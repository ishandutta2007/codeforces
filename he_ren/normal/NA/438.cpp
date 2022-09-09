#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 5e2 + 5;
const int MAXM = 1e4 + 5;

int fa[MAXN], ccnt;
inline void init(int _n){ ccnt = _n; for(int i=1; i<=_n; ++i) fa[i] = i;}
int find(int u){ return fa[u] == u? u: fa[u] = find(fa[u]);}
inline bool connect(int u,int v)
{
	u = find(u); v = find(v);
	if(u == v) return 0;
	--ccnt; fa[u] = v;
	return 1;
}
inline bool connect(pii p){ return connect(p.first, p.second);}

pii es[MAXM];

int main(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=m; ++i) scanf("%d%d",&es[i].first,&es[i].second);
	
	static pii pre[MAXN], suf[MAXN];
	static int idpre[MAXM], idsuf[MAXM];
	int precnt = 0, sufcnt = 0;
	
	init(n);
	for(int i=1; i<=m; ++i)
	{
		if(connect(es[i])) pre[++precnt] = es[i];
		idpre[i] = precnt;
	}
	init(n);
	for(int i=m; i>=1; --i)
	{
		if(connect(es[i])) suf[++sufcnt] = es[i];
		idsuf[i] = sufcnt;
	}
	
	static int f[MAXN][MAXN];
	for(int i=0; i<=precnt; ++i)
	{
		init(n);
		for(int j=1; j<=i; ++j) connect(pre[j]);
		for(int j=0; j<=sufcnt; ++j)
		{
			if(j) connect(suf[j]);
			f[i][j] = ccnt;
		}
	}
	
	int Q;
	scanf("%d",&Q);
	while(Q--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		printf("%d\n",f[idpre[l-1]][idsuf[r+1]]);
	}
	return 0;
}