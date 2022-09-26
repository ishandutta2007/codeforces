#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>

using namespace std;

int main()
{
	int n,x = 0;
	string s;
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> s;
		if (s[1] == '+')
			x++;
		else
			x--;
	}
	cout << x << endl;
	return 0;
}