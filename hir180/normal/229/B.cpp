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
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
map<P,int>ma;
vector<P>edge[100005];
int d[100005];
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++)
	{
		int u,v,c; scanf("%d %d %d",&u,&v,&c);
		edge[u].pb(mp(v,c));
		edge[v].pb(mp(u,c));
	}
	for(int i=1;i<=n;i++)
	{
		int cnt; scanf("%d",&cnt);
		queue<int>que;
		int prev=INF;
		for(int j=0;j<cnt;j++)
		{
			int f; scanf("%d",&f);
			if(prev+1!=f)
			{
				while(!que.empty())
				{
					ma[mp(i,que.front())]=prev+1;
					que.pop();
				}
			}
			prev=f; que.push(f);
		}
		while(!que.empty())
		{
			ma[mp(i,que.front())]=prev+1;
			que.pop();
		}
	}
	fill(d,d+n+1,INF);
	d[1]=0;
	priority_queue<P,vector<P>,greater<P> >que;
	que.push(mp(0,1));
	while(!que.empty())
	{
		P p=que.top(); que.pop();
		int time=p.fi;
		int cur=p.sc;
		if(d[cur]!=time) continue;
		for(int i=0;i<edge[cur].size();i++)
		{
			int nxt=time;
			if(ma.find(mp(cur,time))!=ma.end())
			{
				nxt=ma[mp(cur,time)];
			}
			if(d[edge[cur][i].fi] > nxt+edge[cur][i].sc)
			{
				d[edge[cur][i].fi] = nxt+edge[cur][i].sc;
				que.push(mp(d[edge[cur][i].fi],edge[cur][i].fi));
			}
		}
	}
	printf("%d\n",d[n]==INF?-1:d[n]);
}