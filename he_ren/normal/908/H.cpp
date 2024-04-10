#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 47 + 5;
const int ALL = (1<<23) + 5;
const int mod = 1e9 + 7;

inline void add_mod(int &a,int b){ a+=b; if(a>=mod) a-=mod;}

int lb[ALL], num1[ALL];

#define bbit(i) (1<<(i))
#define bdig(x,i) (((x)>>(i))&1)
#define lowbit(x) ((x)&-(x))

namespace FMT
{
	inline void fmt(int f[],int n)
	{
		int all = (1<<n) - 1;
		for(int i=0; i<n; ++i)
			for(int mask=0; mask<=all; ++mask)
				if(bdig(mask, i)) add_mod(f[mask], f[mask ^ bbit(i)]);
	}
	inline void ifmt(int f[],int n)
	{
		int all = (1<<n) - 1;
		for(int i=0; i<n; ++i)
			for(int mask=0; mask<=all; ++mask)
				if(bdig(mask, i)) add_mod(f[mask], mod - f[mask ^ bbit(i)]);
	}
	inline int get_ifmt(int f[],int x)
	{
		int res = 0;
		for(int i=x;; i=(i-1)&x)
		{
			if(num1[x^i]&1) add_mod(res, mod - f[i]);
			else add_mod(res, f[i]);
			if(!i) break;
		}
		return res;
	}
} using FMT::fmt; using FMT::get_ifmt;

char s[MAXN][MAXN];

int fa[MAXN], siz[MAXN];
inline void init(int n){ for(int i=1; i<=n; ++i) fa[i] = i;}
int find(int u){ return fa[u] == u? u: fa[u] = find(fa[u]);}
inline void connect(int u,int v){ fa[find(u)] = find(v);}

int id[MAXN], pcnt = 0;
int neib[MAXN];
int f[ALL], g[ALL];

int main(void)
{
	lb[0] = -1;
	for(int i=2; i<ALL; ++i) lb[i] = lb[i>>1] + 1;
	for(int i=1; i<ALL; ++i) num1[i] = num1[i^lowbit(i)] + 1;
	
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%s",s[i]+1);
	
	init(n);
	for(int i=1; i<=n; ++i)
		for(int j=1; j<i; ++j)
			if(s[i][j] == 'A') connect(i,j);
	for(int i=1; i<=n; ++i)
		for(int j=1; j<i; ++j)
			if(s[i][j] == 'X' && find(i) == find(j))
				return printf("-1"), 0;
	
	for(int i=1; i<=n; ++i) ++siz[find(i)];
	for(int i=1; i<=n; ++i)
		if(find(i) == i && siz[i] > 1) id[i] = ++pcnt;
	
	if(!pcnt) return printf("%d",n-1), 0;
	
	int all = (1<<pcnt) - 1;
	
	for(int i=1; i<=n; ++i)
		for(int j=1; j<i; ++j) if(s[i][j] == 'X' && find(i) != find(j))
		{
			int u = id[find(i)], v = id[find(j)];
			if(!u || !v) continue;
			neib[u] |= bbit(v-1);
			neib[v] |= bbit(u-1);
		}
	
	for(int i=1; i<=pcnt; ++i) neib[i] ^= all;
	
	f[0] = 1;
	for(int mask=1; mask<=all; ++mask)
	{
		int lowb = lowbit(mask), k = lb[lowb]+1, rem = mask ^ lowb;
		if((rem & neib[k]) == rem && f[rem]) f[mask] = 1;
	}
	
	fmt(f,pcnt);
	for(int i=0; i<=all; ++i) g[i] = f[i];
	for(int i=1; i<=pcnt; ++i)
	{
		if(get_ifmt(g,all)) return printf("%d",i-1 + n), 0;
		for(int j=0; j<=all; ++j) g[j] = (ll)g[j] * f[j] %mod;
	}
	return 0;
}