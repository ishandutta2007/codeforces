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
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000111222
using namespace std;
const int MAX = int(1e7)+10;

int n,m,d[MAX],p[MAX/10],P,ca[MAX/10],cb[MAX/10];
vector < pair<int,int> > a[100100],b[100100];

void write(int n,vector < pair<int,int> > a[100100],int c[])
{
	rep(i,n)
	{
		int val=1;
		rep(j,sz(a[i]))
		{
			int k=d[a[i][j].fi],t=min(c[k],a[i][j].se);
			c[k]-=t; a[i][j].se-=t;
			while (a[i][j].se--) val*=a[i][j].fi;
		}
		cout << val << ' ';
	}
	puts("");
}

int main()
{
	fr(i,2,4000)
		if (!d[i])
			for (int j=i*i;j<MAX;j+=i)
				d[j]=-1;
	fr(i,2,MAX-1)
		if (!d[i]) p[P]=i, d[i]=P++; 
		
	cin >> m >> n;
	rep(j,m+n)
	{
		int x;
		cin >> x;
		for (int i=0;p[i]*p[i]<=x;i++)
			if (x%p[i]==0) 
			{
				int v=0;
				while (x%p[i]==0)	x/=p[i], v++;
				if (j<m) a[j].pb(mp(p[i],v)), ca[i]+=v;
				else b[j-m].pb(mp(p[i],v)), cb[i]+=v;
			}
		if (x>1) 
		{
			if (j<m) a[j].pb(mp(x,1)), ca[d[x]]++;
			else b[j-m].pb(mp(x,1)), cb[d[x]]++;
		}
	}
	
	rep(i,P) ca[i]=cb[i]=min(ca[i],cb[i]);
		
	cout << m << ' ' << n << endl;
	write(m,a,ca);
	write(n,b,cb);
}