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
#define maxN 1
using namespace std;

int n,m,d[100100],low[100100],num[1000100],st[100100],last,step,region,t;
int h[100100],p[100100][20],H,power[100100],cnt[100100],f[100100][20],e[100100],region2;
vector < pair<int,int> > edge;
vector <int> a[100100],b[100100];

void visit(int x,int par)
{
	low[x]=num[x]=++step; st[++last]=x;
	rep(i,sz(a[x]))
	{
		int y=a[x][i];
		if (d[y] || y==par) continue;
		if (num[y]) low[x]=min(low[x],num[y]);
		else visit(y,x), low[x]=min(low[x],low[y]);
	}
	if (num[x]>low[x]) return;
	++region;
	while (1)
	{
		int y=st[last--];
		d[y]=region; cnt[region]++;
		if (y==x) return;
	}
}

void dfs(int x,int par)
{
	H=max(H,h[x]); p[x][0]=par;
	f[x][0]=(cnt[x]>2); e[x]=region2;
	rep(i,sz(b[x]))
	{
		int y=b[x][i];
		if (y==par || e[y]) continue;
		h[y]=h[x]+1;
		dfs(y,x);
	}
}

int calc(int x,int y)
{
	int lg=19,res=0;
	if (h[x]<h[y]) swap(x,y);
	frr(i,lg,0)
		if (h[x]-(1<<i)>=h[y])
			res+=f[x][i], x=p[x][i];
			
	if (x==y) return res+f[x][0];
	
	frr(i,lg,0)
		if (p[x][i]!=p[y][i])
		{
			res+=f[x][i]+f[y][i];
			x=p[x][i], y=p[y][i];
		}
	
	return res+f[x][1]+f[y][0];
}

int main()
{
	int x,y;
	cin >> n >> m;
	fr(i,0,m) power[i]=i?power[i-1]*2%1000000007:1;
	
	rep(i,m)
	{
		cin >> x >> y;
		a[x].pb(y);
		a[y].pb(x);
		edge.pb(mp(x,y));
	}
	
	fr(i,1,n)
		if (!d[i]) visit(i,0);
	
	rep(i,m)
	{
		int x=d[edge[i].fi],y=d[edge[i].se];
		if (x!=y) b[x].pb(y), b[y].pb(x);
	}
	
	fr(i,1,region)
		if (!e[i]) ++region2, dfs(i,0);
		
	for (int j=1;j<20;j++)
		fr(i,1,region)
		{
			p[i][j]=p[p[i][j-1]][j-1];
			f[i][j]=f[i][j-1]+f[p[i][j-1]][j-1];
		}
			
	int q;
	cin >> q;
	while (q--) 
	{
		cin >> x >> y;
		if (e[d[x]]!=e[d[y]]) puts("0");
		else cout << power[calc(d[x],d[y])] << endl;
	}
}