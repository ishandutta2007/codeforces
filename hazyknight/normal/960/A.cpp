#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>

using namespace std;

string s;

int ca,cb,cc;

int main()
{
	cin >> s;
	for (int i = 0;i < s.size() - 1;i++)
		if (s[i] > s[i + 1])
		{
			cout << "NO" << endl;
			return 0;
		}
	for (int i = 0;i < s.size();i++)
		if (s[i] == 'a')
			ca++;
		else if (s[i] == 'b')
			cb++;
		else
			cc++;
	if (ca && cb && (cc == ca || cc == cb))
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}