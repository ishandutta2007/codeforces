#include <cstdio>
#include <algorithm>
using namespace std;
#define N 100000 + 5
#define Mod 998244353

int n, k, A[2][N];

int Calc(int *p, int sz)
{
	int res = 1;
	for (int last = -1, i = 0; i <= sz; i ++) 
	{
		if (i < sz && p[i] == -1) continue ;
		if (last == -1)
		{
			for (int j = last + 1; j < i; j ++)
				res = 1LL * res * (k - 1 + (j == last + 1 && i == sz)) % Mod;
		}
		else if (i == sz)
		{
			for (int j = last + 1; j < i; j ++)
				res = 1LL * res * (k - 1) % Mod;
		}
		else
		{
			int a = 0, _a = 1;
			for (int j = last + 1; j < i; j ++)
			{
				int ta = 1LL * (k - 1) * _a % Mod;
				int _ta = (1LL * (k - 2) * _a + a) % Mod;
				a = ta, _a = _ta;
			}
			if (p[last] == p[i])
				res = 1LL * res * a % Mod;
			else res = 1LL * res * _a % Mod;
		}
		last = i;
	}
	return res;
}

int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i ++)
		scanf("%d", &A[i & 1][i >> 1]);
	printf("%d\n", 1LL * Calc(A[0], n + 1 >> 1) * Calc(A[1], n >> 1) % Mod);
	return 0;
}