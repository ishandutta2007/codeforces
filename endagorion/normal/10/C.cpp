#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <string>

using namespace std;

int d[1000010];
long long q[10];

int s(int x)
{
	int res = 0;
	while (x > 0)
	{
		res += x%10;
		x/=10;
	}
	return res;
}

int main()
{
//	freopen("", "rt", stdin);
//	freopen("", "wt", stdout);
	int n;
	cin >> n;
	long long ans = 0;
	for (int i = 1; i < 10; ++i)
	{
		d[i] = i;
	}
	for (int i = 10; i <= 1000000; ++i)
	{
		d[i] = d[s(i)];
	}
	for (int i = 1; i <= n; ++i)
		q[d[i]]++;
	for (int i = 1; i < 10; ++i)
	{
		for (int j = 1; j < 10; ++j)
			ans += q[i] * q[j] * q[d[i*j]];
	}
	for (int i = 1; i <= n; ++i)
		{
			ans -= n/i;
		}
	cout << ans << '\n';
	return 0;
}