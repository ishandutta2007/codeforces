#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	string s,flag = "heidi";
	cin >> s;
	int level = 0;
	for (int i = 0;i < s.size();i++)
	{
		if (s[i] == flag[level])
			level++;
		if (level == 5)
		{
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}