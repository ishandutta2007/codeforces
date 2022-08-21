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

ll gcd(ll a, ll b) {
	a = abs(a); b = abs(b);
	if (a < b)swap(a, b);
	while (b) {
		ll r = a % b; a = b; b = r;
	}
	return a;
}
void solve() {
	string s; cin >> s;
	int n = s.size();
	vector<int> loc[2];
	rep(i, n) {
		if (s[i] == 'L')loc[0].push_back(i);
		else loc[1].push_back(i);
	}
	int mi = mod; vector<int> ans;
	rep(c, 2) {
		if (loc[c].size() < loc[c ^ 1].size())continue;
		set<int> st[2];
		rep(i, n) {
			if (s[i] == 'L')st[0].insert(i);
			else st[1].insert(i);
		}
		vector<int> cur;
		auto nex = [&](int id, int l)->int {
			st[id].insert(l);
			auto itr = st[id].find(l);
			itr++;
			st[id].erase(l);
			if (itr == st[id].end())return n;
			else return *itr;
		};
		int id = c;
		while (cur.size() < n) {
			int ad = 0;
			int curloc = -1;
			while (curloc < n) {
				int nc = nex(id, curloc);
				if (nc == n) {
					break;
				}
				cur.push_back(nc);
				ad++;
				st[id].erase(nc);
				curloc = nc;
				id ^= 1;
			}
			int mi = mod;
			rep(j, 2)if (st[j].size())mi = min(mi, *st[j].begin());
			if (ad>1&&mi<mod&&s[mi] == s[cur.back()]) {
				if (s[cur.back()] == 'L')st[0].insert(cur.back());
				else st[1].insert(cur.back());
				cur.pop_back();
				id ^= 1;
			}
			//cout << cur.size() <<" "<<ad<< "\n";
		}
		int num = 0;
		rep(i, n - 1)if (cur[i] > cur[i + 1])num++;
		if (num < mi) {
			mi = num; swap(ans, cur);
		}
	}

	cout << mi << "\n";
	rep(i, n) {
		if (i > 0)cout << " ";
		cout << ans[i] + 1;
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