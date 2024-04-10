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


struct sparse_table {
private:
	int n;
	int tmp;
	vector<int> ori;
	vector<vector<int>> nodel, noder;
public:
	sparse_table(vector<int> _ori) {
		ori = _ori;
		n = ori.size();
		int cop = n;
		tmp = 0;
		while (cop > 0) {
			tmp++; cop >>= 1;
		}
		nodel.resize(n);
		noder.resize(n);
		rep(i, n) {
			nodel[i].resize(tmp);
			noder[i].resize(tmp);
		}
		rep(i, n) {
			nodel[i][0] = ori[i];
			noder[i][0] = ori[i];
		}
		rep(j, tmp - 1) {
			rep(i, n) {
				if (i + (1 << j) < n) {
					nodel[i][j + 1] = min(nodel[i][j], nodel[i + (1 << j)][j]);
				}
				if (i - (1 << j) >= 0) {
					noder[i][j + 1] = min(noder[i][j], noder[i - (1 << j)][j]);
				}
			}
		}
	}
	//[l,r)
	int query(int l, int r) {
		if (r - l == 0)return mod;
		int len = r - l;
		int x = 1;
		int cnt = 0;
		while (x * 2 <= len) {
			x *= 2;
			cnt++;
		}
		return min(nodel[l][cnt], noder[r - 1][cnt]);
	}
};

modint rdp[5005][5005];



int dp[5005][5005];

vector<int> tra(int x) {
	vector<int> res;
	while (x > 0) {
		res.push_back(x & 1); x >>= 1;
	}
	return res;
}
vector<int> merge(vector<int> v1, vector<int> v2) {
	int sz = max(v1.size(),v2.size());
	vector<int> res(sz + 2);
	int c = 0;
	rep(i, sz + 2) {
		if (i < v1.size())c += v1[i];
		if (i < v2.size())c += v2[i];
		res[i] = c % 2; c /= 2;
	}
	while (res.size() && res.back() == 0)res.pop_back();
	return res;
}
bool comp(vector<int> v1, vector<int> v2) {
	if (v1.size() != v2.size())return v1.size() < v2.size();
	per(j, (int)v1.size()) {
		if (v1[j] != v2[j])return v1[j] < v2[j];
	}
	return false;
}
void solve() {
	string s; cin >> s; int n = s.size();
	SuffixArray sa(s);
	vector<int> trans(n);
	rep1(i, n)trans[sa.sa[i]] = i;
	sparse_table st(sa.lcp);

	rep(i, n) {
		//[0,i]
		rdp[i][i+1] = 1;
	}
	modint ans1 = 0;
	for (int i = 1; i < n; i++) {
		if (s[i] == '0')continue;
		//[i
		for (int j = 1; j <= n; j++) {
			rdp[i - 1][j + 1] += rdp[i - 1][j];
		}
		for (int j = i; j < n; j++) {
			//[i,j]
			int len = j - i + 1;
			modint val = 0;
			//[1,len)
			val += rdp[i - 1][len - 1];
			if (i - len >= 0) {
				int c1 = trans[i - len];
				int c2 = trans[i];
				int cc = st.query(min(c1, c2) + 1, max(c1, c2) + 1);
				if (cc >= len) {
					//cout << "?? " << i << " " << j << "\n";
					val += rdp[i - 1][len] - rdp[i - 1][len - 1];
				}
				else {
					if (c1 < c2) {
						val += rdp[i - 1][len] - rdp[i - 1][len - 1];
					}
				}
			}
			rdp[j][len] += val;
		}
	}
	for (int i = 1; i <= n; i++)ans1 += rdp[n-1][i];
	cout << ans1 << "\n";
	
	rep(i, n + 1)rep(j, n + 1)dp[i][j] = mod;
	dp[0][0] = 0;
	rep(i, n) {
		dp[i][i + 1] = 1;
	}
	for (int i = 1; i < n; i++) {
		if (s[i] == '0')continue;
		//[i
		for (int j = 1; j <= n; j++) {
			dp[i - 1][j + 1] = min(dp[i - 1][j + 1], dp[i - 1][j]);
		}
		for (int j = i; j < n; j++) {
			//[i,j]
			int len = j - i + 1;
			int val = mod;
			//[1,len)
			val = dp[i - 1][len - 1];
			if (i - len >= 0) {
				int c1 = trans[i - len];
				int c2 = trans[i];
				int cc = st.query(min(c1, c2) + 1, max(c1, c2) + 1);
				if (cc >= len) {
					val = dp[i - 1][len];
				}
				else {
					if (c1 < c2) {
						val = dp[i - 1][len];
					}
				}
			}
			dp[j][len] = min(dp[j][len],val+1);
		}
	}
	vector<vector<int>> vs;
	for (int i = 1; i <= n; i++) {
		if (dp[n - 1][i] == mod)continue;
		//cout << "! " << i << "\n";
		vector<int> cur;
		rep(j, i) {
			cur.push_back(s[n-1-j] - '0');
		}
		cur = merge(cur, tra(dp[n - 1][i]));
		vs.push_back(cur);
	}
	sort(all(vs), comp);
	vector<int>& v = vs[0];
	modint ans2 = 0;
	modint t2 = 1;
	rep(i, v.size()) {
		ans2 += t2 * (modint)v[i];
		t2 *= 2;
	}
	cout << ans2 << "\n";
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