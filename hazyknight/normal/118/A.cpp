#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>

using namespace std;

string s;

int main()
{
	cin >> s;
	for (int i = 0;i < s.size();i++)
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
			s[i] = s[i] - 'A' + 'a';
		if (s[i] == 'a' || s[i] == 'y' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
			continue;
		cout << '.' << s[i];
	}
	cout << endl;
	return 0;
}