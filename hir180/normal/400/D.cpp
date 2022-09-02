//Bokan ga bokka--nn!!
//Daily Lunch Special Tanoshii !!
//HIR180
//IOI2014N
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
int par[100005],ran[100005];
void init(){ for(int i=0;i<100005;i++){ ran[i]=0; par[i]=i;}}
int find(int x){ if(par[x]==x) return x;else return par[x]=find(par[x]);}
bool same(int x,int y){ return find(x)==find(y);}
void unite(int x,int y)
{
	x=find(x); y=find(y);
	if(x==y) return;
	if(ran[x]<ran[y]) par[x]=y;
	else{ par[y]=x; if(ran[x]==ran[y]) ran[x]++;}
}
int d[505][505];
int bel[100005];
int main()
{
	int n,m,k; cin >> n >> m >> k;
	int c[505];
	for(int i=1;i<=k;i++) scanf("%d",&c[i]);
	int cur=0;
	for(int i=1;i<=k;i++) 
	{
		for(int j=cur;j<cur+c[i];j++)
		{
			bel[j]=i;
		}
		cur+=c[i];
	}
	init();
	for(int i=1;i<=k;i++) for(int j=1;j<=k;j++) if(i!=j) d[i][j]=1e9;
	for(int i=0;i<m;i++)
	{
		int x,y,v; scanf("%d %d %d",&x,&y,&v);
		--x; --y;
		d[bel[x]][bel[y]]=min(d[bel[x]][bel[y]],v);
		d[bel[y]][bel[x]]=min(d[bel[y]][bel[x]],v);
		if(v==0) unite(x,y);
	}
	int back=0;
	bool ok=false;
	for(int i=1;i<=k;i++)
	{
		for(int j=back;j<back+c[i];j++)
		{
			if(!same(back,j)) goto out;
		}
		back+=c[i];
		continue;
		out:;puts("No"); return 0;
	}
	puts("Yes");
	for(int mid=1;mid<=k;mid++)
	{
		for(int i=1;i<=k;i++)
		{
			for(int j=1;j<=k;j++)
			{
				d[i][j]=min(d[i][j],d[i][mid]+d[mid][j]);
			}
		}
	}
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=k;j++)
		{
			if(d[i][j]==1e9) printf("-1 ");
			else printf("%d ",d[i][j]);
		}
		puts("");
	}
}