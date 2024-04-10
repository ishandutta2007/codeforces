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

int gcd(int a, int b) {
	if (a < b)swap(a, b);
	while (b) {
		int r = a % b; a = b; b = r;
	}
	return a;
}
struct AhoCorasick {
	static const int SIZE = 11;
	struct State {
		int index, next[SIZE];
		//vector<int> accept;
		State(int index) : index(index) {
			for (int i = 0; i < SIZE; i++)next[i] = -1;
		}
	};
	vector<State> pma;
	//vector<int> lens;

	AhoCorasick(const vector<string>& str, char base_c = '0') {
		pma.clear();
		pma.push_back(State(0));
		//lens.clear();
		rep(i, str.size()) {
			int t = 0;
			for (char c : str[i]) {
				if (pma[t].next[c - base_c] == -1) {
					int m = pma.size();
					pma[t].next[c - base_c] = m;
					pma.push_back(State(m));
				}
				t = pma[t].next[c - base_c];
			}
			//pma[t].accept.push_back(lens.size());
			//lens.push_back(str[i].size());
		}
		queue<int> que;
		for (int c = 0; c < SIZE - 1; c++) {
			if (pma[0].next[c] != -1) {
				pma[pma[0].next[c]].next[SIZE - 1] = 0;
				que.push(pma[0].next[c]);
			}
			else {
				pma[0].next[c] = 0;
			}
		}
		while (!que.empty()) {
			int t = que.front();
			que.pop();
			for (int c = 0; c < SIZE - 1; c++) {
				if (pma[t].next[c] != -1) {
					que.push(pma[t].next[c]);
					int r = pma[t].next[SIZE - 1];
					while (pma[r].next[c] == -1) r = pma[r].next[SIZE - 1];
					pma[pma[t].next[c]].next[SIZE - 1] = pma[r].next[c];
					//for (int i : pma[pma[r].next[c]].accept)
					//	pma[pma[t].next[c]].accept.push_back(i);
				}
			}
		}
	}
	int sub(int index, int c) {
		return pma[index].next[c] != -1 ?
			pma[index].next[c] :
			pma[index].next[c] = sub(pma[index].next[SIZE - 1], c);
	}
	vector<int> ban;
	void init_ban(vector<string>& vs) {
		ban.resize(pma.size());
		rep(i, vs.size()) {
			int loc = 0;
			rep(j, vs[i].size()) {
				loc = sub(loc, vs[i][j] - '0');
			}
			ban[loc] = true;
		}
	}
	vector<int> dp;
	vector<int> cop;
	void init() {
		dp.resize(pma.size(),-mod);
		dp[0] = 0;
		cop.resize(pma.size());
	}
	void step(int c) {
		rep(i, cop.size())cop[i] = dp[i];
		rep(i, dp.size()) {
			int nex = sub(i, c);
			cop[nex] = max(cop[nex], dp[i] + 1);
		}
		rep(i, dp.size()) {
			if (ban[i])dp[i] = -mod;
			else dp[i] = cop[i];
		}
	}
	int query() {
		int res = 0;
		rep(i, dp.size())res = max(res, dp[i]);
		return res;
	}
};



void solve() {
	string s; cin >> s;
	int x; cin >> x;
	vector<string> vs;
	rep(i, (1 << x)) {
		if (i & (1 << x - 1)) {
			int le = 0;
			vector<int> v;
			rep(j, x) {
				if (i & (1 << j)) {
					v.push_back(j - le + 1);
					le = j + 1;
				}
			}
			bool valid = true;
			rep(j, v.size())if (v[j] > 9)valid = false;
			rep(j, v.size()) {
				int sum = 0;
				Rep(k, j, v.size()) {
					sum += v[k];
					if (x!=sum&&x % sum == 0) {
						valid = false; break;
					}
				}
			}
			if (valid) {
				string cur;
				rep(j, v.size()) {
					cur.push_back('0' + v[j]);
				}
				vs.push_back(cur);
			}
		}
	}
	//cout << vs.size() << "\n";
	AhoCorasick ahoc(vs);
	ahoc.init_ban(vs);
	ahoc.init();
	rep(i, s.size()) {
		int c = s[i] - '0';
		ahoc.step(c);
	}
	int ans = ahoc.query();
	ans = s.size() - ans;
	cout << ans << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init_f();
	//init();
	//expr();
	//int t; cin >> t; rep(i, t)
	solve();
	return 0;
}