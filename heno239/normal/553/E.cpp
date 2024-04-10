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
const int max_n = 1 << 17;
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


LDP operator*(const LDP& a, const LDP& b) {
	return LDP{ a.first * b.first - a.second * b.second , a.first * b.second + a.second * b.first };
}
LDP operator+(const LDP& a, const LDP& b) {
	return LDP{ a.first + b.first,a.second + b.second };
}
LDP operator-(const LDP& a, const LDP& b) {
	return LDP{ a.first - b.first,a.second - b.second };
}
//
//eps=0.01
typedef vector<LDP> poly;
poly dft(poly f, bool inverse = false) {
	int n = f.size(); int i, j, k;
	//bit
	for (i = 0, j = 1; j < n - 1; j++) {
		for (k = n >> 1; k > (i ^= k); k >>= 1);
		if (i > j)swap(f[i], f[j]);
	}
	for (int m = 2; m <= n; m *= 2) {
		LDP zeta = { cos(2 * pi / (ld)m), sin(2 * pi / (ld)m) };
		if (inverse) {
			zeta = { cos(2 * pi * (m - 1) / (ld)m), sin(2 * pi * (m - 1) / (ld)m) };
		}
		for (i = 0; i < n; i += m) {
			LDP powzeta = { 1,0 };
			for (k = i; k < i + m / 2; k++) {
				LDP t1 = f[k], t2 = powzeta * f[k + m / 2];
				f[k] = t1 + t2; f[k + m / 2] = t1 - t2;
				powzeta = powzeta * zeta;
			}
		}
	}
	if (inverse) {
		for (i = 0; i < n; i++) {
			f[i].first /= (ld)n;
			f[i].second /= (ld)n;
		}
	}
	return f;
}
poly multiply(poly g, poly h) {
	int n = 1; int sz = g.size() + h.size();
	while (n <= sz)n *= 2;
	while (g.size() < n) {
		g.push_back({ 0,0 });
	}
	while (h.size() < n) {
		h.push_back({ 0,0 });
	}
	poly gg = dft(g);
	poly hh = dft(h);
	poly ff;
	rep(i, n) {
		ff.push_back(gg[i] * hh[i]);
	}
	return dft(ff, true);
}
vector<ld> multiply(vector<ld>& a, vector<ld>& b) {
	poly p(a.size()), q(b.size());
	rep(i, a.size())p[i] = { a[i],0 };
	rep(i, b.size())q[i] = { b[i],0 };
	poly r = multiply(p, q);
	vector<ld> res(r.size());
	rep(i, r.size())res[i] = r[i].first;
	return res;
}


struct edge {
	int to;
	int cost;
};

void solve() {
	int n, m, t, x; cin >> n >> m >> t >> x;
	vector<int> a(m), b(m), c(m);
	vector<vector<ld>> tc(m);
	vector<vector<edge>> rG(n);
	rep(i, m) {
		cin >> a[i] >> b[i] >> c[i]; a[i]--; b[i]--;
		rG[b[i]].push_back({ a[i],c[i] });

		tc[i].resize(t + 1);
		rep1(j, t) {
			int x; cin >> x; tc[i][j] = x / (ld)100000;
		}
	}
	vector<int> dist(n, mod);
	dist[n - 1] = x;
	priority_queue<P, vector<P>, greater<P>> q;
	q.push({ x,n - 1 });
	while (!q.empty()) {
		P p = q.top(); q.pop();
		int id = p.second;
		if (dist[id] < p.first)continue;
		for (edge e : rG[id]) {
			int nd = e.cost + dist[id];
			if (dist[e.to] > nd) {
				dist[e.to] = nd; q.push({ nd,e.to });
			}
		}
	}
	//rep(i, n)cout << "? " << dist[i] << "\n";
	vector<vector<ld>> rtc(m);
	rep(i, m) {
		rtc[i].resize(t + 2, 0);
		for (int j = t; j > 0; j--) {
			rtc[i][j] = rtc[i][j + 1] + tc[i][j];
		}
	}
	vector<vector<ld>> memo(m, vector<ld>(t + 1));
	vector<vector<ld>> ex(n, vector<ld>(t + 1));
	function<void(int, int)> yaru = [&](int l, int r) {
		if (r - l == 1) {
			rep(i, n) {
				ex[i][l] = INF;
				if (i == n - 1)ex[i][l] = 0;
			}
			rep(i, m) {
				ld val = memo[i][l];
				val += rtc[i][t + 1 - l] * dist[b[i]];
				ex[a[i]][l] = min(ex[a[i]][l], val+c[i]);
			}

			return;
		}
		int mid = (l + r) / 2;
		yaru(mid, r);


		int sz = r - l;
		rep(i, m) {
			vector<ld> coef(sz);
			rep(j, sz) {
				if(j+1<tc[i].size())coef[sz - 1 - j] = tc[i][j + 1];
			}
			vector<ld> pro(r - mid);
			rep(j, r - mid)pro[j] = ex[b[i]][mid + j];
			vector<ld> r = multiply(coef, pro);
			rep(j, mid - l) {
				memo[i][mid - 1 - j] += r[sz - 1 - j];
			}
		}

		//cout << l << " " << r << " " << memo[0][0]<<" "<<ex[1][3] << "\n";

		yaru(l, mid);
	};

	yaru(0, t+1);

	/*rep(j, t + 1) {
		cout << "start " << j << "\n";
		rep(i, n)cout << ex[i][j] << "\n";
	}*/
	//cout << "why " << memo[0][0] << "\n";
	cout << ex[0][0] << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(15);
	//init_f();
	//init();
	//expr();
	//int t; cin >> t; rep(i, t)
	solve();
	return 0;
}