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
#define reset(a,b) memset(a,b,sizeof(a))
#define pii pair<int,int>
#define oo 1000111222
#define maxN 1
using namespace std;

int m,dist[100100],visited[100100];
pair <int,int> a[100100];
map < pair<int,int>,int > d;
queue <int> q;

int main()
{
	int n,sx,sy,fx,fy,x,y,yy;
	cin >> sx >> sy >> fx >> fy >> n;
	while (n--)
	{
		cin >> x >> y >> yy;
		while (y<=yy)
		{
			if (!d.count(make_pair(x,y))) d[make_pair(x,y)]=m, a[m++]=make_pair(x,y);
			y++;
		}
	}
	
	int s=d[make_pair(sx,sy)],f=d[make_pair(fx,fy)];
	q.push(s); visited[s]=1;
	while (!visited[f] && !q.empty())
	{
		int u=q.front();
		q.pop();
		for (int dx=-1;dx<=1;dx++)
			for (int dy=-1;dy<=1;dy++)
			{
				int xx=a[u].first+dx,yy=a[u].second+dy;
				if (!d.count(make_pair(xx,yy))) continue;
				int v=d[make_pair(xx,yy)];
				if (visited[v]) continue;
				visited[v]=1; q.push(v);
				dist[v]=dist[u]+1;
			}
	}
	
	cout << (visited[f]?dist[f]:-1) << endl;
}