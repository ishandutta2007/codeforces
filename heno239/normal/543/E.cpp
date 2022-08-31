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

const int b = 300;
void solve() {
	int n, m; cin >> n >> m;
	vector<int> a(n);
	rep(i, n)cin >> a[i];
	vector<int> l(n), r(n);
	vector<int> xs;
	vector<P> vs;
	rep(i, n) {
		vs.push_back({ a[i],i });
	}
	sort(all(vs));
	rep(i, vs.size()) {
		xs.push_back(vs[i].first);
		int le = vs[i].second - m + 1;
		int ri = vs[i].second;
		le = max(le, 0);
		ri = min(ri, n - m);
		l[i] = le, r[i] = ri;
	}
	int q; cin >> q;
	vector<int> ql(q), qr(q), x(q);
	rep(i, q) {
		cin >> ql[i] >> qr[i] >> x[i];
		ql[i]--; qr[i]--;
	}
	int d = (n+b - 1) / b;
	int dq = (q + b - 1) / b;
	vector<vector<int>> ads;
	vector<vector<int>> vals;
	vector<vector<P>> updval(n);
	vector<int> ad(d);
	vector<int> val(d);
	ads.push_back(ad);
	vals.push_back(val);
	vector<int> cur(n);
	rep(i, n) {
		int bl = l[i] / b;
		int br = r[i] / b;
		if (bl == br) {
			for (int j = l[i]; j <= r[i]; j++) {
				cur[j]++;
			}
			val[bl] = mod;
			for (int j = bl * b; j < min(bl * b + b, n); j++) {
				val[bl] = min(val[bl], cur[j]);
			}
			updval[i].push_back({ bl,val[bl] });
		}
		else {
			for (int j = bl + 1; j< br; j++) {
				ad[j]++;
			}
			for (int j = l[i]; j < min(n, bl * b + b); j++) {
				cur[j]++;
			}
			val[bl] = mod;
			for (int j = bl * b; j < min(n, bl * b + b); j++) {
				val[bl] = min(val[bl], cur[j]);
			}
			updval[i].push_back({ bl,val[bl] });
			for (int j = br * b; j <= r[i]; j++) {
				cur[j]++;
			}
			val[br] = mod;
			for (int j = br * b; j < min(n, br * b + b); j++) {
				val[br] = min(val[br], cur[j]);
			}
			updval[i].push_back({ br,val[br] });
		}
		if ((i + 1) % b == 0) {
			ads.push_back(ad);
			vals.push_back(val);
		}
	}
	vector<vector<int>> adnode(n), decnode(n+1);
	rep(i, n) {
		int rl = l[i] % b;
		adnode[l[i]].push_back(i);
		decnode[r[i] + 1].push_back(i);
	}
	vector<vector<int>> levals;
	vector<int> leval(d);
	levals.push_back(leval);
	for (int i = 0; i < n; i++) {
		rep(j, d) {
			if (l[i] <= j * b && j * b <= r[i])leval[j]++;
		}
		if ((i + 1) % b == 0) {
			levals.push_back(leval);
		}
	}
	vector<int> ans(q, mod);
	vector<int> imos(d + 1);
	vector<int> memo(b);
	int las = 0;
	rep(id, q) {
		x[id] ^= las;
		int num = lower_bound(all(xs), x[id]) - xs.begin();
		//cout << "? " << num << "\n";
		int bid = num / b;
		rep(j, d) {
			ad[j] = ads[bid][j];
			val[j] = vals[bid][j];
		}
		fill(all(imos), 0);
		for (int i = bid * b; i < num; i++) {
			for (P p : updval[i]) {
				val[p.first] = p.second;
			}
			int bl = l[i] / b, br = r[i] / b;
			if (bl != br) {
				imos[bl + 1]++;
				imos[br]--;
			}
		}
		rep(j, d) {
			imos[j + 1] += imos[j];
			ad[j] += imos[j];
		}

		int qbl = ql[id] / b;
		int qbr = qr[id] / b;
		if (qbl == qbr) {
			fill(all(memo), 0);
			memo[0] = levals[bid][qbl];
			for (int i = bid * b; i < num; i++)if (l[i] <= qbl * b && qbl * b <= r[i])memo[0]++;
			for (int i = 1; i < b; i++) {
				int loc = qbl * b + i;
				if (loc >= n)continue;
				memo[i] = memo[i - 1];
				memo[i] += lower_bound(all(adnode[loc]), num) - adnode[loc].begin();
				memo[i] -= lower_bound(all(decnode[loc]), num) - decnode[loc].begin();
			}
			for (int j = ql[id] % b; j <= qr[id] % b; j++)ans[id] = min(ans[id], memo[j]);
		}
		else {
			for (int j = qbl + 1; j < qbr; j++) {
				ans[id] = min(ans[id], val[j] + ad[j]);
			}
			fill(all(memo), 0);
			memo[0] = levals[bid][qbl];
			for (int i = bid * b; i < num; i++)if (l[i] <= qbl * b && qbl * b <= r[i])memo[0]++;
			for (int i = 1; i < b; i++) {
				int loc = qbl * b + i;
				if (loc >= n)continue;
				memo[i] = memo[i - 1];
				memo[i] += lower_bound(all(adnode[loc]), num) - adnode[loc].begin();
				memo[i] -= lower_bound(all(decnode[loc]), num) - decnode[loc].begin();
			}
			for (int j = ql[id] % b; j <b&&qbl*b+j<n; j++)ans[id] = min(ans[id], memo[j]);

		    fill(all(memo), 0);
			memo[0] = levals[bid][qbr];
			for (int i = bid * b; i < num; i++)if (l[i] <= qbr * b && qbr * b <= r[i])memo[0]++;
			for (int i = 1; i < b; i++) {
				int loc = qbr * b + i;
				if (loc >= n)continue;
				memo[i] = memo[i - 1];
				memo[i] += lower_bound(all(adnode[loc]), num) - adnode[loc].begin();
				memo[i] -= lower_bound(all(decnode[loc]), num) - decnode[loc].begin();
			}
			for (int j = 0; j <= qr[id] % b; j++)ans[id] = min(ans[id], memo[j]);
		}
		las = ans[id];
	}
	rep(i, q)cout << ans[i] << "\n";
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