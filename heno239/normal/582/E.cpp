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
typedef double ld;
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

using ar = vector<modint>;
ar or_conv(ar a, ar b) {
	/*cout << "a\n";
	rep(i, a.size())if (a[i] != (modint)0)cout << i << " " << a[i] << "\n";
	cout << "b\n";
	rep(i, b.size())if (b[i] != (modint)0)cout << i << " " << b[i] << "\n";*/

	
	rep(j, 16)rep(i, (1 << 16)) {
		if (i & (1 << j)) {
			a[i] += a[i ^ (1 << j)];
			b[i] += b[i ^ (1 << j)];
		}
	}
	ar res(1 << 16);
	rep(i, 1 << 16)res[i] = a[i] * b[i];
	rep(j, 16)rep(i, 1 << 16) {
		if (i & (1 << j)) {
			res[i] -= res[i^(1<<j)];
		}
	}

	//cout << "res\n";
	//rep(i, res.size())if (res[i] != (modint)0)cout << i << " " << res[i] << "\n";
	return res;

}
ar and_conv(ar a, ar b) {
	rep(j, (1 << 15)) {
		swap(a[j], a[(1 << 16) - 1 - j]);
		swap(b[j], b[(1 << 16) - 1 - j]);
	}
	ar res = or_conv(a, b);
	rep(j, (1 << 15)) {
		swap(res[j], res[(1 << 16) - 1 - j]);
	}
	return res;
}

ar expr(string& s, int& i) {
	if (s[i] == '(') {
		i++;
		ar res = expr(s, i);
		//assert(s[i]==')'
		i++;
		while (i<s.size()&&(s[i]=='?'||s[i]=='|'||s[i]=='&')) {
			char ope = s[i]; i++;
			//assert(s[i]=='(';
			i++;
			ar nex = expr(s, i);
			//assert(s[i]==')'
			i++;
			ar cop(1 << 16);
			if (ope == '|' || ope == '?') {
				ar z = or_conv(res, nex);
				rep(j, z.size())cop[j] += z[j];
			}
			if (ope == '&' || ope == '?') {
				ar z = and_conv(res, nex);
				rep(j, z.size())cop[j] += z[j];
			}
			swap(cop, res);
		}
		return res;
	}
	else {
		ar res(1 << 16);
		rep(j, 4) {
			if (s[i] == 'A' + j || s[i] == '?'){
				int t = 0;
				rep(k, 16) {
					if (k & (1 << j))t |= (1 << k);
				}
				res[t]+=1;
			}
		}
		rep(j, 4) {
			if (s[i] == 'a' + j || s[i] == '?') {
				int t = 0;
				rep(k, 16) {
					if (k & (1 << j)) {

					}
					else {
						t |= (1 << k);
					}
				}
				res[t] += 1;
			}
		}
		i++;
		return res;
	}
}
void solve() {
	string s; cin >> s; int i = 0;
	ar a = expr(s, i);
	int n; cin >> n;
	vector<P> v(n);
	rep(i, n) {
		int in[5]; rep(j, 5)cin >> in[j];
		int x = 0;
		rep(j, 4) {
			if (in[j])x |= (1 << j);
		}
		v[i] = { x,in[4] };
	}
	modint ans = 0;
	rep(i, (1 << 16)) {
		bool valid = true;
		rep(j, n) {
			bool b = (i & (1 << v[j].first));
			bool c = v[j].second;
			if (b != c)valid = false;
		}
		if (valid) {
			//if (a[i] != (modint)0)cout << i << " " << a[i] << "\n";
			ans += a[i];
		}
	}
	cout << ans << "\n";
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