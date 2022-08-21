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

vector<int> memo;
int sz;
priority_queue<P>node[1 << 21];

void init(int n) {
	sz = 1;
	while (sz < n)sz *= 2;
}

void update(P p, int a, int b, int k = 0, int l = 0, int r = -1) {
	if (r < 0)r = sz;
	if (r <= a || b <= l)return;
	else if (a <= l && r <= b) {
		node[k].push(p);
	}
	else {
		update(p, a, b, 2 * k + 1, l, (l + r) / 2);
		update(p, a, b, 2 * k + 2, (l + r) / 2, r);
	}
}
int query(int k) {
	int res = -1;
	k += sz - 1;
	while (node[k].size() && node[k].top().first != memo[node[k].top().second])node[k].pop();
	if (node[k].size())res = max(res, node[k].top().first);
	while (k > 0) {
		k = (k - 1) / 2;
		while (node[k].size() && node[k].top().first != memo[node[k].top().second])node[k].pop();
		if (node[k].size())res = max(res, node[k].top().first);
	}
	return res;
}

struct sparse_table {
private:
	int n;
	int tmp;
	vector<int> ori;
	vector<int> transtmp;
	vector<vector<int>> nodel;
public:
	sparse_table(vector<int> _ori) {
		ori = _ori;
		n = ori.size();
		int cop = n;
		tmp = 0;
		while (cop > 0) {
			tmp++; cop >>= 1;
		}
		nodel.resize(tmp);
		rep(i, tmp)nodel[i].resize(n);
		rep(i, n) {
			nodel[0][i] = ori[i];
		}
		rep(j, tmp - 1) {
			rep(i, n) {
				if (i + (1 << j) < n) {
					nodel[j + 1][i] = min(nodel[j][i], nodel[j][i + (1 << j)]);
				}
			}
		}
		transtmp.resize(n + 1);
		int x = 1;
		int cnt = 0;
		rep1(i, n) {
			while (x * 2 <= i) {
				x *= 2; cnt++;
			}
			transtmp[i] = cnt;
		}
	}
	//[l,r)
	int query(int l, int r) {
		if (r - l == 0)return mod;
		int cnt = transtmp[r - l];
		return min(nodel[cnt][l], nodel[cnt][r - (1 << cnt)]);
	}
};

void solve() {
	int n, q; cin >> n >> q;
	vector<string> s(n);
	rep(i, n)cin >> s[i];
	vector<int> typ(q);
	vector<string> qs(q);
	vector<int> ind(q), val(q);
	rep(i, q) {
		cin >> typ[i];
		if (typ[i] == 1) {
			cin >> ind[i] >> val[i]; ind[i]--;
		}
		else {
			cin >> qs[i];
		}
	}
	vector<int> ad(n + q);
	string al;
	rep(i, n) {
		ad[i] = al.size();
		al += s[i];
	}
	rep(i, q) {
		ad[i + n] = al.size();
		al += qs[i];
		if (qs[i].size())al.push_back('*');
	}
	SuffixArray sa(al);
	vector<int> trans(al.size());
	rep1(i, al.size())trans[sa.sa[i]] = i;
	sparse_table sp(sa.lcp);
	init(al.size() + 1);
	//[]
	vector<int> le(n), ri(n);
	rep(i, n) {
		int loc = trans[ad[i]];
		int l = -1, r = loc + 1;
		while (r - l > 1) {
			int m = (l + r) / 2;
			if (sp.query(m, loc + 1) < s[i].size()) {
				l = m;
			}
			else {
				r = m;
			}
		}
		le[i] = l;
		l = loc, r = al.size() + 1;
		while (r - l > 1) {
			int m = (l + r) / 2;
			if (sp.query(loc + 1, m + 1) < s[i].size()) {
				r = m;
			}
			else {
				l = m;
			}
		}
		ri[i] = l;
		update({ 0,i }, le[i], ri[i] + 1);
	}
	memo.resize(n);
	rep(i, q) {
		if (typ[i] == 1) {
			int id = ind[i];
			//st.update(memo[id], le[id], ri[id] + 1, false);
			memo[id] = val[i];
			update({ memo[id],id }, le[id], ri[id] + 1);
			//st.update(memo[id], le[id], ri[id] + 1, true);
		}
		else {
			int ans = -1;
			rep(j, qs[i].size()) {
				int loc = trans[ad[i + n] + j];
				ans = max(ans, query(loc));
			}
			cout << ans << "\n";
		}
	}
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