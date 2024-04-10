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

int last[21],n,x,d[1<<21];

int main()
{
	reset(last,-1);
	cin >> n;
	rep(i,n)
	{
		cin >> x;
		if (!x) 
		{
			d[x]=1; continue;
		}
		rep(j,20)
			if (x>>j&1) last[j]=i;
			
		vector < pair<int,int> > b;
		rep(j,20) 
			if (last[j]>=0) b.pb(mp(last[j],j));
		sort(all(b));
		
		x=0;
		for (int j=sz(b)-1;j>=0;)
		{
			int jj=j;
			while (jj>=0 && b[jj].fi==b[j].fi) x|=1<<b[jj--].se;
			d[x]=1;
			j=jj;
		}
	}
	
	int ans=0;
	rep(i,1<<20) ans+=d[i];
	cout << ans << endl;
}