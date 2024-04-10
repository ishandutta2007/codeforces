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
typedef pair<int,long long> P;
typedef pair<long long,int> Q;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
typedef long long ll;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000001
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
int n,m,k;
ll d[100005];
ll e[100005];
vector<P>edge[100005];
vector<P>all;
int main()
{
	cin >> n >> m >> k;
	for(int i=0;i<m;i++)
	{
		int a,b; ll c; scanf("%d%d%lld",&a,&b,&c);
		edge[a].pb(mp(b,c));
		edge[b].pb(mp(a,c));
	}
	priority_queue<Q,vector<Q>,greater<Q> >que;
	ll q[100005]={};
	for(int i=0;i<k;i++)
	{
		int x; ll y; scanf("%d%lld",&x,&y);
		if(q[x]==0) q[x]=y;
		else q[x]=min(q[x],y);
	}
	for(int i=1;i<=n;i++) if(q[i]) que.push(mp(q[i],i));
	que.push(mp(0,1));
	for(int i=2;i<100005;i++) d[i] = 1e18; int cnt = k;
	while(!que.empty())
	{
		Q q = que.top(); que.pop();
		if(d[q.sc] > q.fi) { cnt--; d[q.sc] = q.fi; }
		if(d[q.sc] != q.fi) continue;
		for(int i=0;i<edge[q.sc].size();i++)
		{
			if(d[edge[q.sc][i].fi] > q.fi+edge[q.sc][i].sc)
			{
				d[edge[q.sc][i].fi] = q.fi+edge[q.sc][i].sc;
				
				que.push(mp(d[edge[q.sc][i].fi],edge[q.sc][i].fi));
			}
		}
	}
	cout << cnt << endl;
}