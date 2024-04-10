//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
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
#include<chrono>
using namespace std;

//#define int long long
typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 998244353;
const ll INF = mod * mod;
typedef pair<int, int>P;

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
const ld eps = 1e-8;
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
const int max_n = 1 << 10;
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

int trans(char c) {
	if ('a' <= c && c <= 'z')return c - 'a';
	else {
		return c - 'A' + 26;
	}
}
void solve() {
	int n; cin >> n;
	vector<string> s(n);
	rep(i, n)cin >> s[i];
	vector<vector<vector<int>>> nex(n);
	rep(i, n) {
		nex[i].resize(s[i].size()+1);
		rep(j, s[i].size() + 1)nex[i][j].resize(52);
		rep(k, 52)nex[i][s[i].size()][k] = s[i].size();
		per(j, s[i].size()) {
			rep(k, 52) {
				nex[i][j][k] = nex[i][j + 1][k];
			}
			nex[i][j][trans(s[i][j])] = j;
		}
	}
	vector<vector<int>> vs;
	rep(alf, 52) {
		vector<vector<int>> vcur(n);
		rep(i, n)rep(j, s[i].size())if (trans(s[i][j]) == alf) {
			vcur[i].push_back(j);
		}
		vector<int> cur;
		function<void(int)>dfs = [&](int dep) {
			if (dep == n) {
				vs.push_back(cur);
			}
			else {
				for (int id : vcur[dep]) {
					cur.push_back(id);
					dfs(dep + 1);
					cur.pop_back();
				}
			}
		};
		dfs(0);
	}
	sort(all(vs));
	if (vs.empty()) {
		cout << 0 << "\n";
		cout << "" << "\n"; return;
	}
	vector<int> dp(vs.size());
	vector<int> pre(vs.size(), -1);
	vector<char> cs(vs.size());
	rep(i, vs.size()) {
		char c = s[0][vs[i][0]];
		cs[i] = c;
		dp[i] += 1;
		vector<int> ne(n);
		rep(alf, 52) {
			bool valid = true;
			rep(j, n) {
				ne[j] = nex[j][vs[i][j] + 1][alf];
				if (ne[j] == s[j].size())valid = false;
			}
			if (valid) {
				int loc = lower_bound(all(vs), ne) - vs.begin();
				if (dp[loc] < dp[i]) {
					dp[loc] = dp[i];
					pre[loc] = i;
				}
			}
		}
	}
	int ma = -1;
	int chk = -1;
	rep(i, vs.size()) {
		if (dp[i] > ma) {
			ma=dp[i]; chk = i;
		}
	}
	string ans;
	int cur = chk;
	while (cur >= 0) {
		ans.push_back(cs[cur]);
		cur = pre[cur];
	}
	reverse(all(ans));
	cout << ans.size() << "\n";
	cout << ans << "\n";
}



signed main() {
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout << fixed << setprecision(10);
	//init_f();
	//init();
	int t; cin >> t; rep(i, t)
	solve();
	return 0;
}