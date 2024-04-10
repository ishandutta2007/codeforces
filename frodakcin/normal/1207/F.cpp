#include <cstdio>

using ll = long long;
#define tl(X) static_cast<ll>(X)
const int N = 5e5;
const int S = 720;
const int L = 720;
static_assert(S*L>N, "bounds");

int Q;

int a[10+N];
ll f[S][S];
ll s;

int main(void)
{
	scanf("%d", &Q);
	for(int i = 0, t, x, y;i < Q;i++)
	{
		scanf("%d%d%d", &t, &x, &y);
		if(t==1)
		{
			a[x]+=y;
			for(int j = 1;j < S;j++)
				f[j][x%j]+=y;
		}
		else
		{
			if(x < S)
				printf("%lld\n", f[x][y]);
			else
			{
				s = 0LL;
				for(int j = !y;x*j+y <= N;j++)
					s += a[x*j+y];
				printf("%lld\n", s);
			}
		}
	}
	return 0;
}