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
#define pii pair<int,int>
#define oo 1000111222
#define maxN 1
using namespace std;

int n,ans,f[100100],d[100100],occur[100100];
vector <int> a[100100],c[100100],pos[100100];
priority_queue < pair<int,int> > q;

int main()
{
	//freopen("d2","r",stdin);
	int m,x,y,z,L,capital;
	cin >> n >> m >> capital;
	while (m--) 
	{
		scanf("%d%d%d",&x,&y,&z);
		a[x].pb(y); c[x].pb(z); pos[x].pb(m);
		a[y].pb(x); c[y].pb(z); pos[y].pb(m);
	}
	cin >> L;

	fr(i,1,n) f[i]=oo;
	f[x=capital]=0; 
	q.push(mp(0,x));
	while (!q.empty())
	{
		int x=q.top().second,F=-q.top().first; q.pop();
		if (f[x]!=F) continue;
		d[x]=1; 
		rep(i,sz(a[x]))
		{
			int y=a[x][i];
			if (!d[y] && f[y]>f[x]+c[x][i])
				f[y]=f[x]+c[x][i], q.push(mp(-f[y],y));
		}
	}

	fr(x,1,n) ans+=(f[x]==L);
	fr(x,1,n)
		if (f[x]<L)
			rep(i,sz(a[x]))
			{
				int C=c[x][i],P=pos[x][i],y=a[x][i];
				if (f[x]+C>L)
				{
					int dist=f[y]+f[x]+C-L;
					if (dist<L) continue;
					if (occur[P]!=f[x]+C-L) ans++, occur[P]=L-f[x];
				}
			}
	cout << ans << endl;
}