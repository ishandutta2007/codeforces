#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <ctime>
#include <windows.h>

using namespace std;

int n,m;
int sum,a,l,r;

int main()
{
	cin >> n;
	for (int i = 1;i <= n;i++)
		cin >> a,sum += a;
	cin >> m;
	for (int i = 1;i <= m;i++)
	{
		cin >> l >> r;
		if (r >= sum)
		{
			cout << max(l,sum) << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}