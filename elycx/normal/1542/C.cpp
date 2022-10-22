#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int t;
long long n;
long long gcd(long long x, long long y)
{
	if(x < y) swap(x, y);
	return y == 0 ? x : gcd(y, x % y);
}
int main()
{
	long long mo = 1e9 + 7;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%lld", &n);
		long long x = 1;
		long long ans = 0;
		for (int i = 1; i <= 100; i++)
		{
			ans = (ans + n / x) % mo;
			x = x * i / gcd(x, i);
			if(x > n) break;
		}
		printf("%lld\n", ans);
	}
	return 0;
}