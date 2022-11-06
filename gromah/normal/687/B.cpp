#include <cstdio>
#define N 1000000 + 5 

int n, k, A[N];
bool ok = 1;

int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i ++)
		scanf("%d", A + i);
	for (int x = k, i = 2, m; ok && x > 1; i ++)
	{
		if (x % i) continue ;
		for (m = 1; x % i == 0; x /= i, m *= i) ;
		ok = 0;
		for (int j = 1; !ok && j <= n; j ++)
			ok = (A[j] % m == 0);
	}
	puts(ok ? "Yes" : "No");
	return 0;
}