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
typedef vector<int> vec;
typedef vector<string> svec;
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-8;

vector<int> G[1 << 18];
LP dfs(int id, int fr) {
	if (G[id].size() == 0) {
		return { 1,1 };
	}
	vector<LP> v;
	rep(j, G[id].size()) {
		int to = G[id][j];
		if (to == fr)continue;
		v.push_back(dfs(to, id));
	}
	int len = v.size();
	vector<ll> lp(v.size()), rp(v.size());
	lp[0] = v[0].first; rp[len - 1] = v[len - 1].first;
	rep1(i, len - 1) {
		lp[i] = lp[i - 1] * v[i].first%mod;
		rp[len - 1 - i] = rp[len - i] * v[len - 1 - i].first % mod;
	}
	ll x = 1;
	rep(i, len) {
		x = x * (v[i].first + v[i].second) % mod;
	}
	ll dif = 0;
	rep(i, len) {
		ll pro = v[i].second;
		if (i > 0)pro = pro * lp[i - 1] % mod;
		if (i < len - 1)pro = pro * rp[i + 1] % mod;
		dif += pro;
		if (dif >= mod)dif -= mod;
	}
	x += mod - dif;
	if (x >= mod)x -= mod;
	ll adpro = 1;
	rep(i, len) {
		adpro = adpro * v[i].first%mod;
	}
	x += mod - adpro; if (x >= mod)x -= mod;
	LP ret;
	ret.first = (adpro + x) % mod;
	ret.second = (dif + x) % mod;
	return ret;
}
void solve() {
	int n; cin >> n;
	rep1(i, n - 1) {
		int p; cin >> p; p--;
		G[p].push_back(i);
	}
	LP ans = dfs(0, -1);
	cout << ans.first << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init();
	solve();
	//cout << "finish" << endl;
	//stop
	return 0;
}