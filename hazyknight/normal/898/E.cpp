#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>

using namespace std;

long long n,ans;

struct Node
{
	long long a,b;
	bool operator < (const Node & p)const
	{
		return a - b < p.a - p.b;
	}
}a[200005];

long long bs(long long tar)
{
	long long low = 0,high = (1 << 16);
	while (low < high)
	{
		long long mid = (low + high + 1) >> 1;
		if (mid * mid <= tar)
			low = mid;
		else
			high = mid - 1;
	}
	return low;
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		long long k;
		cin >> k;
		long long ret = bs(k);
		a[i].a = min(k - ret * ret,(ret + 1) * (ret + 1) - k);
		if (k == 0)
			a[i].b = 2;
		else if (k == ret * ret)
			a[i].b = 1;
		else
			a[i].b = 0;
	}
	sort(a + 1,a + n + 1);
	for (int i = 1;i <= (n >> 1);i++)
		ans += a[i].a;
	for (int i = (n >> 1) + 1;i <= n;i++)
		ans += a[i].b;
	cout << ans << endl;
	return 0;
}