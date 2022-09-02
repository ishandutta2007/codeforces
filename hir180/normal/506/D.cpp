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
vector<int>col[100005];
vector<int>par[100005];
vector<int>ran[100005];
bool big[100005];
vector<P1>edge;

int find(int x,int c)
{
	if(x == -1) return -1;
	int a = lower_bound(col[x].begin(),col[x].end(),c)-col[x].begin();
	if(a == col[x].size() || col[x][a] != c) return -1;
	
	if(par[x][a] == x) return x;
	else return par[x][a]=find(par[x][a],c);
}
void unite(int x,int y,int c)
{
	x=find(x,c);
	y=find(y,c);
	if(x == y) return ;
	int a = lower_bound(col[x].begin(),col[x].end(),c)-col[x].begin();
	int b = lower_bound(col[y].begin(),col[y].end(),c)-col[y].begin();
	if(ran[x][a] < ran[y][b]) par[x][a]=par[y][b];
	else 
	{
		par[y][b] = par[x][a];
		if(ran[x][a] == ran[y][b]) ran[x][a]++;
	}
}
bool same(int x,int y,int c)
{
	return find(x,c) == find(y,c);
}
int n,m;

int main()
{
	cin >> n >> m;
	for(int i=0;i<m;i++)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		col[a].pb(c);
		col[b].pb(c);
		edge.pb(mp(c,mp(a,b)));
	}
	vector<int>many;
	int v = 893;
	for(int i=1;i<=n;i++)
	{
		sort(col[i].begin(),col[i].end());
		col[i].erase(unique(col[i].begin(),col[i].end()),col[i].end());
		par[i].resize(col[i].size(),i);
		ran[i].resize(col[i].size(),0);
		if(col[i].size() >= v)
		{
			many.pb(i);
			big[i] = true;
		}
	}
	for(int i=0;i<m;i++)
	{
		unite(edge[i].sc.fi,edge[i].sc.sc,edge[i].fi);
	}
	map<P,int>ma;
	for(int i=0;i<many.size();i++)
	{
		for(int j=i+1;j<many.size();j++)
		{
			int x = many[i];
			int y = many[j];
			if(col[x].size() > col[y].size()) swap(x,y);
			int r = 0;
			for(int k=0;k<col[x].size();k++)
			{
				if(binary_search(col[y].begin(),col[y].end(),col[x][k])) r+=same(x,y,col[x][k]);
			}
			ma[mp(min(x,y),max(x,y))] = r;
		}
	}
	int q; cin >> q;
	map<P,int>pre;
	for(int i=0;i<q;i++)
	{
		int x,y; scanf("%d %d",&x,&y);
		if(pre.find(mp(min(x,y),max(x,y))) != pre.end()) printf("%d\n",pre[mp(min(x,y),max(x,y))]);
		else if(big[x] && big[y]) printf("%d\n",ma[mp(min(x,y),max(x,y))]);
		else
		{
			if(col[x].size() > col[y].size()) swap(x,y);
			int r = 0;
			for(int k=0;k<col[x].size();k++)
			{
				if(binary_search(col[y].begin(),col[y].end(),col[x][k])) r+=same(x,y,col[x][k]);
			}
			pre[mp(min(x,y),max(x,y))] = r;
			printf("%d\n",r);
		}
	}
}