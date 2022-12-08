#include <cstdio>

using namespace std;

using ll = long long;
#define tl(X) static_cast<ll>(X)

const int MN = 1e3 + 100;

int N, M, Q;
bool a[MN<<1][MN<<1]; char I;
int p[MN<<1][MN<<1];

int l2(int x)
{
	int r = -1;
	for(;x;x>>=1) r++;
	return r;
}
ll calc(int x, int y)
{
	bool inv = (__builtin_popcount(x/M)^__builtin_popcount(y/N))&1;
	ll f = tl(x/M*M)*y>>1; x %= M;
	f += tl(y/N*N)*x>>1; y %= N;
	return f + (inv?x*y-p[x][y]:p[x][y]);
}
int main(void)
{
	scanf("%d%d%d", &N, &M, &Q);
	for(int i = 0;i < N;i++)
		for(int j = 0;j < M;j++)
			scanf(" %c", &I), a[j][i] = a[j+M][i+N] = I=='1', a[j+M][i] = a[j][i+N] = I!='1';
	N<<=1, M<<=1;
	for(int i = 0;i < M;i++)
		for(int j = 0;j < N;j++)
			p[i+1][j+1] = p[i+1][j]+p[i][j+1]-p[i][j]+a[i][j];
	for(int i = 0;i < Q;i++)
	{
		int a, b, c, d;
		scanf("%d%d%d%d", &a, &b, &c, &d);
		a--, b--;
		printf("%lld\n", calc(d,c)+calc(b,a)-calc(b,c)-calc(d,a));
	}
	return 0;
}