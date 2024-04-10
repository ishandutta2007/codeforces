#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;

int mod;

inline ll pw(ll a,ll b)
{
	ll res = 1;
	while(b)
	{
		if(b&1) res=res*a%mod;
		a=a*a%mod; b>>=1;
	}
	return res;
}

int fa[MAXN];
inline void init(int n){ for(int i=1; i<=n; ++i) fa[i] = i;}
int find(int u){ return fa[u] == u? u: fa[u] = find(fa[u]);}
inline void connect(int u,int v){ fa[find(u)] = find(v);}

int siz[MAXN];

int main(void)
{
	int n,m;
	scanf("%d%d%d",&n,&m,&mod);
	if(mod == 1) return printf("0"), 0;
	init(n);
	for(int i=1; i<=m; ++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		connect(u,v);
	}
	
	for(int i=1; i<=n; ++i)
		++siz[find(i)];
	
	int cnt = 0;
	for(int i=1; i<=n; ++i) if(find(i) == i)
		++cnt;
	
	if(cnt == 1) return printf("1"), 0;
	ll ans = pw(n, cnt-2);
	for(int i=1; i<=n; ++i) if(find(i) == i)
		ans = (ans * siz[i]) %mod;
	printf("%lld",ans);
	return 0;
}