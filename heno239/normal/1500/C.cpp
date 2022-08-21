#pragma GCC optimize("Ofast")
//#pragma GCC target ("sse4")

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
constexpr ll mod = 1000000007;
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
const int max_n = 1 << 2;
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

vector<int> ids[1500];
vector<int> cs[1500];
void solve() {
	int n, m; cin >> n >> m;
	vector<vector<int>> a(n, vector<int>(m));
	vector<vector<int>> b(n, vector<int>(m));
	rep(i, n)rep(j, m)cin >> a[i][j];
	rep(i, n)rep(j, m)cin >> b[i][j];

	vector<int> cnt(m);
	rep(j, m) {
		rep1(i, n - 1) {
			if (b[i - 1][j] > b[i][j]) {
				ids[i].push_back(j);
				cnt[j]++;
			}
			if (b[i - 1][j] < b[i][j]) {
				cs[j].push_back(i);
			}
		}
	}
	queue<int> q;
	vector<int> ans;
	rep(j, m) {
		if (cnt[j] == 0) {
			q.push(j);
			//cout << "yes " << j << "\n";
		}
	}
	vector<bool> exi(n);
	while (!q.empty()) {
		int id = q.front(); q.pop();
		//cout << "wow " << id << "\n";
		ans.push_back(id);
		for (int x : cs[id]) {
			if (!exi[x]) {
				exi[x] = true;
				for (int to : ids[x]) {
					cnt[to]--;
					if (cnt[to] == 0)q.push(to);
				}
			}
		}
	}
	vector<pair<vector<int>,int>> va,vb;
	rep(i, n) {
		va.push_back({ a[i],i });
		vb.push_back({ b[i],i });
	}
	sort(all(va));
	sort(all(vb));
	vector<int> trans(n);
	rep(i, n) {
		if (va[i].first != vb[i].first) {
			cout << -1 << "\n"; return;
		}
		trans[vb[i].second] = va[i].second;
	}
	//cout << "hello\n";
	int le = 0;
	rep1(i, n-1) {
		if (exi[i]) {
			//[le,i)
			vector<int> ids;
			for (int j = le; j < i; j++) {
				ids.push_back(trans[j]);
			}
			bool valid = true;
			rep(j, ids.size() - 1)if (ids[j] > ids[j + 1])valid = false;
			if (!valid) {
				cout << -1 << "\n"; return;
			}
			le = i;
		}
	}
	//[le,n)
	vector<int> ids;
	for (int j = le; j < n; j++) {
		ids.push_back(trans[j]);
	}
	bool valid = true;
	rep(j, ids.size() - 1)if (ids[j] > ids[j + 1])valid = false;
	if (!valid) {
		cout << -1 << "\n"; return;
	}
	reverse(all(ans));
	cout << ans.size() << "\n";
	rep(i, ans.size()) {
		if (i > 0)cout << " ";
		cout << ans[i] + 1;
	}
	cout << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init_f();
	//init();
	//expr();
	//int t; cin >> t; rep(i, t)
		solve();
	return 0;
}