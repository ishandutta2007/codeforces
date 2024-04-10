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

int n,m,V,S,T,v[100100],isV[100100],d[100100],f[100100];
vector <int> a[100100];

void bfs()
{
	queue <int> q;
	d[S]=1;
	q.push(S);
	while (!q.empty())
	{
		int x=q.front(); q.pop();
		rep(i,sz(a[x]))
		{
			int y=a[x][i];
			if (!d[y]) d[y]=d[x]+1, q.push(y);
		}
	}
}

int possible(int val)
{
	queue <int> q;
	fr(i,1,n) f[i]=-1, d[i]=0;
	f[S]=val;
	q.push(S);
	while (!q.empty())
	{
		int x=q.front(); q.pop();
		if (x==T) return 1;
		if (d[x] || !f[x]) continue;
		d[x]=1;
		rep(i,sz(a[x]))
		{
			int y=a[x][i],F=(isV[y]?val:f[x]-1);
			if (F>f[y]) f[y]=F, q.push(y), d[y]=0;
		}
	}
	return 0;
}

int main()
{
	int x,y;
	cin >> n >> m >> V;
	rep(i,V) scanf("%d",v+i), isV[v[i]]=1;
	while (m--) 
	{
		scanf("%d%d",&x,&y);
		a[x].pb(y); a[y].pb(x);
	}
	cin >> S >> T;
	
	bfs();
	if (!d[T]) 
	{
		puts("-1"); return 0;
	}
	
	int low=1,high=d[T],ans=high;
	while (low<=high)
	{
		int mid=(low+high)/2;
		if (possible(mid)) high=mid-1, ans=mid;
		else low=mid+1;
	}
	
	cout << ans << endl;
}