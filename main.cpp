/*
Author: Hoang Phuc Luan Truong

This program will have 3 important functions. One will convert a string 
containing a 16-bit binary integer to decimal number. One will convert
a string containing a 32-bit hexadecimal integer to a decimal number.
One will convert a decimal to a string containing the hexadecimal 
representation of the input decimal. The program then will run the test
funcions to guarantee the 3 functions perform the correct task and give
the desired output.
*/


#include <iostream>

using namespace std; 


long convert16BitTodecimal(string);

void testConvert16BitTodecimal();

long convertHexTodecimal(string);

void testconvertHexTodecimal();

string convertdecimalToHex(long);

void testConvertdecimalToHex();



/********************************************************************
*>>>>>>>>>>>>>>>>>>>>>>>>> MAIN FUNCTION <<<<<<<<<<<<<<<<<<<<<<<<<<<*
********************************************************************/
int main() 
{

	cout << "========================================" << endl;
	cout << "TESTING convert16BitTodecimal()..." << endl << endl << endl;
	testConvert16BitTodecimal();


	cout << endl << "========================================" << endl;
	cout << "TESTING convertHexTodecimal()..." << endl << endl << endl;
	testconvertHexTodecimal();


	cout << endl << "========================================" << endl;
	cout << "TESTING convertdecimalToHex()..." << endl << endl << endl;
	testConvertdecimalToHex();

	return 0;
}




/******************************************************************
* The function that converts a 16 bit binary to decimal number
* 
* receive:	a string that represents the binary
* return:	the decimal value of the input binary
******************************************************************/
long convert16BitTodecimal(string bit) 
{
	long result = 0;

	if (bit.length() > 0 && bit.length() <= 16) 
	{
		for (int i = 0; i < bit.length(); i++) 
		{
			if (bit.at(i) == '1') 
			{
				result += pow(2, bit.length() - i - 1);
			}
		}
	}
	else 
	{
		cout << "Invalid input length" << endl;
		result = NULL;
	}

	return result;
}




/******************************************************************
* the function that tests convert16BitTodecimal(). 
* 
* receive:	none
* return:	none
******************************************************************/
void testConvert16BitTodecimal() 
{
	bool result = true;

	const string BIT[] = {"0000000000000000", "1111111111111111", 
						"0000000001000011", "1000111000000010", ""};
	const int DECIMAL[] = {0, 65535, 67, 36354, NULL};
	int received;

	
	for (int i = 0; i < 5; i++) 
	{

		cout << "Converting " << BIT[i] << " to decimal, "
			<< "the result should be " << DECIMAL[i] << endl;

		received = convert16BitTodecimal(BIT[i]);

		if (received == DECIMAL[i]) 
		{
			cout << "*** PASS" << endl << endl;
		}
		else 
		{
			cout << "*** FAIL, received " << received << " instead" 
				<< endl << endl;
			result = false;
		}
	}

	if (result)
	{
		cout << "	++++++++++++++++++++++++++++++++++++" << endl;
		cout << "	*** convert16BitTodecimal PASSES ***"
			<< endl << endl << endl;
	}
	else 
	{
		cout << "	xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;
		cout << "	*** convert16BitTodecimal FAILS ***" 
			<< endl << endl << endl;
	}
}





/******************************************************************
* the function that converts a 32-bit hexadecimal to decimal number
*
* receive:	a string that represents the hexadecimal
* return:	the decimal value of the input hexadecimal
******************************************************************/
long convertHexTodecimal(string hex) 
{
	long result = 0;
	int BASE = 16;

	for (int i = 0; i < hex.length(); i++)
	{
		char value = hex.at(i);
		int numberValue = 0;

		if (isdigit(value)) 
		{
			numberValue = value - '0';
		}
		else if (isalpha(value)) 
		{
			numberValue = value - '0';
			numberValue -= 7;
		}
		else 
		{
			cout << "Invalid input!!!" << endl << endl;
			result = NULL;
			break;
		}
		
		result += numberValue * pow(BASE, hex.length() - i - 1);
	}

	return result;
}





/******************************************************************
* the function that tests convertHexTodecimal().
*
* receive:	none
* return:	none
******************************************************************/
void testconvertHexTodecimal() 
{
	bool result = true;

	const string HEX[] = {"0126F9D4", "6ACDFA95", "A1FC2", "11111111"};
	const long DECIMAL[] = { 19331540, 1791883925, 663490, 286331153 };
	int received;


	for (int i = 0; i < 4; i++)
	{

		cout << "Converting " << HEX[i] << " to decimal, "
			<< "the result should be " << DECIMAL[i] << endl;

		received = convertHexTodecimal(HEX[i]);

		if (received == DECIMAL[i]) 
		{
			cout << "*** PASS" << endl << endl;
		}
		else
		{
			cout << "*** FAIL, received " << received << " instead" << endl << endl;
			result = false;
		}
	}

	if (result) 
	{
		cout << "	++++++++++++++++++++++++++++++++++" << endl;
		cout << "	*** convertHexTodecimal PASSES ***" 
			<< endl << endl << endl;
	}
	else
	{
		cout << "	xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;
		cout << "	*** convertHexTodecimal FAILS ***" 
			<< endl << endl << endl;
	}

}






/******************************************************************
* the function that converts decimal number to a hexadicimal 
*
* receive:	a decimal number 
* return:	the string representing the hexadecimal value of the 
*			input decimal
******************************************************************/
string convertdecimalToHex(long decimal)
{

	string result = "";
	int remainder;
	const int BASE = 16;

	do
	{
		remainder = decimal % BASE;

		if (remainder < 10 && remainder > 0) 
		{
			char temp = remainder + '0';
			result = temp + result;
		}
		else if (remainder >= 10) 
		{
			char hex = (char)remainder + 55;
			result = hex + result;
		}

		decimal /= BASE;

	} while (remainder != 0);

	return result;
}





/******************************************************************
* the function that tests convertdecimalToHex().
*
* receive:	none
* return:	none
******************************************************************/
void testConvertdecimalToHex() 
{
	bool result = true;

	const string HEX[] = { "126F9D4", "6ACDFA95" };
	const long DECIMAL[] = { 19331540, 1791883925 };
	string received;


	for (int i = 0; i < 2; i++) 
	{

		cout << "Converting " << DECIMAL[i] << " to hexadecimal, "
			<< "the result should be " << HEX[i] << endl;

		received = convertdecimalToHex(DECIMAL[i]);

		if (received == HEX[i]) 
		{
			cout << "*** PASS" << endl << endl;
		}
		else
		{
			cout << "*** FAIL, received " << received << " instead" << endl << endl;
			result = false;
		}
	}

	if (result)
	{
		cout << "	++++++++++++++++++++++++++++++++++" << endl;
		cout << "	*** convertHexTodecimal PASSES ***"
			<< endl << endl << endl;
	}
	else {
		cout << "	xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;
		cout << "	*** convertHexTodecimal FAILS ***"
			<< endl << endl << endl;
	}
}
