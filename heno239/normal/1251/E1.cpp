#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<utility>
#include<set>

using namespace std;

//#define int long long

using ll = long long;
using P = pair<int, int>;
using LP = pair<ll, ll>;
const ll INF = (1e+18) + 100;
const ll mod = 998244353;
#define rep(i, n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define repl(i, l, n) for(int i=l;i<n;++i)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define stop char nyaa;cin>>nyaa;


void solve() {
	int n; cin >> n;
	vector<vector<int>> loc(n);
	rep(i, n) {
		int m, val;
		cin >> m >> val;
		loc[m].push_back(val);
	}
	ll ans = 0;
	priority_queue<int, vector<int>, greater<int>> q;
	per(i, n) {
		int sup = n - i;
		rep(j, loc[i].size())q.push(loc[i][j]);
		while (q.size() > sup) {
			ans += q.top(); q.pop();
		}
	}
	cout << ans << endl;
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	int t; cin >> t;
	rep(i, t) {
		solve();
	}
	//stop
	return 0;
}