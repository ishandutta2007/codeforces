#include <iostream>
#include <list>
#include <string>
#include <cmath>
#include <vector>
#include <fstream>
using namespace std;

vector<int> ivec(200,0);

void init()
{
	ivec[int('6')] = 6;
	ivec[int('7')] = 7;
	ivec[int('8')] = 8;
	ivec[int('9')] = 9;
	ivec[int('T')] = 10;
	ivec[int('J')] = 11;
	ivec[int('Q')] = 12;
	ivec[int('K')] = 13;
	ivec[int('A')] = 14;
}

int main()
{
	init();
	char c;
	string str1, str2;
	cin >> c;
	cin >> str1 >> str2;
	bool flag = false;
	if(str1[1] == c && str2[1] != c)
	{
		flag = true;
	}
	else if(str1[1] == str2[1])
	{
		flag = ivec[int(str1[0])] > ivec[int(str2[0])];
	}
	cout << (flag ? "YES" : "NO") << endl;
	return 0;
}