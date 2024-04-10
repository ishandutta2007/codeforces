#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#define ll long long
#define lc(x) ((x) << 1)
#define rc(x) ((x) << 1 | 1)
#define maxn 200005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
inline ll readll()
{
	ll x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n, m;
long long a[maxn], x, y;
int main()
{
	scanf("%d", &n);
	long long sum = 0;
	for (int i = 1; i <= n; i++) 
	{
		scanf("%lld", &a[i]);
		sum += a[i];
	}
	sort(a + 1, a + n + 1);
	scanf("%d", &m);
	for (int i = 1; i <= m; i++)
	{
		scanf("%lld%lld", &x, &y);
		if(x > a[n])
		{
			printf("%lld\n", max(0ll, x - a[n] + max(0ll, (y - (sum - a[n])))));
			continue;
		}
		int loc = lower_bound(a + 1, a + n + 1, x) - a;
		long long ans = max(0ll, y - (sum - a[loc]));
		if(loc > 1) ans = min(ans, x - a[loc - 1] + max(0ll, y - (sum - a[loc - 1])));
		ans = max(ans, 0ll);
		printf("%lld\n", ans);
	}
	return 0;
}