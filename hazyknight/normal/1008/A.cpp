#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>

using namespace std;

bool judge(char c)
{
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main()
{
	string s;
	cin >> s;
	for (int i = 0;i < s.size();i++)
		if (!judge(s[i]) && s[i] != 'n')
		{
			if (i == s.size())
			{
				cout << "NO" << endl;
				return 0;
			}
			if (!judge(s[i + 1]))
			{
				cout << "NO" << endl;
				return 0;
			}
		}
	cout << "YES" << endl;
	return 0;
}