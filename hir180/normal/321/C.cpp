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
#define INF 2000000000
#define f first
#define s second
#define rep(i,x) for(int i=0;i<x;i++)
int n;
vector<int>edge[100005];
char ret[100005];
int cnt[100005];
bool rem[100005];
int make(int v,int u)
{
	if(rem[v]) return 0;
	cnt[v]=1;
	for(int i=0;i<edge[v].size();i++)
	{
		int x=edge[v][i];
		if(x==u || rem[x]) continue;
		cnt[v]+=make(x,v);
	}
	return cnt[v];
}
//SIZE and POSITION
//MINIMIZE LARGEST SUBTREE SIZE
P search(int v,int u,int c)
{
	P ret=mp(INF,-1);
	int sum=1,maxv=0;
	for(int i=0;i<edge[v].size();i++)
	{
		int x=edge[v][i];
		if(x==u || rem[x]) continue;
		maxv=max(maxv,cnt[x]);
		sum+=cnt[x];
		ret=min(ret,search(x,v,c));
	}
	maxv=max(maxv,c-sum);
	ret=min(ret,mp(maxv,v));
	return ret;
}
void sol(int v,int cur)
{
	make(v,-1);
	int cent=search(v,-1,cnt[v]).s;
	ret[cent]=cur+'A';
	rem[cent]=true;
	for(int i=0;i<edge[cent].size();i++)
	{
		if(!rem[edge[cent][i]]) sol(edge[cent][i],cur+1);
	}
}
int main()
{
	srand((unsigned int)time(NULL));
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int a,b; scanf("%d%d",&a,&b);
		edge[a].pb(b);
		edge[b].pb(a);
	}
	sol(1,0);
	for(int i=1;i<=n;i++) printf("%c ",ret[i]);
	puts("");
}