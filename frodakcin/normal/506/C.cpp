#include <iostream>
#include <cstdio>

using namespace std;

const int MN = 1e5 + 100;
const int MM = 5e3 + 100;
const int MK = 10 + 5;
const int MP = 1e9 + 100;
using ll = long long;
#define tl(X) static_cast<ll>(X)
#define ti(X) static_cast<int>(X)

int N, M, K, P;
ll h[MN], a[MN];
ll c, L, x;
int p[MN];

ll k, d, t;
int y;
bool solve(ll v)
{
	c = 0LL;
	for(int i = 0;i < N;i++)
		if(v < h[i]+M*tl(a[i])&&(c += (h[i]+M*tl(a[i])-v+P-1)/P) > M*K)
			return 0;
	for(int i = 0;i <= M;i++) p[i] = 0;
	for(int i = 0;i < N;i++)
	{
		L = h[i] + M*tl(a[i]) - v;
		x = 0LL;
		if(L <= 0) continue;
		t = (h[i]+M*tl(a[i])-v+P-1)/P;
		L = t*P-L;
		for(int j = 0;j < t;j++)
		{
			//h[i]+k*tl(a[i])-x >= P-L;
			//min k that satisfies above equ
			k = (P-L+x-h[i]+a[i]-1)/a[i];
			if(k < 0) k = 0;
			d = min(h[i]+tl(a[i])*k-x, tl(P));
			x += d, L -= P-d;
			p[k]++;
			//printf("%lld: %d %lld\n", v, i, k);
		}
	}
	x = 0LL, y = 0;
	for(int i = M;i >= 0;i--, y += K)
		if((x += p[i]) > y)
			return 0;
	return 1;
}
ll l, m, r;
int main(void)
{
	scanf("%d%d%d%d", &N, &M, &K, &P);
	l = 0LL;
	for(int i = 0;i < N;i++)
		scanf("%lld%lld", h + i, a + i), l = max(l, tl(a[i]));
	l--, r = 1e16;
	for(;r-l>1;)
	{
		m = l + ((r-l)>>1LL);
		if(solve(m)) r = m;
		else l = m;
	}
	printf("%lld\n", r);
	return 0;
}