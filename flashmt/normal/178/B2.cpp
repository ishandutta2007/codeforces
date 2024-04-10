#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
#define fr(a,b,c) for (int a=b;a<=c;a++)
#define frr(a,b,c) for (int a=b;a>=c;a--)
#define rep(a,b) for (int a=0;a<b;a++)
#define repp(a,b) for (int a=b-1;a>=0;a--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) int(a.size())
#define all(a) a.begin(),a.end()
#define reset(a,b) memset(a,b,sizeof(a))
#define pii pair<int,int>
#define oo 1000111222
#define N 100100
using namespace std;

int n,step,low[N],num[N],region,d[N],st[N],last,p[N][20],h[N],H;
vector <int> a[N],b[N];
pair <int,int> edge[100100];

void visit(int x,int par)
{
	st[++last]=x; num[x]=low[x]=++step;
	rep(i,sz(a[x]))
	{
		int y=a[x][i];
		if (y==par || d[y]) continue;
		if (num[y]) low[x]=min(low[x],num[y]);
		else visit(y,x), low[x]=min(low[x],low[y]);
	}
	if (low[x]<num[x]) return;
	++region;
	while (1)
	{
		int y=st[last--];
		d[y]=region;
		if (y==x) break;
	}
}

void dfs(int x,int par)
{
	p[x][0]=par; H=max(H,h[x]);
	rep(i,sz(b[x]))
	{
		int y=b[x][i];
		if (y!=par)
		{
			h[y]=h[x]+1;
			dfs(y,x);
		}
	}
}

int lca(int x,int y)
{
	if (h[x]<h[y]) swap(x,y);
	int lg=0;
	while (1<<lg<h[x]) lg++;
	frr(i,lg,0)
		if (h[x]-(1<<i)>=h[y])
			x=p[x][i];
	
	if (x==y) return x;
	
	frr(i,lg,0)
		if (p[x][i]!=p[y][i])
			x=p[x][i], y=p[y][i];
	
	return p[x][0];
}

int main()
{
	int m,x,y;
	cin >> n >> m;
	rep(i,m) scanf("%d%d",&x,&y), a[x].pb(y), a[y].pb(x), edge[i]=mp(x,y);
	fr(i,1,n)
		if (!d[i])
			visit(i,0);
	
	rep(i,m)
	{
		x=edge[i].fi; y=edge[i].se;
		if (d[x]!=d[y]) b[d[x]].pb(d[y]), b[d[y]].pb(d[x]);
	}
	
	dfs(1,0);
	for (int j=1;1<<j<=H;j++)
		fr(i,1,region)
			p[i][j]=p[p[i][j-1]][j-1];
	
	int q;
	cin >> q;
	while (q--)
	{
		scanf("%d%d",&x,&y);
		x=d[x]; y=d[y];
		int z=lca(x,y);
		printf("%d\n",h[x]+h[y]-h[z]*2);
	}
}