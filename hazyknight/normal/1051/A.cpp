#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector> 

using namespace std;

int T;

string s;

vector<int> dig,upp,low;

int main()
{
	cin >> T;
	while (T--)
	{
		cin >> s;
		dig.clear();
		upp.clear();
		low.clear();
		for (int i = 0;i < s.size();i++)
		{
			if (s[i] >= '0' && s[i] <= '9')
				dig.push_back(i);
			if (s[i] >= 'A' && s[i] <= 'Z')
				upp.push_back(i);
			if (s[i] >= 'a' && s[i] <= 'z')
				low.push_back(i);
		}
		if (!dig.size() && !low.size())
		{
			s[upp.back()] = '1';
			upp.pop_back();
			s[upp.back()] = 'a';
			upp.pop_back();
			cout << s << endl;
			continue;
		}
		if (!dig.size() && !upp.size())
		{
			s[low.back()] = '1';
			low.pop_back();
			s[low.back()] = 'A';
			low.pop_back();
			cout << s << endl;
			continue;
		}
		if (!low.size() && !upp.size())
		{
			s[dig.back()] = 'a';
			dig.pop_back();
			s[dig.back()] = 'A';
			dig.pop_back();
			cout << s << endl;
			continue;
		}
		if (!dig.size())
		{
			if (upp.size() > 1)
				s[upp.back()] = '1',upp.pop_back();
			else if (low.size() > 1)
				s[low.back()] = '1',low.pop_back();
		}
		if (!upp.size())
		{
			if (dig.size() > 1)
				s[dig.back()] = 'A',dig.pop_back();
			else if (low.size() > 1)
				s[low.back()] = 'A',low.pop_back();
		}
		if (!low.size())
		{
			if (upp.size() > 1)
				s[upp.back()] = 'a',upp.pop_back();
			else if (dig.size() > 1)
				s[dig.back()] = 'a',dig.pop_back();
		}
		cout << s << endl;
	}
	return 0;
}