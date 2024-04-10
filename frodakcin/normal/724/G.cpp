#include <cstdio>
#include <vector>
#include <algorithm>

using ll = long long;
#define tl(X) static_cast<ll>(X)

const int MN = 1e5 + 100;
const int MM = 2e5 + 100;
const int MOD = 1e9+7;
const int MB = 60;

int N, M;
ll p2[MB+1<<1];
ll c2(int v) {return tl(v)*(v-1)/2%MOD;}
ll F;
struct E1
{
public:
	int u, v;
	ll w;
};
std::vector<E1> e;
struct E2
{
public:
	int n;
	ll w;
};
std::vector<E2> a[MN];

int dsp[MN], dsr[MN];
int dsf(int n) {return dsp[n]?dsp[n]=dsf(dsp[n]):n;}
bool dsm(int a, int b)
{
	a=dsf(a), b=dsf(b);
	if(a==b) return 0;
	if(dsr[b]>dsr[a]) std::swap(a,b);
	return dsp[b]=a, dsr[a]+=dsr[a]==dsr[b], dsr[b]=-1, 1;
}

bool v[MN];
ll d[MN];
int t[MN];
std::vector<int> c[MN];
int C;
void dfs(int n, int p = 0)
{
	t[n] = C, v[n] = 1;
	c[C].push_back(n);
	for(E2 x : a[n])
		if(p!=x.n)
			d[x.n]=d[n]^x.w, dfs(x.n,n);
}

std::vector<ll> q[MN]; 

int main(void)
{
	p2[0] = 1;
	for(int i = 0;i <= MB*2;++i)
		p2[i+1] = p2[i]*2%MOD;
	scanf("%d%d", &N, &M);
	for(int i = 0;i < M;++i)
	{
		int u, v;
		ll w;
		scanf("%d%d%lld", &u, &v, &w);
		if(dsm(u, v))
			a[u].push_back({v,w}), a[v].push_back({u,w});
		else
			e.push_back({u,v,w});
	}
	for(int i = 1;i <= N;++i)
		if(!v[i])
			dfs(i), ++C;
	for(E1 i : e)
		q[t[i.u]].push_back(d[i.u]^d[i.v]^i.w);
	for(int i = 0, j, n, b, x;i < C;++i)
	{
		if(q[i].empty()) continue;
		std::vector<ll> f(q[i]);
		for(b = MB, x = -1;b >= 0;--b, x=-1)
		{
			for(j = 0;j < q[i].size();++j)
				if(f[j] < 2LL<<b && f[j]&1LL<<b)
				{
					x = j;
					break;
				}
			if(~x)
				for(j = 0;j < q[i].size();++j)
					if(j!=x && f[j]&1LL<<b)
						f[j]^=f[x];
		}
		for(j = 0, n = 0;j < q[i].size();++j)
			if(f[j])
				q[i][n++] = q[i][j];
		q[i].resize(n);
		f.clear();
	}
	for(int i = 0, h[MB+1], j, k, s;i < C;++i)
	{
		for(j = 0;j <= MB;++j) h[j] = 0;
		s = c[i].size();
		for(int x : c[i])
			for(j = 0;j <= MB;++j)
				h[j] += !!(d[x]&1LL<<j);
		ll g = 0;
		for(ll x : q[i])
			g |= x;
		k = q[i].size();
		for(j = 0;j <= MB;++j)
			if(g&1LL<<j)
				F += p2[j+k-1]*c2(s)%MOD;
			else
				F += p2[j+k]*h[j]%MOD*(s-h[j])%MOD;
	}
	printf("%d\n", static_cast<int>(F%MOD));
	return 0;
}