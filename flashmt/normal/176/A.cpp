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

int n,m,k,a[22][111],b[22][111],c[22][111],ans;
string name[11];

void att(int x,int y)
{
	vector < pair<int,int> > d;
	rep(i,m) d.pb(mp(b[y][i]-a[x][i],c[x][i]));
	sort(all(d));
	int cnt=k,profit=0;
	repp(i,sz(d))
		if (d[i].fi>0)
		{
			int buy=min(cnt,d[i].se);
			cnt-=buy;
			profit+=buy*d[i].fi;
		}
	ans=max(ans,profit);
}

int main()
{
	cin >> n >> m >> k;
	rep(i,n) 
	{
		cin >> name[i];
		rep(j,m) cin >> a[i][j] >> b[i][j] >> c[i][j];
	}
	rep(i,n)
		rep(j,n)
			if (i!=j)
				att(i,j);
	cout << ans << endl;
}