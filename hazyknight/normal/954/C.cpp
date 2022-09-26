#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>

using namespace std;

long long n,ansy = -1;
long long a[250005];

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1;i <= n;i++)
		cin >> a[i];
	for (int i = 2;i <= n;i++)
	{
		long long f = a[i],t = a[i - 1];
		if (a[i] == a[i - 1])
		{
			cout << "NO" << endl;
			return 0;
		}
		if (f < t)
			swap(f,t);
		if (f - t != 1)
		{
			if (ansy != -1 && ansy != f - t)
			{
				cout << "NO" << endl;
				return 0;
			}
			ansy = f - t;
		}
	}
	if (ansy == -1)
	{
	cout << "YES" << endl;
		long long MAX = 0;
		for (int i = 1;i <= n;i++)
			MAX = max(MAX,a[i]);
		cout << 1 << ' ' << MAX << endl;
		return 0;
	}
	for (int i = 2;i <= n;i++)
	{
		if (abs(a[i - 1] - a[i]) == 1 && (a[i - 1] - 1) / ansy + 1 != (a[i] - 1) / ansy + 1)
		{
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	long long MAX = 0;
	for (int i = 1;i <= n;i++)
		MAX = max(MAX,(a[i] - 1) / ansy + 1);
	cout << MAX << ' ' << ansy << endl;
	return 0;
}