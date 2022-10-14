// Codeforces Beta Round #16
// Problem E -- Fish
#include <cstdio>
#include <cstring>

#define N 18

#define BIT(x) (1 << (x))

using namespace std;

int n, f[N];
double a[N][N], p[1 << N];

int main()
{
	scanf("%d", &n);
	for(int i = 0; i != n; ++ i)
		for(int j = 0; j != n; ++ j)
			scanf("%lf", &a[i][j]);
	memset(p, 0, sizeof(p));
	p[BIT(n) - 1] = 1.0;
	for(int i = BIT(n) - 1; i; -- i)
	{
		int s = 0;
		for(int j = 0; j != n; ++ j)
			if(i & BIT(j))
				f[s ++] = j;
		if(s < 2)
			continue;
		double temp = 2.0 * p[i] / (s * (s - 1));
		for(int j = 0; j != s; ++ j)
			for(int k = j + 1; k != s; ++ k)
			{
				p[i ^ BIT(f[k])] += temp * a[f[j]][f[k]];
				p[i ^ BIT(f[j])] += temp * a[f[k]][f[j]];				
			}
	}
	for(int i = 0; i != n; ++ i)
		printf("%f ", p[BIT(i)]);
	printf("\n");
	return 0;
}