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
const ld eps = 1e-8;
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
const int max_n = 1 << 1;
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
		return min(a, b);
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
	int queryr(int loc, int x) {
		int k = loc + sz - 1;
		while (k > 0) {
			int pre = k;
			k = (k - 1) / 2;
			if (2 * k + 2 == pre) {
				//
			}
			else {
				if (node[2 * k + 2] < x) {
					k = 2 * k + 2; break;
				}
			}
		}
		assert(k > 0);
		while (k < sz - 1) {
			if (node[2 * k + 1] < x) {
				k = 2 * k + 1;
			}
			else {
				k = 2 * k + 2;
			}
		}
		return k - (sz - 1);
	}
	int queryl(int loc, int x) {
		int k = loc + sz - 1;
		if (node[k] < x)return loc;
		while (k > 0) {
			int pre = k;
			k = (k - 1) / 2;
			if (2 * k + 1 == pre) {
				//
			}
			else {
				if (node[2 * k + 1] < x) {
					k = 2 * k + 1; break;
				}
			}
		}
		assert(k > 0);
		while (k < sz - 1) {
			if (node[2 * k + 2] < x) {
				k = 2 * k + 2;
			}
			else {
				k = 2 * k + 1;
			}
		}
		return k - (sz - 1);
	}
};

struct Seg2T {
private:
	int sz; vector<P> node;
	const P init_c = { -mod,-1 };
public:
	Seg2T(int n) {
		sz = 1;
		while (sz < n)sz *= 2;
		node.resize(2 * sz - 1, init_c);
		rep(i, n) {
			node[i + sz - 1] = { 0,i };
		}
		per(i, sz - 1) {
			node[i] = f(node[2 * i + 1], node[2 * i + 2]);
		}
	}
	void init(int n) {
		rep(i, n) {
			node[i + sz - 1] = { 0,i };
		}
		per(i, sz - 1) {
			node[i] = f(node[2 * i + 1], node[2 * i + 2]);
		}
	}
	P f(P a, P b) {
		if (a.first > b.first)return a;
		else if (a.first < b.first)return b;
		if (a.second < b.second)return a;
		else return b;
	}
	void update(int k, P a) {
		k += sz - 1;
		node[k] = a;
		while (k > 0) {
			k = (k - 1) / 2;
			node[k] = f(node[k * 2 + 1], node[k * 2 + 2]);
		}
	}
	P query(int a, int b, int k = 0, int l = 0, int r = -1) {
		if (r < 0)r = sz;
		if (r <= a || b <= l)return init_c;
		else if (a <= l && r <= b)return node[k];
		else {
			P vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
			P vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
			return f(vl, vr);
		}
	}
};

struct ste {
	int l, r, id;
};
bool operator<(ste a, ste b) {
	if (a.r != b.r)return a.r < b.r;
	if (a.l != b.l)return a.l < b.l;
	return a.id < b.id;
}
const int b = 200;

void solve() {
	string s;
	cin >> s;
	int m; cin >> m;
	vector<string> t(m);
	rep(i, m)cin >> t[i];
	int q; cin >> q;
	vector<int> l(q), r(q), sl(q), sr(q);
	rep(i, q) {
		cin >> sl[i] >> sr[i] >> l[i] >> r[i];
		l[i]--; r[i]--; sl[i]--; sr[i]--;
	}
	string al;
	al += s;
	rep(i, m) {
		al += t[i];
		al.push_back('?');
	}
	SuffixArray sa(al);
	vector<int> ori = sa.lcp;
	ori.push_back(0);
	SegT st(ori);
	vector<int> rev(al.size());
	for (int i = 1; i < sa.sa.size();i++) {
		rev[sa.sa[i]] = i;
	}
	vector<int> ad(m);
	ad[0] = s.size();
	rep(i, m - 1) {
		ad[i + 1] = ad[i] + t[i].size()+1;
	}
	vector<int> ids;
	vector<int>trans(sa.sa.size());
	int tmp = 0;
	for (int i = 1; i < sa.sa.size(); i++) {
		trans[i] = tmp;
		if (sa.sa[i] >= s.size()) {
			int id = upper_bound(all(ad), sa.sa[i]) - ad.begin(); id--;
			ids.push_back(id);
			tmp++;
		}
	}
	trans.push_back(tmp);
	auto segquery = [&](int l, int r)->P {
		int len = r - l + 1;
		int loc = rev[l];
		int resl = st.queryl(loc, len);
		int resr = st.queryr(loc, len);
		resl = trans[resl];
		resr = trans[resr];
		return { resl,resr };
	};
	const int b = 200;
	int z = al.size() - s.size();
	int d = (z + b - 1) / b;
	vector<vector<ste>> qs(d);
	vector<P> ans(q);
	rep(i, q) {
		P p = segquery(l[i], r[i]);
		if (p.first >= p.second) {
			ans[i] = { 0,sl[i] };
			continue;
		}
		qs[p.first / b].push_back({ p.first,p.second,i });
	}
	Seg2T ct(m);
	vector<int> cnt(m);
	auto add = [&](int loc) {
		int id = ids[loc];
		cnt[id]++;
		ct.update(id, { cnt[id],id });
	};
	auto del = [&](int loc) {
		int id = ids[loc];
		cnt[id]--;
		ct.update(id, { cnt[id],id });
	};
	rep(i, d) {
		sort(all(qs[i]));
		ct.init(m);
		fill(all(cnt), 0);
		int l = i * b, r = i * b;
		for (ste s : qs[i]) {
			while (r < s.r) {
				add(r); r++;
			}
			while (l < s.l) {
				del(l); l++;
			}
			while (l > s.l) {
				add(l - 1);
				l--;
			}

			P p = ct.query(sl[s.id], sr[s.id] + 1);
			ans[s.id] = p;
		}
	}
	rep(i, q) {
		cout << ans[i].second+1 << " " << ans[i].first << "\n";
	}
}


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init_f();
	//init();
	//expr();
	//int t; cin >> t;rep(i, t)
	solve();
	return 0;
}