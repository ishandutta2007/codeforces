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
#include<chrono>
using namespace std;

//#define int long long
typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 1000000007;
const ll INF = mod * mod;
typedef pair<int, int>P;

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
const ld eps = 1e-4;
const ld pi = acosl(-1.0);

template<typename T>
void chmin(T& a, T b) {
	a = min(a, b);
}
template<typename T>
void chmax(T& a, T b) {
	a = max(a, b);
}
template<typename T>
void cinarray(vector<T>& v) {
	rep(i, v.size())cin >> v[i];
}
template<typename T>
void coutarray(vector<T>& v) {
	rep(i, v.size()) {
		if (i > 0)cout << " "; cout << v[i];
	}
	cout << "\n";
}
ll mod_pow(ll x, ll n, ll m = mod) {
	if (n < 0) {
		ll res = mod_pow(x, -n, m);
		return mod_pow(res, m - 2, m);
	}
	if (abs(x) >= m)x %= m;
	if (x < 0)x += m;
	if (x == 0)return 0;
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
const int max_n = 1 << 20;
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

ll gcd(ll a, ll b) {
	a = abs(a); b = abs(b);
	if (a < b)swap(a, b);
	while (b) {
		ll r = a % b; a = b; b = r;
	}
	return a;
}
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

struct AhoCorasick {
	static const int SIZE = 27;
	struct State {
		int index, next[SIZE], val;
		//vector<int> accept;
		State(int index) : index(index) {
			for (int i = 0; i < SIZE; i++)next[i] = -1;
			val = 0;
		}
	};
	vector<State> pma;
	//vector<int> lens;

	AhoCorasick() { ; }
	void init(const vector<string>& str, char base_c = 'a') {
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
		for (string s : str) {
			int loc = 0;
			for (char c : s) {
				loc = sub(loc, c - base_c);
			}
			pma[loc].val += 1;
		}
		queue<int> q;
		q.push(0);
		while (!q.empty()) {
			int id = q.front(); q.pop();
			if (id != 0)pma[id].val += pma[pma[id].next[SIZE - 1]].val;
			rep(c, SIZE - 1) {
				if (pma[id].next[c] >0) {
					q.push(pma[id].next[c]);
				}
			}
		}
	}
	int sub(int index, int c) {
		return pma[index].next[c] != -1 ?
			pma[index].next[c] :
			pma[index].next[c] = sub(pma[index].next[SIZE - 1], c);
	}
	int query(string& s, char base_c = 'a') {
		int loc = 0;
		int res = 0;
		for (char c : s) {
			loc = sub(loc, c - base_c);
			res += pma[loc].val;
		}
		return res;
	}
};

struct online_AhoCorasick {
	vector<AhoCorasick> vaho;
	vector<vector<string>> memo;
	void add(string s) {
		vector<string> cur;
		cur.push_back(s);
		while (memo.size() && memo.back().size() == cur.size()) {
			vector<string> ncur;
			for (string s : memo.back())ncur.push_back(s);
			for (string s : cur)ncur.push_back(s);
			swap(cur, ncur);
			memo.pop_back();
			vaho.pop_back();
		}
		memo.push_back(cur);
		vaho.resize(vaho.size() + 1);
		vaho.back().init(cur);
	}
	int query(string& s) {
		int res = 0;
		rep(i, vaho.size())res += vaho[i].query(s);
		return res;
	}
};


void solve() {
	int q; cin >> q;
	online_AhoCorasick ad, del;
	rep(i, q) {
		int typ; string s; cin >> typ >> s;
		if (typ == 1) {
			ad.add(s);
		}
		else if (typ == 2) {
			del.add(s);
		}
		else {
			int ans = ad.query(s) - del.query(s);
			cout << ans << endl;
		}
	}
}


signed main() {
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout << fixed << setprecision(10);
	//init_f();
	//init();
	//while(true)
	//expr();
	//int t; cin >> t; rep(i, t)
	solve();
	return 0;
}