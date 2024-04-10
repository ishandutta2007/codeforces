#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

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
#include<unordered_set>
#include<utility>
#include<cassert>
#include<complex>
#include<numeric>
#include<array>
using namespace std;

//#define int long long
typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
constexpr ll mod = 998244353;
const ll INF = mod * mod;
typedef pair<int, int>P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
#define all(v) (v).begin(),(v).end()
typedef pair<ll, ll> LP;
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-12;
const ld pi = acosl(-1.0);


void solve() {
	int n; cin >> n;
	vector<ll> x(n), y(n);
	rep(i, n)cin >> x[i] >> y[i];
	vector<int> ans;
	ans.push_back(0);
	ll mi = -1;
	int chk = -1;
	for (int i = 1; i < n; i++) {
		ll dx = x[i] - x[0];
		ll dy = y[i] - y[0];
		ll dist = dx * dx + dy * dy;
		if (mi < 0 || dist < mi) {
			mi = dist;
			chk = i;
		}
	}
	ans.push_back(chk);
	mi = -1;
	ll dx1 = x[chk] - x[0];
	ll dy1 = y[chk] - y[0];
	int mem = -1;
	for (int i = 1; i < n; i++)if (i != chk) {
		ll dx2 = x[i] - x[0];
		ll dy2 = y[i] - y[0];
		ll s = abs(dx1 * dy2 - dx2 * dy1);
		if (s == 0)continue;
		if (mi < 0 || s < mi) {
			mi = s; mem = i;
		}
	}
	ans.push_back(mem);
	sort(all(ans));
	cout << ans[0] + 1 << " " << ans[1] + 1 << " " << ans[2] + 1 << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
		solve();
	return 0;
}