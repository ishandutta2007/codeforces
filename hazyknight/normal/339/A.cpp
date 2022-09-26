#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cctype>

using namespace std;

int n;
int c[105];

string s;

int main()
{
	cin >> s;
	for (int i = 0;i < s.size();i += 2)
		c[++n] = s[i] - '0';
	sort(c + 1,c + n + 1);
	cout << c[1];
	for (int i = 2;i <= n;i++)
		cout << '+' << c[i];
	cout << endl;
	return 0;
}