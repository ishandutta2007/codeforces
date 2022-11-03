#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <list>
#include <sstream>

using namespace std;


int test(string str)
{
	int temp = 0;
	for(int i = 0; i < str.length();i++)
	{
		temp += str[i] - '0';
	}
	return temp;
}
int sub(int n)
{
	int count = 0;
	while(n != 0)
	{
		count += n%10;
		n = n/10;
	}
	return count;
}


int main()
{
	string str;
	cin >> str;
	int count = 0;
	int ok;
	if(str.length() == 1) count = 0;
	else
	{
		ok = test(str);
		count ++;
		while(ok >= 10)
		{
			ok = sub(ok);
			count++;
		}
	}
	cout << count << endl;
	return 0;
}