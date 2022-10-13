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
#define pii pair<int,int>
#define oo 1000111222
#define maxN 1
using namespace std;

struct edge
{
	int x,y,z,d;
};

bool operator < (const edge &i,const edge &j)
{
	return i.z<j.z;
}

int n,m,d[100100],ans[100100],region,mark[100100],step;
int p[100100],num[100100],low[100100],cnt,from[100100];
edge a[100100];
pair <int,int> l[100100];
vector <int> adj[100100],id[100100];
vector <int> v;

int get(int x)
{
	return (x==d[x]?d[x]:d[x]=get(d[x]));
}

void visit(int x,int par)
{
	int havePar=0;
	num[x]=low[x]=++cnt; p[x]=par;
	rep(i,sz(adj[x]))
	{
		int y=adj[x][i];
		if (y==par && !havePar) 
		{
				havePar=1; continue;
		}
		if (num[y]) low[x]=min(low[x],num[y]);
		else from[y]=id[x][i], visit(y,x), low[x]=min(low[x],low[y]);
	}
}

void reset(int x)
{
	adj[x].clear(); id[x].clear();
	num[x]=low[x]=0;
	v.pb(x); mark[x]=step;
}

int main()
{
	cin >> n >> m;
	region=n;
	fr(i,1,n) d[i]=i;
	rep(i,m) scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z), a[i].d=i;
	sort(a,a+m);
	
	for (int i=0;i<m && region>1;)
	{
		++step;
		v.clear();
		int j;
		for (j=i;j<m && a[j].z==a[i].z;j++)
		{
			int x=get(a[j].x),y=get(a[j].y);
			if (x!=y) 
			{
				ans[a[j].d]++;
				if (mark[x]!=step) reset(x);
				if (mark[y]!=step) reset(y);
				adj[y].pb(x); id[y].pb(a[j].d);
				adj[x].pb(y); id[x].pb(a[j].d);
			}
		}
		
		rep(j,sz(v))
			if (!num[v[j]]) visit(v[j],0);

		rep(j,sz(v))
			if (p[v[j]] && low[v[j]]==num[v[j]]) ans[from[v[j]]]++;
			
		while (i<j)
		{
			int x=get(a[i].x),y=get(a[i].y);
			if (x!=y) d[x]=y, region--;
			i++;
		}
	}
	
	rep(i,m) puts(ans[i]?(ans[i]==1?"at least one":"any"):"none");
}