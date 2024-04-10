#include <cstdio>
#include <algorithm>

using ll = long long;
int R, G, B, T;
const int MN = 1e5 + 100;
const int MV = 1e9 + 100;
const ll INF = 6e18;
ll r[MN], g[MN], b[MN];
int rc, gc, bc;
ll ans;
ll get(ll a, ll b, ll c) {return (a-b)*(a-b)+(a-c)*(a-c)+(b-c)*(b-c);}
void solve(ll * x, ll * y, ll * z, int X, int Y, int Z)
{
	for(int i = 0, j = 0, k = 0;i < X;++i)
	{
		for(;j < Y && y[j] < x[i];++j);
		if(j == Y) break;
		for(;k < Z && z[k]*2 < x[i]+y[j];++k);
		if(k) ans = std::min(ans, get(x[i], y[j], z[k-1]));
		if(k < Z) ans = std::min(ans, get(x[i], y[j], z[k]));
	}
}
int main(void)
{
	scanf("%d", &T);
	for(int tc = 0;tc < T;++tc)
	{
		scanf("%d%d%d", &R, &G, &B);
		for(int i = 0;i < R;++i) scanf("%d", r+i);
		for(int i = 0;i < G;++i) scanf("%d", g+i);
		for(int i = 0;i < B;++i) scanf("%d", b+i);
		std::sort(r, r+R);
		std::sort(g, g+G);
		std::sort(b, b+B);
		r[R] = g[G] = b[B] = MV;
		
		rc = 0, gc = 0, bc = 0;
		ans = INF;
		solve(r, g, b, R, G, B);
		solve(r, b, g, R, B, G);
		solve(b, r, g, B, R, G);
		solve(b, g, r, B, G, R);
		solve(g, r, b, G, R, B);
		solve(g, b, r, G, B, R);
		printf("%lld\n", ans);
	}
	return 0;
}