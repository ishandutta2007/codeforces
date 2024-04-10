#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 150000 + 5

int n, ans = -1, A[N], B[N];
LL d;

int Find(LL x)
{
	for (int i = 2; 1LL * i * i <= x; i ++)
		if (x % i == 0) return i;
	return x;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
	{
		scanf("%d%d", A + i, B + i);
		d = __gcd(d, 1LL * A[i] * B[i] / __gcd(A[i], B[i]));
	}
	if (__gcd(d, LL(A[1])) > 1) ans = Find(__gcd(d, LL(A[1])));
	else if (__gcd(d, LL(B[1])) > 1) ans = Find(__gcd(d, LL(B[1])));
	printf("%d\n", ans);
	return 0;
}