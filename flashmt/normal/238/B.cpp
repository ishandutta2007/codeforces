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
#include <ctime>
#include <cstdlib>
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

vector < pii > a;
int n,h;

int main()
{
	int x;
	cin >> n >> h;
	if (n==2)
	{
		puts("0");
		puts("1 2");
		return 0;
	}
	
	rep(i,n) cin >> x, a.pb(mp(x,i));
	sort(all(a));
	
	int ans=a[n-1].fi+a[n-2].fi-(a[0].fi+a[1].fi),flag=-1;
	rep(i,n)
	{
		int cnt=0,mn[2],mx[2];
		rep(j,n)
			if (i!=j)
			{
				mn[cnt++]=a[j].fi;
				if (cnt==2) break;
			}
		cnt=0;
		repp(j,n)
			if (i!=j)
			{
				mx[cnt++]=a[j].fi;
				if (cnt==2) break;
			}
		
		int val=max(mx[0]+mx[1],mx[0]+a[i].fi+h) - min(mn[0]+mn[1],mn[0]+a[i].fi+h);
		if (val<ans) ans=val, flag=a[i].se;
	}
		
	cout << ans << endl;
	rep(i,n) cout << (flag==i?2:1) << ' ';
}