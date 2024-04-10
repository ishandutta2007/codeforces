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

modint dp[51][30000][2][2];
struct AhoCorasick {
	static const int SIZE = 27;
	struct State {
		int index, next[SIZE];
		vector<int> accept;
		State(int index) : index(index) {
			for (int i = 0; i < SIZE; i++)next[i] = -1;
		}
	};
	vector<State> pma;
	vector<int> lens;

	AhoCorasick(const vector<string>& str,char base_c='a') {
		pma.clear();
		pma.push_back(State(0));
		lens.clear();
		rep(i, str.size()) {
			int t = 0;
			for (char c : str[i]) {
				if (pma[t].next[c-base_c] == -1) {
					int m = pma.size();
					pma[t].next[c-base_c] = m;
					pma.push_back(State(m));
				}
				t = pma[t].next[c-base_c];
			}
			pma[t].accept.push_back(lens.size());
			lens.push_back(str[i].size());
		}
		queue<int> que;
		for (int c = 0; c < SIZE-1; c++) {
			if (pma[0].next[c] != -1) {
				pma[pma[0].next[c]].next[SIZE-1] = 0;
				que.push(pma[0].next[c]);
			}
			else {
				pma[0].next[c] = 0;
			}
		}
		while (!que.empty()) {
			int t = que.front();
			que.pop();
			for (int c = 0; c < SIZE-1; c++) {
				if (pma[t].next[c] != -1) {
					que.push(pma[t].next[c]);
					int r = pma[t].next[SIZE-1];
					while (pma[r].next[c] == -1) r = pma[r].next[SIZE-1];
					pma[pma[t].next[c]].next[SIZE-1] = pma[r].next[c];
					for (int i : pma[pma[r].next[c]].accept)
						pma[pma[t].next[c]].accept.push_back(i);
				}
			}
		}
	}
	int sub(int index, int c) {
		return pma[index].next[c] != -1 ?
			pma[index].next[c] :
			pma[index].next[c] = sub(pma[index].next[SIZE-1], c);
	}
	vector<int> query(string& t) {
		int index = 0;
		vector<int> ret(lens.size(), -1);
		rep(i, t.size()) {
			int c = t[i];
			index = sub(index, c);
			for (int j : pma[index].accept) {
				if (ret[j] != -1) continue;
				ret[j] = i - lens[j] + 1;
			}
		}
		return ret;
	}

	vector<bool> islast;
	void make_mark(vector<string> s) {
		islast.resize(pma.size());
		rep(i, s.size()) {
			int ind = 0;
			for (char c : s[i]) {
				ind = sub(ind, c-'0');
			}
			islast[ind] = true;
		}
	}
	modint num(string r) {
		int d = r.size();
		int sz = pma.size();
		rep(i, d + 1)rep(j, sz)rep(k, 2)rep(l, 2)dp[i][j][k][l] = 0;
		dp[0][0][0][0] = 1;
		rep(i, d) {
			int t = r[i] - '0';
			rep(j, sz)rep(k, 2)rep(l, 2) {
				modint val = dp[i][j][k][l];
				if (val == (modint)0)continue;
				rep(x, 10) {
					int ni = i + 1;
					int nj = sub(j, x);
					int nk = k;
					if (nk == 0 && t < x)continue;
					if (t > x)nk = 1;
					int nl = l;
					if (islast[nj])nl = 1;
					dp[ni][nj][nk][nl] += val;
				}
			}
		}
		modint res = 0; rep(j, sz)rep(k, 2) {
			res += dp[d][j][k][1];
		}
		return res;
	}
};

bool exi(string s, string c) {
	rep(i, s.size() - c.size() / 2 + 1) {
		rep(j, c.size() - c.size() / 2 + 1) {
			string sl = s.substr(i, c.size() / 2);
			string sr = c.substr(j, c.size() / 2);
			if (sl == sr)return true;
		}
	}
	return false;
}
void solve() {
	string s; cin >> s;
	string x, y; cin >> x >> y;
	if (s.size() < x.size() / 2) {
		cout << 0 << "\n"; return;
	}
	int d = x.size();
	vector<string> vs;
	rep(i, s.size() - d / 2 + 1) {
		string t = s.substr(i, d / 2);
		vs.push_back(t);
	}
	sort(all(vs));
	vs.erase(unique(all(vs)), vs.end());
	AhoCorasick aho(vs,'0');
	aho.make_mark(vs);
	modint ans = aho.num(y) - aho.num(x);
	if (exi(s, x))ans += 1;
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