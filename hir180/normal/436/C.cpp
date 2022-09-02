#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
using namespace std;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
typedef long long ll;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)

int n,m,k,w;
char f[1005][15][15];
bool used[1005];
vector<int>edge[1005];
vector<P1>all;

int par[1005];
int ran[1005];
void init()
{
	for(int i=0;i<1005;i++) par[i]=i,ran[i]=0;
}
int find(int x)
{
	if(par[x] == x) return x;
	else return par[x]=find(par[x]);
}
void unite(int x,int y)
{
	x=find(x);
	y=find(y);
	if(x == y) return ;
	if(ran[x]<ran[y]) par[x]=par[y];
	else 
	{
		par[y]=par[x];
		if(ran[x] == ran[y]) ran[x]++;
	}
}
bool same(int x,int y)
{
	return find(x)==find(y);
}

void dfs(int v,int u)
{
	if(used[v]) return ;
	used[v] = true;
	if(u != -1) printf("%d %d\n",v,u);
	else printf("%d %d\n",v,0);
	
	for(int i=0;i<edge[v].size();i++)
	{
		if(edge[v][i] == u) continue;
		dfs(edge[v][i],v);
	}
}

int main()
{
	cin >> n >> m >> k >> w;
	for(int i=1;i<=k;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%s",&f[i][j]);
		}
	}
	for(int i=1;i<=k;i++)
	{
		for(int j=i+1;j<=k;j++)
		{
			int dif = 0;
			for(int a=0;a<n;a++) for(int b=0;b<m;b++) dif +=(f[i][a][b] != f[j][a][b]);
			all.pb(mp(dif*w,mp(i,j)));
		}
	}
	for(int i=1;i<=k;i++) all.pb(mp(n*m,mp(0,i)));
	sort(all.begin(),all.end());
	init();
	int res = 0;
	for(int i=0;i<all.size();i++)
	{
		if(!same(all[i].sc.fi,all[i].sc.sc))
		{
			unite(all[i].sc.fi,all[i].sc.sc);
			res += all[i].fi;
			edge[all[i].sc.fi].pb(all[i].sc.sc);
			edge[all[i].sc.sc].pb(all[i].sc.fi);
		}
	}
	cout << res << endl;
	
	for(int i=0;i<edge[0].size();i++) dfs(edge[0][i],0);
}