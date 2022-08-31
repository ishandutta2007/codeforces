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
struct SegT {
private:
	int sz; vector<int> node;
	const int init_c = 0;
public:
	SegT(vector<int> v) {
		int n = v.size();
		sz = 1;
		while (sz < n)sz *= 2;
		node.resize(2 * sz - 1, init_c);
		rep(i, n) {
			node[i + sz - 1] = v[i];
		}
		per(i, sz - 1) {
			node[i] = f(node[2 * i + 1], node[2 * i + 2]);
		}
	}
	SegT(int n) {
		sz = 1;
		while (sz < n)sz *= 2;
		node.resize(2 * sz - 1, init_c);
	}
	int f(int a, int b) {
		return max(a, b);
	}
	void update(int k, int a) {
		k += sz - 1;
		node[k] = a;
		while (k > 0) {
			k = (k - 1) / 2;
			node[k] = f(node[k * 2 + 1], node[k * 2 + 2]);
		}
	}
	int query(int a, int b, int k = 0, int l = 0, int r = -1) {
		if (r < 0)r = sz;
		if (r <= a || b <= l)return init_c;
		else if (a <= l && r <= b)return node[k];
		else {
			int vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
			int vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
			return f(vl, vr);
		}
	}
};


void solve() {
	int n, q; cin >> n >> q;
	vector<int> h(n);
	vector<int> vx;
	rep(i, n) {
		cin >> h[i]; vx.push_back(h[i]);
	}
	vector<int> a(q), b(q);
	rep(i, q) {
		cin >> a[i] >> b[i]; a[i]--;
	}
	vector<int> score(q, 1);

	sort(all(vx));
	vx.erase(unique(all(vx)), vx.end());
	rep(i, n) {
		h[i] = lower_bound(all(vx), h[i]) - vx.begin();
	}
	SegT st(n);
	vector<vector<P>> qs(n);
	rep(i, q) {
		qs[a[i]].push_back({ i,b[i]});
	}

	vector<int> vals(n);
	rep(i, n) {
		for (P p : qs[i]) {
			int id = p.first, y = p.second;
			y = lower_bound(all(vx), y) - vx.begin();
			score[id] += st.query(0, y);
		}
		int val = st.query(0, h[i]) + 1;
		vals[i] = val;
		st.update(h[i], val);
	}

	SegT stri(n);
	per(i, n) {
		for (P p : qs[i]) {
			int id = p.first, y = p.second;
			y = upper_bound(all(vx), y) - vx.begin();
			score[id] += stri.query(y, vx.size());
		}
		int val = stri.query(h[i] + 1, vx.size()) + 1;
		stri.update(h[i], val);
	}

	vector<int> cnt(n + 1);
	int ma = st.query(0, vx.size());
	vector<vector<int>> loc(n+1);
	loc[0].push_back(-1);
	rep(i, n) {
		loc[vals[i]].push_back(i);
	}
	vector<P> v;
	vector<int> mas;
	for (int id : loc[ma]) {
		v.push_back({ h[id],id });
		cnt[id + 1]++; cnt[n]--;
	}
	sort(all(v));
	mas.resize(v.size() + 1); mas[v.size()] = -2;
	per(i, (int)v.size()) {
		mas[i] = max(mas[i+1], v[i].second);
	}

	for (int j = ma - 1; j > 0; j--) {
		vector<P> nex;
		for (int id : loc[j]) {
			int to = lower_bound(all(v), P{ h[id],n + 1 }) - v.begin();
			if (mas[to] > id) {
				cnt[id + 1]++;
				cnt[mas[to]]--;
				nex.push_back({ h[id],id });
			}
		}
		swap(v, nex);
		sort(all(v));
		mas.resize(v.size() + 1); mas[v.size()] = -2;
		per(i, (int)v.size()) {
			mas[i] = max(mas[i + 1], v[i].second);
		}
	}
	for (P p : v) {
		int id = p.second;
		cnt[0]++; cnt[id]--;
	}
	rep(i, n)cnt[i + 1] += cnt[i];
	rep(i, q) {
		int ans = score[i];
		if (cnt[a[i]] > 0) {
			ans = max(ans, ma);
		}
		else {
			ans = max(ans, ma - 1);
		}
		cout << ans << "\n";
	}
}

signed main() {
    ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(15);
	//init_f();
	//expr();
	//int t; cin >> t; rep(i, t)
	solve();
	return 0;
}