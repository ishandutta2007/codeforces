#pragma GCC optimize("Ofast")
#pragma GCC target ("sse4")

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
typedef double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-12;
const ld pi = acosl(-1.0);

ll mod_pow(ll x, ll n, ll m = mod) {
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


vector<P> vs[100005];
void solve() {
	int n; cin >> n;
	vector<int> a(n);
	rep(i, n)cin >> a[i];
	int m; cin >> m;
	vector<int> b(m);
	rep(i, m)cin >> b[i];
	vector<int> vb = b;
	sort(all(vb));
	vb.erase(unique(all(vb)), vb.end());
	rep1(i, n) {
		vs[i].push_back({ mod,-1 });
	}
	vs[0].push_back({ 0,-1 });
	rep(i, n) {
		if (a[i] >= 0) {
			int le = -1, ri = n + 1;
			while (ri - le > 1) {
				int mid = (le + ri) / 2;
				if (vs[mid].back().first < a[i]) {
					le = mid;
				}
				else {
					ri = mid;
				}
			}
			if (vs[le + 1].back().first > a[i]) {
				vs[le + 1].push_back({ a[i],i });
			}
		}
		else {
			int loc = 0;
			rep(j, n + 1) {
				int val = vs[j].back().first;
				if (vs[j].back().second == i) {
					val = vs[j][vs[j].size() - 2].first;
				}
				while (loc < vb.size() && vb[loc] <= val)loc++;
				if (loc < vb.size()) {
					if (vb[loc] < vs[j + 1].back().first) {
						vs[j + 1].push_back({ vb[loc],i });
					}
				}
				else break;
			}
		}
	}
	int cur = -1;
	vector<int> ans(n,-1);
	rep(i, n + 1) {
		if (vs[i].back().first < mod) {
			cur = i;
		}
	}
	int tm = vs[cur].back().second;
	ans[tm] = vs[cur].back().first;
	//cout << cur << "\n";
	for (int j = cur-1; j > 0; j--) {
		//cout << j << " " << tm << "\n";
		int le = -1, ri = vs[j].size();
		while (ri - le > 1) {
			int mid = (le + ri) / 2;
			if (vs[j][mid].second < tm) {
				le = mid;
			}
			else {
				ri = mid;
			}
		}
		ans[vs[j][le].second] = vs[j][le].first;
		tm = vs[j][le].second;
	}
	multiset<int> st;
	rep(i, m)st.insert(b[i]);
	rep(i, n)if (ans[i] >= 0)if (a[i] < 0) {
		st.erase(st.find(ans[i]));
	}
	rep(i, n) {
		if (ans[i] < 0) {
			if (a[i] >= 0)ans[i] = a[i];
			else {
				ans[i] = *st.begin(); st.erase(st.begin());
			}
		}
	}
	rep(i, n) {
		if (i > 0)cout << " ";
		cout << ans[i];
	}
	cout << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(15);
	//init_f();
	//init();
	//expr();
	//int t; cin >> t; rep(i, t)
	solve();
	return 0;
}