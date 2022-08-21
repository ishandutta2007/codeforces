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
const ll mod = 1000000007;
#define rep(i, n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define repl(i, l, n) for(int i=l;i<n;++i)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define stop char nyaa;cin>>nyaa;

typedef long double ld;
const ld eps = 1e-8;

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	int chk;
	rep(i, n) {
		cin >> a[i];
		if (a[i] == -1)chk = i + 1;
	}
	int t = 1;
	while (t <= chk)t *= 2;
	t /= 2;
	int cop = t;
	int tmp = 0;
	while (cop < n) {
		cop *= 2; tmp++;
	}
	int m = n;
	priority_queue<int, vector<int>, greater<int>> q;
	ll ans = 0;
	q.push(a.back()); a.pop_back();
	rep(i, tmp) {
		int u = q.top(); q.pop();
		ans += u;
		m /= 2;
		rep(j, m) {
			q.push(a.back()); a.pop_back();
		}
	}
	cout << ans << endl;
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	solve();
	//stop
	return 0;
}