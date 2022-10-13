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

int n,f[100100],d[100100];
vector <int> a[100100],c[100100];
vector < pair<int,int> > t[100100];

int main()
{
	int x,y,z,k,m;
	cin >> n >> m;
	while (m--)
	{
		scanf("%d%d%d",&x,&y,&z);
		a[x].pb(y); c[x].pb(z);
		a[y].pb(x); c[y].pb(z);
	}
	
	fr(i,1,n)
	{
		scanf("%d",&k);
		if (!k) 
		{
			t[i].pb(mp(0,oo-2));
			continue;
		}
		int last;
		scanf("%d",&last);
		t[i].pb(mp(0,last-1));
		while (--k)
		{
			scanf("%d",&x);
			if (x>last+1) t[i].pb(mp(last+1,x-1));
			last=x;
		}
		t[i].pb(mp(last+1,oo-2));
	}
	
	priority_queue < pair<int,int> > q;
	fr(i,1,n) f[i]=oo;
	f[1]=0; q.push(mp(0,1));
	while (!q.empty())
	{
		int x=q.top().se, F=-q.top().fi;
		q.pop();
		if (F!=f[x]) continue;
		d[x]=1;
		if (x==n) break;
		
		int i=lower_bound(all(t[x]),mp(F+1,-1))-t[x].begin();
		if (i<sz(t[x]))
		{
			if (t[x][i-1].se<F) F=t[x][i].fi;
		}
		
		rep(i,sz(a[x]))
		{
			int y=a[x][i],z=c[x][i];
			if (d[y]) continue;
			if (f[y]>F+z) f[y]=F+z, q.push(mp(-f[y],y));
		}
	}
	
	cout << (d[n]?f[n]:-1) << endl;
}