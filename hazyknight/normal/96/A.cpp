#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>

using namespace std;

int main()
{
	string s;
	cin >> s;
	for (int i = 6;i < s.size();i++)
	{
		bool ok = true;
		for (int j = i - 6;j <= i;j++)
			if (s[i] != s[j])
			{
				ok = false;
				break;
			}
		if (ok)
		{
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}