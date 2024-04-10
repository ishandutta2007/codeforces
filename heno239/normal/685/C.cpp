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
#include<complex>
#include<numeric>
#include<array>
using namespace std;

//#define int long long
typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
constexpr ll mod = 1000500007;
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

ll mod_pow(ll x, ll n, ll m) {
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

const int max_n = 1 << 18;
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

ll xsup = 1000000000000000000;
void solve() {
	int n; cin >> n;
	vector<ll> x(n), y(n), z(n);
	rep(i, n) {
		cin >> x[i] >> y[i] >> z[i];
	}
	ll sup = 3*INF;
	ll le = -1, ri = sup;
	ll ansx, ansy, ansz;

	vector<LP> v;
	while (ri - le > 1) {
		ll d = (le + ri) / 2;
		ll la = -2*sup, ra = 2*sup, lb = -2*sup, rb = 2*sup, lc = -2*sup, rc = 2*sup;
		ll ls = -2*sup, rs = 2*sup;
		rep(i, n) {
			ll a = x[i] + y[i] - z[i];
			ll b = x[i] - y[i] + z[i];
			ll c = -x[i] + y[i] + z[i];
			ll s = a + b + c;
			la = max(la, a-d); ra = min(ra, a+d);
			lb = max(lb, b-d); rb = min(rb, b+d);
			lc = max(lc, c-d); rc = min(rc, c+d);
			ls = max(ls, s-d); rs = min(rs, s+d);
		}
		if (la > ra || lb > rb || lc > rc||ls>rs) {
			le = d; continue;
		}
		bool valid = false;
		rep(i, 2) {
			ll a = la, b = lb, c = lc;
			if (i == 0) {
				if (a % 2!=0)a++;
				if (b % 2!=0)b++;
				if (c % 2!=0)c++;
			}
			else {
				if (a % 2 == 0)a++;
				if (b % 2 == 0)b++;
				if (c % 2 == 0)c++;
			}
			if (a > ra || b > rb || c > rc || a + b + c > rs)continue;
			ll da = (ra - a) / 2*2;
			ll db = (rb - b) / 2*2;
			ll dc = (rc - c) / 2 * 2;
			ll dif = ls - (a+b+c);
			if (dif % 2)dif++;
			if (dif > 0) {
				v.clear();
				v.push_back({ a,0 });
				v.push_back({ b,1 });
				v.push_back({ c,2 });
				sort(all(v));
				for (LP p : v) {
					int id = p.second;
					if (id == 0) {
						ll z = min(da, dif);
						a += z; dif -= z;
					}
					else if (id == 1) {
						ll z = min(db, dif);
						b += z; dif -= z;
					}
					else {
						ll z = min(dc, dif);
						c += z; dif -= z;
					}
				}
			}
			if (a<=ra&&a>=la&&b<=rb&&b>=lb&&c<=rc&&c>=lc&&a+b+c<=rs&&a+b+c>=ls) {
				valid = true;
				ansx = (a + b) / 2;
				ansy = (a + c) / 2;
				ansz = (b + c) / 2;
				break;
			}
		}
		if (valid) {
			ri = d;
		}
		else le = d;
	}
	ll ma = -1;
	rep(i, n) {
		ll sum = abs(ansx - x[i]) + abs(ansy - y[i]) + abs(ansz - z[i]);
		ma = max(ma, sum);
	}
	//assert(ma == ri);
	//cout << ri << "\n";
	cout << ansx << " " << ansy << " " << ansz << "\n";
	/*rep(i, n) {
		ll sum = abs(ansx - x[i]) + abs(ansy - y[i]) + abs(ansz - z[i]);
		cout << sum << "\n";
	}*/
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(15);
	//init_f();
	//expr();
	int t; cin >> t; rep(i, t)
	solve();
	return 0;
}