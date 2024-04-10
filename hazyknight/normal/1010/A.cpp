#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <queue>
#include <iomanip>

using namespace std;

const long double eps = 1e-8;

int n,m,id;

long double a[1005];
long double b[1005];
long double c[2005];

bool ok(long double fuel)
{
	for (int i = 1;i <= id;i++)
	{
		long double need = (fuel + m) / c[i];
		fuel -= need;
		if (fuel < 0)
			return false;
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
		cin >> a[i];
	for (int i = 1;i <= n;i++)
		cin >> b[i];
	for (int i = 1;i <= n;i++)
	{
		c[++id] = a[i];
		c[++id] = b[i % n + 1];
	}
	if (!ok(1000000001))
	{
		cout << -1 << endl;
		return 0;
	}
	long double low = 0,high = 1000000001;
	while (high - low > eps)
	{
		long double mid = (low + high) / 2.0;
		if (ok(mid))
			high = mid;
		else
			low = mid + eps;
	}
	cout << fixed << setprecision(10) << low << endl;
	return 0;
}