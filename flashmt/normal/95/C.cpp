#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <sstream>
#include <queue>
#define fr(a,b,c) for (a=b;a<=c;a++)
#define frr(a,b,c) for (a=b;a>=c;a--)
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define F first
#define S second
#define oo 1000111222
using namespace std;
typedef long long ll;
const int dx[]={-1,0,1,0,-1,1,1,-1};
      int dy[]={0,1,0,-1,1,1,-1,-1};
      
int m,n,S,F,len[1111],price[1111],d[1111];
long long f[1111][1111],cost[1111];
vector < int > a[1111],c[1111];
priority_queue  < pair<long long,int> > q;

void Dijkstra(int start)
{
	int x=start;
	for (int i=1;i<=n;i++) d[i]=0, f[start][i]=1LL*oo*oo;
	f[start][x]=0;
	while (!q.empty()) q.pop();
	q.push(make_pair(0,x));
	while (!q.empty())
	{
		pair <long long,int> u=q.top(); q.pop();
		x=u.second; 
		long long fx=-u.first;
		if (fx!=f[start][x]) continue;
		d[x]=1;
		for (int i=0;i<int(a[x].size());++i)
		{
			int y=a[x][i];
			if (!d[y] && f[start][y]>fx+c[x][i])
			{
				f[start][y]=fx+c[x][i];
				q.push(make_pair(-f[start][y],y));
			}
		}
	}
}

void solve()
{
	int x=S;
	for (int i=1;i<=n;i++) d[i]=0, cost[i]=1LL*oo*oo;
	cost[x]=0; d[x]=1;
	while (!d[F])
	{
		for (int y=1;y<=n;y++)
			if (!d[y] && f[x][y]<=len[x]) cost[y]=min(cost[y],cost[x]+price[x]);
		long long mn=1LL*oo*oo-1;
		int t=0;
		fr(x,1,n)
			if (!d[x] && cost[x]<mn) mn=cost[x], t=x;
		if (!t) break;
		x=t; d[x]=1;
	}
	if (!d[F]) cout << -1 << endl;
	else cout << cost[F] << endl;
}

int main()
{
	//freopen("c.in.0","r",stdin);
	cin >> n >> m >> S >> F;
	while (m--)
	{
		int x,y,z;
		cin >> x >> y >> z;
		a[x].push_back(y); c[x].push_back(z);
		a[y].push_back(x); c[y].push_back(z);
	}
	for (int i=1;i<=n;i++) cin >> len[i] >> price[i], Dijkstra(i);
	solve();
	return 0;
}