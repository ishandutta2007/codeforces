#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>

using namespace std;

int n;
string s;

int main()
{
	cin >> n >> s;
	for (int i = s.size() / 2;i >= 1;i--)
	{
		if (s.substr(0,i) == s.substr(i,i))
		{
			cout << n - i + 1 << endl;
			return 0;
		}
	}
	cout << n << endl;
	return 0;
}