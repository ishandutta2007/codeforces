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
typedef double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-12;
const ld pi = acosl(-1.0);

ll mod_pow(ll x, ll n, ll m = mod) {
	if (n < 0) {
		ll res = mod_pow(x, -n, m);
		return mod_pow(res, m - 2, m);
	}
	x %= m;
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


bool used[1 << 20];
void solve() {
	int n, k; cin >> n >> k;
	string s; cin >> s;
	rep(i, s.size())s[i] = '0' + '1' - s[i];
	if (k <= 20) {
		vector<int> vs;
		rep(i, n - k + 1) {
			int x = 0;
			rep(j, k) {
				if (s[i + k - 1 - j] == '1')x |= (1 << j);
			}
			vs.push_back(x);
		}
		sort(all(vs));
		vs.erase(unique(all(vs)), vs.end());
		int ans = vs.size();
		rep(i, vs.size())if (vs[i] != i) {
			ans = i; break;
		}
		if (ans == (1 << k)) {
			cout << "NO\n";
		}
		else {
			string out; out.resize(k,'0');
			rep(i, k)if (ans & (1 << i))out[k-1-i] = '1';
			cout << "YES\n";
			cout << out << "\n";
		}
	}
	else {
		vector<int> memo;
		vector<int> cnt(n + 1);
		rep(i, n) {
			cnt[i + 1] = cnt[i] + (s[i] == '1');
		}
		rep(i, n - k + 1) {
			if (cnt[i] == cnt[i + k - 20]) {
				int x = 0;
				rep(j, 20) {
					if (s[i + k-1-j] == '1') {
						x |= (1 << j);
					}
				}
				memo.push_back(x);
			}
		}
		sort(all(memo));
		memo.erase(unique(all(memo)), memo.end());
		int ans = memo.size();
		rep(i, memo.size())if (memo[i] != i) {
			ans = i; break;
		}
		string out;
		rep(i, k - 20)out.push_back('0');
		string ad; ad.resize(20,'0');
		rep(j, 20)if (ans & (1 << j))ad[19 - j] = '1';
		out += ad;
		cout << "YES\n";
		cout << out << "\n";
	}
}


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(15);
	//init_f();
	//cout << t << " " << m << " " << m2 << "\n";
	//init();
	//expr();
	int t; cin >> t; rep(i, t)
	solve();
	return 0;
}