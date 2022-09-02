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
vector<int>edge[100005];
bool chpo[100005];
int dp[100005];
int main()
{
	srand((unsigned int)time(NULL));
	int n,m,k,s,t;
	cin >> n >> m >> k;
	for(int i=1;i<=k;i++)
	{
		int x; cin >> x;
		chpo[x]=true;
	}
	for(int i=1;i<=m;i++)
	{
		int u,v; cin >> u >> v;
		edge[u].pb(v);
		edge[v].pb(u);
	}
	cin >> s >> t;
	int lb=0,ub=1000000;
	while(ub-lb>1)
	{
		fill(dp,dp+n+1,INF);
		dp[s]=0;
		int mid=(lb+ub)>>1;
		priority_queue<P,vector<P>,greater<P> >que;
		que.push(mp(0,s));
		while(!que.empty())
		{
			P p=que.top(); que.pop();
			if(p.fi!=dp[p.sc]) continue;
			int i=p.sc;
			{
				for(int j=0;j<edge[i].size();j++)
				{
					int to=edge[i][j];
					if(dp[i]+1<=mid && dp[to]>(chpo[to]?0:dp[i]+1))
					{
						dp[to]=dp[i]+1;
						if(chpo[to]) dp[to]=0;
						que.push(mp(dp[to],to));
					}
				}
			}
		}
		if(dp[t]!=INF) ub=mid;
		else lb=mid;
	}
	cout << (ub==1000000?-1:ub) << endl;
}