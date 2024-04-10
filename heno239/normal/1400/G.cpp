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

ll mod_pow(ll x, ll n, ll m = mod) {
	if (n < 0) {
		ll res = mod_pow(x, -n, m);
		return mod_pow(res, m - 2, m);
	}
	if (abs(x) >= m)x %= m;
	if (x < 0)x += m;
	ll res = 1;
	while (n) {
		if (n & 1)res = res * x % m;
		x = x * x % m; n >>= 1;
	}
	return res;
}
struct modint {
	ll n;
	modint() :n(0) { ; }
	modint(ll m) :n(m) {
		if (n >= mod)n %= mod;
		else if (n < 0)n = (n % mod + mod) % mod;
	}
	operator int() { return n; }
};
bool operator==(modint a, modint b) { return a.n == b.n; }
modint operator+=(modint& a, modint b) { a.n += b.n; if (a.n >= mod)a.n -= mod; return a; }
modint operator-=(modint& a, modint b) { a.n -= b.n; if (a.n < 0)a.n += mod; return a; }
modint operator*=(modint& a, modint b) { a.n = ((ll)a.n * b.n) % mod; return a; }
modint operator+(modint a, modint b) { return a += b; }
modint operator-(modint a, modint b) { return a -= b; }
modint operator*(modint a, modint b) { return a *= b; }
modint operator^(modint a, ll n) {
	if (n == 0)return modint(1);
	modint res = (a * a) ^ (n / 2);
	if (n % 2)res = res * a;
	return res;
}

ll inv(ll a, ll p) {
	return (a == 1 ? 1 : (1 - p * inv(p % a, a)) / a + p);
}
modint operator/(modint a, modint b) { return a * modint(inv(b, mod)); }
modint operator/=(modint& a, modint b) { a = a / b; return a; }
const int max_n = 1 << 19;
modint fact[max_n], factinv[max_n];
void init_f() {
	fact[0] = modint(1);
	for (int i = 0; i < max_n - 1; i++) {
		fact[i + 1] = fact[i] * modint(i + 1);
	}
	factinv[max_n - 1] = modint(1) / fact[max_n - 1];
	for (int i = max_n - 2; i >= 0; i--) {
		factinv[i] = factinv[i + 1] * modint(i + 1);
	}
}
modint comb(int a, int b) {
	if (a < 0 || b < 0 || a < b)return 0;
	return fact[a] * factinv[b] * factinv[a - b];
}
modint combP(int a, int b) {
	if (a < 0 || b < 0 || a < b)return 0;
	return fact[a] * factinv[a - b];
}

int gcd(int a, int b) {
	if (a < b)swap(a, b);
	while (b) {
		int r = a % b; a = b; b = r;
	}
	return a;
}



void solve() {
	int n, m; cin >> n >> m;
	vector<int> l(n), r(n);
	rep(i, n)cin >> l[i] >> r[i];
	vector<int> a(m), b(m);
	vector<vector<int>> G(n);
	vector<int> ids;
	rep(i, m) {
		cin >> a[i] >> b[i]; a[i]--; b[i]--;
		G[a[i]].push_back(b[i]);
		G[b[i]].push_back(a[i]);
		ids.push_back(a[i]);
		ids.push_back(b[i]);
	}
	sort(all(ids));
	ids.erase(unique(all(ids)),ids.end());
	vector<vector<int>> vid;
	vector<bool> used(n);
	rep(i, ids.size()) {
		int id = ids[i];
		if (used[id])continue;
		vector<int> cur;
		queue<int> q;
		q.push(id); used[id] = true;
		while (!q.empty()) {
			int v = q.front(); q.pop();
			cur.push_back(v);
			for (int to : G[v])if (!used[to]) {
				used[to] = true;
				q.push(to);
			}
		}
		vid.push_back(cur);
	}
	vector<int> trans(n,-1);
	rep(i, vid.size()) {
		rep(j, vid[i].size()) {
			trans[vid[i][j]] = j;
		}
	}
	vector<vector<vector<modint>>> memo(vid.size());
	rep(i, vid.size()) {
		int len = vid[i].size();
		vector<bool> can(1 << len);
		can[0] = true;
		vector<vector<bool>> exi(len, vector<bool>(len));
		for (int id : vid[i]) {
			for (int to : G[id]) {
				exi[trans[id]][trans[to]] = true;
			}
		}
		for (int j = 1; j < (1 << len); j++) {
			vector<int> cc;
			rep(k, len)if (j & (1 << k))cc.push_back(k);
			int nj = j ^ (1 << cc[0]);
			if (!can[nj]) {
				can[j] = false; continue;
			}
			can[j] = true;
			for (int k = 1; k < cc.size(); k++) {
				if (exi[cc[0]][cc[k]])can[j] = false;
			}
		}
		memo[i].resize(1 << len);
		rep(j, (1 << len)) {
			int cnt = 0; rep(k, len)if (j & (1 << k))cnt++;
			memo[i][j].resize(cnt + 1);
			if (can[j])memo[i][j][cnt] = 1;
		}
		rep(j, len)rep(k, (1 << len))if (k & (1 << j))rep(l, memo[i][k^(1<<j)].size()) {
			memo[i][k][l] += memo[i][k ^ (1 << j)][l];
		}
	}
	vector<int> ads(n + 1);
	vector<int> decs(n + 1);
	rep(i, n) {
		if (trans[i] < 0) {
			ads[l[i]]++;
			decs[r[i]]++;
		}
	}
	int cnt = 0;
	modint ans = 0;
	for (int c = 1; c <= n; c++) {
		cnt += ads[c];
		vector<modint> dp = { 1 };
		rep(i, vid.size()) {
			int s = 0;
			rep(j, vid[i].size()) {
				int id = vid[i][j];
				if (l[id] <= c && c <= r[id])s |= (1 << j);
			}
			vector<modint>& vdp = memo[i][s];
			vector<modint> ndp(dp.size() + vdp.size() - 1);
			rep(j, dp.size())rep(k, vdp.size()) {
				ndp[j + k] += dp[j] * vdp[k];
			}
			swap(dp, ndp);
		}
		modint csum = 0;
		rep(j, dp.size()) {
			if (j > c)continue;
			int r = c - j;
			csum += comb(cnt,r) * dp[j];
		}
		ans += csum;
		//cout << c << " " << cnt<<" "<<csum << "\n";
		cnt -= decs[c];

	}
	cout << ans << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	init_f();
	//init();
	//expr();
	//int t; cin >> t; rep(i, t)
	solve();
	return 0;
}