#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#define ll long long
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9')
	{
		w |= ch == '-';
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9')
	{
		x = (x << 3) + (x << 1) + ch - '0';
		ch = getchar();
	}
	return w ? -x : x;
}
long long gcd(long long x, long long y)
{
	if(x < y) swap(x, y);
	return y == 0 ? x : gcd(y, x % y);
}
int main()
{
	long long n = read(), m = read(), k = read();
	long long tmp = (ll)2 * n * m;
	if(tmp % k != 0)
	{
		printf("NO\n");
		return 0;
	}
	tmp /= k;
	long long x = gcd(k, n * 2);
	if(x == 1) x *= 2;
	printf("YES\n");
	printf("0 0\n0 %lld\n%lld 0", tmp * x / 2 / n, n * 2 / x);
	return 0;
}