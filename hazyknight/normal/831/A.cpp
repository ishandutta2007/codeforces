#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>

using namespace std;

int n;
int a[105];

int main()
{
	cin >> n;
	int lev = 0;
	for (int i = 1;i <= n;i++)
		cin >> a[i];
	for (int i = 2;i <= n;i++)
	{
		int now = 0;
		if (a[i] > a[i - 1])
			now = 0;
		else if (a[i] == a[i - 1])
			now = 1;
		else
			now = 2;
		if (now < lev)
		{
			cout << "No" << endl;
			return 0;
		}
		lev = now;
	}
	cout << "Yes" << endl;
	return 0;
}