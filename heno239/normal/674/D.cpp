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
constexpr ll mod = 1000000007;
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
	int n;
	modint() :n(0) { ; }
	modint(ll m) {
		if (m < 0 || mod <= m) {
			m %= mod; if (m < 0)m += mod;
		}
		n = m;
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
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-8;
const ld pi = acosl(-1.0);
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

using mP = pair<modint, modint>;
//-----------------------------------

const int bl = 300;
void solve() {
	int n, q; cin >> n >> q;
	vector<ll> t(n);
	rep(i, n)cin >> t[i];
	vector<int> f(n);
	rep(i, n) {
		cin >> f[i]; f[i]--;
	}
	vector<int> typ(q);
	vector<int> x(q), y(q);
	rep(i, q) {
		cin >> typ[i];
		if (typ[i] <= 2) {
			cin >> x[i]; x[i]--;
		}
		if (typ[i] == 1) {
			cin >> y[i]; y[i]--;
		}
	}
	vector<int> cf;
	vector<ll> score(n);
	vector<int> deg(n);
	vector<bool> exi(n);
	vector<LP> ans;

	vector<ll> mi(n), ma(n);
	for (int i = 0; i < q; i+=bl) {
		int le = i;
		int ri = min(i + bl, q);
		//[le,ri)
		fill(all(exi), false);
		//calc score
		fill(all(score), 0);
		fill(all(deg), 0);
		rep(j, n) {
			deg[f[j]]++;
		}
		rep(j, n) {
			int c = deg[j] + 2;
			ll val = t[j] / c;
			score[f[j]] += val;
			score[j] += t[j] - val * (c - 1);
			int nc = deg[f[j]] + 2;
			ll nval = t[f[j]] / nc;
			score[j] += nval;
		}
		//coutarray(score);
		cf = f;
		vector<int> cur;
		Rep(j, le, ri) {
			if (typ[j] == 1) {
				cur.push_back(x[j]);
				cur.push_back(cf[x[j]]);
				cur.push_back(cf[cf[x[j]]]);
				cur.push_back(y[j]);
				cur.push_back(cf[y[j]]);
				cf[x[j]] = y[j];
			}
			else if (typ[j] == 2) {
				cur.push_back(x[j]);
			}
			else {
				//non
			}
		}
		for (int id : cur) {
			exi[id] = true;
		}
		sort(all(cur)); cur.erase(unique(all(cur)), cur.end());
		rep(j, cur.size()) {
			mi[cur[j]] = INF;
			ma[cur[j]] = -INF;
		}
		ll premi = INF, prema = -INF;
		//rep(j, n)st.insert(score[j]);
		rep(j, n) {
			if (!exi[j]) {
				if (exi[f[j]]) {
					chmin(mi[f[j]], score[j]);
					chmax(ma[f[j]], score[j]);
				}
				else {
					chmin(premi, score[j]);
					chmax(prema, score[j]);
				}
			}
		}
		//coutarray(cur);
		Rep(j, le, ri) {
			if (typ[j] == 1) {
				int id = x[j];
				//from id
				int c = deg[id] + 2;
				ll val = t[id] / c;
				score[f[id]] -= val;
				score[y[j]] += val;
				//from f[id]
				int prec = deg[f[id]] + 2;
				int nexc = deg[f[id]] - 1 + 2;
				ll preval = t[f[id]] / prec;
				ll nexval = t[f[id]] / nexc;
				score[id] -= nexval;
				score[f[id]] += t[f[id]] - (nexc-1) * nexval - (t[f[id]] - (prec-1) * preval);
				score[f[f[id]]] += nexval - preval;
				if (mi[f[id]] != INF) {
					mi[f[id]] += nexval - preval;
					ma[f[id]] += nexval - preval;
				}
				rep(k, cur.size()) {
					if (f[cur[k]] == f[id]) {
						score[cur[k]] += nexval - preval;
					}
				}
				deg[f[id]]--;
				//from f[id]
				f[id] = y[j];
				prec = deg[f[id]] + 2;
				nexc = deg[f[id]] + 1 + 2;
				preval = t[f[id]] / prec;
				nexval = t[f[id]] / nexc;
				score[id] += preval;
				score[f[id]] += t[f[id]] - (nexc - 1) * nexval - (t[f[id]] - (prec - 1) * preval);
				score[f[f[id]]] += nexval - preval;
				if (mi[f[id]] != INF) {
					mi[f[id]] += nexval - preval;
					ma[f[id]] += nexval - preval;
				}
				rep(k, cur.size()) {
					if (f[cur[k]] == f[id]) {
						score[cur[k]] += nexval - preval;
					}
				}
				deg[f[id]]++;
			}
			else if(typ[j]==2) {
				ans.push_back({ score[x[j]],-1 });
			}
			else {
				ll nwmi = premi;
				ll nwma = prema;
				rep(j, cur.size()) {
					chmin(nwmi, score[cur[j]]);
					chmax(nwma, score[cur[j]]);
					chmin(nwmi, mi[cur[j]]);
					chmax(nwma, ma[cur[j]]);
				}
				ans.push_back({ nwmi,nwma });
			}
		}
	}
	rep(i, ans.size()) {
		if (ans[i].second >= 0) {
			cout << ans[i].first << " " << ans[i].second << "\n";
		}
		else {
			cout << ans[i].first << "\n";
		}
	}
}


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(10);
	//init_f();
	//init();
	//while(true)
	//expr();
	//int t; cin >> t; rep(i, t)
	solve();
	return 0;
}