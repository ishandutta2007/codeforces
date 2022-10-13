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

int main()
{
	int n, a[4444], ans = 0, cnt[4444], last[4444];
	vector <int> X;
	cin >> n;
	rep(i,n) cin >> a[i], X.pb(a[i]);
	sort(all(X));
	X.resize(unique(all(X)) - X.begin());
	rep(i,n) a[i] = lower_bound(all(X), a[i]) - X.begin();
	
	rep(i,n)
	{
		int lim = i, x = 1;
		reset(cnt, 0);
		reset(last, -1);
		fr(j,i+1,n-1)
			if (a[j] == a[i]) x++, lim = j;
			else
				if (last[a[j]] < lim) cnt[a[j]]++, last[a[j]] = j;
		
		rep(j,sz(X)) 
			if (last[j] > lim) ans = max(ans, cnt[j] * 2);
			else ans = max(ans, cnt[j] * 2 + 1);
			
		ans = max(ans, x);
	}
	
	cout << ans << endl;
}