#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
#define Mod 1000000007

LL n, k;

inline LL Phi(LL x)
{
	LL _x = x, res = 1;
	for (LL i = 2; _x > 1 && i * i <= x; i ++)
		if (_x % i == 0)
		{
			res *= i - 1, _x /= i;
			for (; _x % i == 0; _x /= i, res *= i) ;
		}
	if (_x > 1) res *= _x - 1;
	return res;
}

int main()
{
	scanf("%I64d%I64d", &n, &k);
	for (k = k + 1 >> 1; n > 1 && k; k --)
		n = Phi(n);
	printf("%I64d\n", n % Mod);
	return 0;
}