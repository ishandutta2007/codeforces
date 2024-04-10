#include <iostream>
#include <list>
#include <string>
#include <cmath>
#include <vector>
#include <fstream>
using namespace std;


int main()
{
	string str;
	cin >> str;
	while(1)
	{
		str[4] ++;
		if(str[4] > '9')
		{
			str[4] -= 10;
			str[3] += 1;
			if(str[3] >= '6')
			{
				str[1] += 1;
				str[3] -= '6';
				if(str[1] > '9')
				{
					str[1] -= 10;
					str[0] ++;
				}
				if(str[0] == '2' && str[1] == '4')
				{
						str[0] = '0';
						str[1] = '0';
				}
			}
		}
		if(str[0] == str[4] && str[1] == str[3])
		{
			cout << str << endl;
			break;
		}
	}

	return 0;
}