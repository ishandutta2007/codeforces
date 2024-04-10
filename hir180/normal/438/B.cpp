#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
typedef long long ll;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 100000000
#define fi first
#define sc second

int n,m;
int a[100005];

int par[100005];
int ran[100005];
int sz[100005];
void init()
{
	for(int i=0;i<100005;i++) par[i]=i,ran[i]=0,sz[i]=1;
}
int find(int x)
{
	if(par[x] == x) return x;
	else return par[x]=find(par[x]);
}
ll unite(int x,int y)
{
	x=find(x);
	y=find(y);
	if(x == y) return 0LL;
	if(ran[x]<ran[y])
	{
		par[x]=y;
		ll aa = 1LL*(sz[x]+sz[y])*(sz[x]+sz[y]-1)/2 - 1LL*sz[x]*(sz[x]-1)/2 - 1LL*sz[y]*(sz[y]-1)/2;
		sz[y]+=sz[x];
		return aa;
	}
	else 
	{
		par[y]=x;
		if(ran[x] == ran[y]) ran[x]++;
		ll aa = 1LL*(sz[x]+sz[y])*(sz[x]+sz[y]-1)/2 - 1LL*sz[x]*(sz[x]-1)/2 - 1LL*sz[y]*(sz[y]-1)/2;
		sz[x]+=sz[y];
		return aa;
	}
}
bool same(int x,int y)
{
	return find(x)==find(y);
}
int cnt(int x)
{
	x = find(x);
	return sz[x];
}
vector<int>val;
vector<int>edge[100005];
vector<int>vertex[100005];

int main()
{
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		val.pb(a[i]);
	}
	for(int i=0;i<m;i++)
	{
		int x,y;
		cin >> x >> y;
		edge[x].pb(y);
		edge[y].pb(x);
	}
	init();
	sort(val.begin(),val.end());
	val.erase(unique(val.begin(),val.end()),val.end());
	for(int i=1;i<=n;i++)
	{
		int x = lower_bound(val.begin(),val.end(),a[i])-val.begin();
		vertex[x].pb(i);
	}
	double res = 0.0;
	double div = 1.0*n*(n-1)/2;
	for(int i=val.size()-1;i>=0;i--)
	{
		for(int j=0;j<vertex[i].size();j++)
		{
			int v = vertex[i][j];
			for(int k=0;k<edge[v].size();k++)
			{
				if(a[ edge[v][k] ] >= val[i])
				{
					res += 1.0*val[i]*unite(v,edge[v][k]);
				}
			}
		}
	}
	printf("%.6f\n",res/div);
}