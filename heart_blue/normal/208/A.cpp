#include <cstdlib>   
#include <cctype>   
#include <cstring>   
#include <cstdio>   
#include <cmath>   
#include <algorithm>   
#include <vector>   
#include <string>   
#include <iostream>   
#include <sstream>   
#include <map>   
#include <set>   
#include <queue>   
#include <stack>   
#include <fstream>   
#include <numeric>   
#include <iomanip>   
#include <bitset>   
#include <list>   
#include <stdexcept>   
#include <functional>   
#include <utility>   
#include <ctime>
//#include "BigNum.h"
using namespace std;

int main()
{
	string str;
	cin >> str;
	for(int i = 0; i < str.length(); i++)
	{
		if(str[i] == 'W')
		{
			if(i + 2 < str.length())
			{
				if(str[i+1] == 'U' && str[i+2] == 'B')
				{
					str[i] = str[i+1] = str[i+2] = ' ';
				}
			}
		}
	}
	int k = 0;
	stringstream sin(str);
	string s;
	while(sin>> s)
	{
		if(k) cout << ' ';
		cout << s;
		k++;
	}
	cout << endl;
	return 0;
}