#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <fstream>

using namespace std;

int n,p;

string s;

int main()
{
	cin >> n >> p >> s;
	for (int i = 0;i < s.size() - p;i++)
	{
		if (s[i] != '.' || s[i + p] != '.')
		{
			if (s[i] == '.')
			{
				if (s[i + p] == '1')
					s[i] = '0';
				else
					s[i] = '1';
			}
			else if (s[i + p] == '.')
			{
				if (s[i] == '1')
					s[i + p] = '0';
				else
					s[i + p] = '1';
			}
		}
	}
	for (int i = s.size() - 1;i >= p;i--)
	{
		if (s[i] != '.' || s[i - p] != '.')
		{
			if (s[i] == '.')
			{
				if (s[i - p] == '1')
					s[i] = '0';
				else
					s[i] = '1';
			}
			else if (s[i - p] == '.')
			{
				if (s[i] == '1')
					s[i - p] = '0';
				else
					s[i - p] = '1';
			}
		}
		else
		{
			s[i] = '1';
			s[i - p] = '0';
		}
	}
	for (int i = 0;i < s.size() - p;i++)
		if (s[i] != s[i + p])
		{
			for (int j = 0;j < s.size();j++)
				if (s[j] == '.')
					cout << 1;
				else
					cout << s[j];
			cout << endl;
			return 0;
		}
	cout << "No" << endl;
	return 0;
}