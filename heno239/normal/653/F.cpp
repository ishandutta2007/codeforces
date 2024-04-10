#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

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
const ld eps = 1e-6;
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
const int max_n = 1 << 21;
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

struct SuffixArray {
	struct SAComp {
		const int h;
		const vector<int>& g;
		SAComp(int h, vector<int>& g) : h(h), g(g) { ; }
		bool operator() (int a, int b) {
			return a != b && (g[a] != g[b] ? g[a] < g[b] : g[a + h] < g[b + h]);
		}
	};
	int n;
	string str;
	vector<int> sa, lcp;
	SuffixArray(const string& t) : n(t.size()), sa(n + 1), lcp(n + 1) {
		str = t;
		// build SA
		vector<int> g(n + 1, 0), b(n + 1, 0);
		rep(i, n + 1) { sa[i] = i; g[i] = str[i]; }
		sort(begin(sa), end(sa), SAComp(0, g));
		for (int h = 1; b[n] != n; h *= 2) {
			SAComp comp(h, g);
			sort(sa.begin(), sa.end(), comp);
			rep(i, n) b[i + 1] = b[i] + comp(sa[i], sa[i + 1]);
			rep(i, n + 1) g[sa[i]] = b[i];
		}
		// build LCP
		int h = 0;
		rep(i, n + 1) b[sa[i]] = i;
		rep(i, n + 1) {
			if (b[i]) {
				for (int j = sa[b[i] - 1]; j + h < n && i + h < n && str[j + h] == str[i + h]; ++h);
				lcp[b[i]] = h;
			}
			else {
				lcp[b[i]] = -1;
			}
			if (h > 0) --h;
		}
	}
	~SuffixArray() { str.clear(); }
	/*int find(string t) {
	int m = t.size();
	string p;
	p = t;
	int left = -1, right = n + 1;
	while (left + 1 < right) {
	int mid = (left + right) / 2;
	if (strncmp(str + sa[mid], p, m) < 0) left = mid;
	else right = mid;
	}
	return strncmp(str + sa[right], p, m) == 0 ? sa[right] : -1;
	}*/
};


struct SegT {
private:
	int sz; vector<int> node;
	const int init_c = mod;
public:
	SegT(vector<int> v) {
		int n = v.size(); sz = 1;
		while (sz < n)sz *= 2;
		node.resize(2 * sz - 1, init_c);
		rep(i, n)node[i + sz - 1] = v[i];
		per(i, sz - 1) {
			node[i] = f(node[2 * i + 1], node[2 * i + 2]);
		}
	}
	int f(int a, int b) {
		return min(a, b);
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
	void sear(int x, vector<int>& v, int a, int b, int k = 0, int l = 0, int r = -1) {
		if (r < 0)r = sz;
		if (r <= a || b <= l)return;
		else if (a <= l && r <= b) {
			if (node[k] != x)return;
			if (r == l + 1) {
				v.push_back(k - (sz - 1));
			}
			else {
				sear(x, v, a, b, k * 2 + 1, l, (l + r) / 2);
				sear(x, v, a, b, k * 2 + 2, (l + r) / 2, r);
			}
		}
		else {
			sear(x, v, a, b, k * 2 + 1, l, (l + r) / 2);
			sear(x, v, a, b, k * 2 + 2, (l + r) / 2, r);
		}
	}
};

const int sup = 500005;
vector<int> locs[2*sup+1];
void solve() {
	int n; cin >> n;
	string s; cin >> s;
	SuffixArray sa(s);
	SegT st(sa.lcp);
	vector<int> c(n + 1);
	c[0] = sup;
	rep(i, n) {
		c[i + 1] = c[i];
		if (s[i] == '(')c[i + 1]++;
		else c[i + 1]--;
	}
	rep(i, n + 1) {
		locs[c[i]].push_back(i);
	}
	auto cnt = [&](int id, int len)->int {
		//cout << id << " " << len << "\n";
		int ri = lower_bound(all(locs[c[id]-1]), id) - locs[c[id]-1].begin();
		if (ri == locs[c[id] - 1].size())ri = n + 1;
		else ri = locs[c[id] - 1][ri];
		if (ri - id < len)len = ri-id;
		int to = upper_bound(all(locs[c[id]]), id + len) - locs[c[id]].begin(); to--;
		id = lower_bound(all(locs[c[id]]), id) - locs[c[id]].begin();
		//cout << "? " << len << "\n";
		//cout << to-id << "\n";
		return to - id;
	};
	vector<int> nex(n);
	ll ans = 0;
	function<void(int, int,int)> dfs = [&](int l, int r,int pre) {
		int mi = st.query(l + 1, r);
		//calc ans
		{
			int id = sa.sa[l];
			ans += cnt(id, mi) - cnt(id, pre);
			//cout << l << " " << r << "\n";
			//cout << "this ad " << cnt(id, mi) - cnt(id, pre) << "\n";
		}
		if (l + 1 == r) {
			return;
		}
		vector<int> nexs;
		st.sear(mi, nexs, l + 1, r);
		vector<P> memo;
		int le = l;
		rep(i, nexs.size()) {
			int to = nexs[i];
			dfs(le, to,mi);
			P nex = { le,to };
			memo.push_back(nex);

			le = to;
		}
		dfs(le, r,mi);
		P nex = { le,r };
		memo.push_back(nex);
	};
	dfs(0, n + 1, 0);
	cout << ans << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(10);
	//init_f();
	//init();
	//expr();

	//int t; cin >> t; rep(i, t)
		solve();
	return 0;
}