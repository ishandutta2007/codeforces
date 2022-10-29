#include <bits/stdc++.h>

#define N 500005

#define pb push_back
#define mk make_pair
#define fi first
#define se second

#define Mo 1000000007

int power(int x, int y)
{
	int s = 1;
	for (;y;y>>=1) 
	{
		if (y&1) s=1ll*s*x%Mo;
		x=1ll*x*x%Mo;
	}
	return s;
}

using namespace std;

int counter[N], n, ans;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
	{
		int x, cnt = 0; scanf("%d", &x);
		for (;x%2 == 0;) x /= 2, cnt++;
		counter[cnt]++;
	}
	ans = (power(2, n) - power(2, n - counter[0]) + Mo) % Mo; n -= counter[0];
	for (int i = 1; i <= 30; ++i)
		if (counter[i] > 0)
		{
			n -= counter[i];
			(ans += 1ll * power(2, n) * (power(2, counter[i] - 1) - 1) % Mo) %= Mo;
		}
	printf("%d\n", ans); 
}