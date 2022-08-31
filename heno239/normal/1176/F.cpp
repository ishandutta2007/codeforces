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
#include<random>
#include<map>
#include<set>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
#include<cassert>
using namespace std;

//#define int long long
typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 998244353;
const ll INF = mod * mod;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef pair<ll, ll> LP;
typedef vector<ll> vec;
typedef vector<string> svec;
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-8;

ll dp[10], cop[10];
void solve() {
	int n; cin >> n;
	fill(dp, dp + 10, -INF); dp[0] = 0;
	rep(i, n) {
		fill(cop, cop + 10, -INF);
		int k; cin >> k;
		vector<ll> v[3];
		rep(j, k) {
			int c; ll d;
			cin >> c >> d;
			v[c-1].push_back(d);
		}
		rep(j, 3) {
			sort(v[j].begin(), v[j].end(), greater<ll>());
		}
		//0
		rep(j, 10) {
			cop[j] = max(cop[j], dp[j]);
		}
		//1
		ll ma = 0; ll ma2 = 0;
		rep(j, 3) {
			if (v[j].empty())continue;
			ma = max(ma, v[j][0]);
		}
		rep(j, 9) {
			cop[j + 1] = max(cop[j + 1], dp[j] + ma);
		}
		cop[0] = max(cop[0], dp[9] + ma * 2);
		//2
		ma = -INF; ma2 = -INF;
		if (v[0].size() >= 2) {
			ma = max(ma, v[0][0] + v[0][1]);
			ma2 = max(ma2, 2 * v[0][0] + v[0][1]);
		}
		if (v[0].size() && v[1].size()) {
			ma = max(ma, v[0][0] + v[1][0]);
			ma2 = max({ ma2,2 * v[0][0] + v[1][0],v[0][0] + 2 * v[1][0] });
		}
		if (ma != -INF) {
			rep(j, 8) {
				cop[j + 2] = max(cop[j + 2], dp[j] + ma);
			}
			Rep(j, 8, 10) {
				cop[j - 8] = max(cop[j - 8], dp[j] + ma2);
			}
		}
		//3
		if (v[0].size() >= 3) {
			ma = 0; ma2 = 0;
			rep(j, 3)ma += v[0][j];
			ma2 = ma + v[0][0];
			rep(j, 7) {
				cop[j + 3] = max(cop[j + 3], dp[j] + ma);
			}
			Rep(j, 7, 10) {
				cop[j - 7] = max(cop[j - 7], dp[j] + ma2);
			}
		}
		rep(j, 10) {
			dp[j] = cop[j];
		}
	}
	ll ans = 0;
	rep(i, 10) {
		ans = max(ans, dp[i]);
	}
	cout << ans << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(10);
	//init();
	solve();
	//cout << "finish" << endl;
	//stop
	return 0;
}