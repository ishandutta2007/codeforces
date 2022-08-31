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
constexpr ll mod = 998244353;
//constexpr ll mod = 1000000007;
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
void pout(P& p) {
	cout << p.first << " " << p.second << "\n";
}
void pout(LP& p) {
	cout << p.first << " " << p.second << "\n";
}
ll mod_pow(ll x, ll n, ll m = mod) {
	if (n < 0) {
		ll res = mod_pow(x, -n, m);
		return mod_pow(res, m - 2, m);
	}
	if (abs(x) >= m)x %= m;
	if (x < 0)x += m;
	//if (x == 0)return 0;
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
bool operator<(modint a, modint b) { return a.n < b.n; }
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
void pout(LDP& p) {
	cout << p.first << " " << p.second << "\n";
}
const ld eps = 1e-8;
const ld pi = acosl(-1.0);
template<typename T>
void addv(vector<T>& v, int loc, T val) {
	if (loc >= v.size())v.resize(loc + 1, 0);
	v[loc] += val;
}
/*const int mn = 100005;
bool isp[mn];
vector<int> ps;
void init() {
	fill(isp + 2, isp + mn, true);
	for (int i = 2; i < mn; i++) {
		if (!isp[i])continue;
		ps.push_back(i);
		for (int j = 2 * i; j < mn; j += i) {
			isp[j] = false;
		}
	}
}*/

//[,val)
template<typename T>
auto prev_itr(set<T>& st, T val) {
	auto res = st.lower_bound(val);
	if (res == st.begin())return st.end();
	res--; return res;
}

//[val,)
template<typename T>
auto next_itr(set<T>& st, T val) {
	auto res = st.lower_bound(val);
	return res;
}
using mP = pair<modint, modint>;

const string drul = "DRUL";
//DRUL
int dx[4] = { 0,-1,0,1 };
int dy[4] = { -1,0,1,0 };
//-----------------------------------------

const int bl = 2401;
const int med =400;
const int mn = 100001;
void solve() {
	int n, q; cin >> n >> q;
	vector<int> a(n);
	rep(i, n)cin >> a[i];
	vector<int> ql(q), qr(q), qk(q), qp(q), qx(q), qtyp(q);
	rep(i, q) {
		int typ; cin >> typ;
		qtyp[i] = typ;
		if (typ == 1) {
			int l, r, k; cin >> l >> r >> k;
			l--; r--; ql[i] = l, qr[i] = r, qk[i] = k;
		}
		else {
			int p, x; cin >> p >> x; p--; qp[i] = p, qx[i] = x;
		}
	}
	const int dn = (n + bl - 1) / bl;
	const int dq = (q + bl - 1) / bl;
	vector<vector<vector<int>>> trans(dn);
	rep(i, dn) {
		trans[i].resize(dn);
		rep(j, dn) {
			trans[i][j].resize(dq);
		}
	}
	int tmp = 0;
	rep(k, dq) {
		if (k % 2 == 0) {
			rep(i, dn) {
				if (i % 2 == 0) {
					rep(j, dn) {
						trans[i][j][k] = tmp; tmp++;
					}
				}
				else {
					per(j, dn) {
						trans[i][j][k] = tmp; tmp++;
					}
				}
			}
		}
		else {
			per(i, dn) {
				if (i % 2 == 0) {
					per(j, dn) {
						trans[i][j][k] = tmp; tmp++;
					}
				}
				else {
					rep(j, dn) {
						trans[i][j][k] = tmp; tmp++;
					}
				}
			}
		}
	}
	vector<P> qupd, qori;
	vector<int> cop = a;
	vector<P> vp;
	vector<int> pre2(q);
	rep(i, q) {
		if (qtyp[i] == 2) {
			qori.push_back({ qp[i],a[qp[i]] });
			a[qp[i]] = qx[i];
			qupd.push_back({ qp[i],a[qp[i]] });
		}
		else {
			pre2[i] = qori.size();
			int x = ql[i] / bl;
			int y = qr[i] / bl;
			int z = qori.size() / bl;
			vp.push_back({ trans[x][y][z],i });
		}
	}
	sort(all(vp));
	a = cop;
	vector<int> alcnt(mn);
	rep(i, n)alcnt[a[i]]++;
	rep(i, q)if (qtyp[i] == 2) {
		alcnt[qx[i]]++;
	}
	vector<int> sups;
	rep(i, mn)if (alcnt[i] >= med)sups.push_back(i);
	vector<int> curcnt(mn);
	vector<int> cursum(med);
	auto upd = [&](int x, int ad) {
		if (alcnt[x] >= med) {
			curcnt[x] += ad;
		}
		else {
			if (curcnt[x] >= 0)cursum[curcnt[x]]--;
			curcnt[x] += ad;
			if (curcnt[x] >= 0)cursum[curcnt[x]]++;
		}
	};
	auto query = [&](int k) {
		vector<P> vp;
		for (int i = 1; i < med; i++)if (cursum[i] > 0) {
			vp.push_back({ i,cursum[i] });
		}
		for (int id : sups) {
			if (curcnt[id] > 0) {
				vp.push_back({ curcnt[id],1 });
			}
		}
		sort(all(vp));
		auto cop = vp; vp.clear();
		rep(i, cop.size()) {
			int ss = cop[i].second;
			while (i + 1 < cop.size() && cop[i].first == cop[i + 1].first) {
				i++; ss += cop[i].second;
			}
			vp.push_back({ cop[i].first,ss });
		}
		
		int r = 0;
		int s = 0;
		int ans = -1;
		rep(l, vp.size()) {
			while (r < vp.size() && s < k) {
				s += vp[r].second; r++;
			}
			if (s >= k) {
				int val = vp[r - 1].first - vp[l].first;
				if (val < ans || ans < 0)ans = val;
			}
			s -= vp[l].second;
		}
		//rep(i, vp.size())cout << vp[i].first << " " << vp[i].second << "\n";
		return ans;
	};
	int l = 0, r = -1, z = 0;
	vector<int> ans(q);
	for (auto p : vp) {
		int id = p.second;
		while (l < ql[id]) {
			upd(a[l], -1); l++;
		}
		while (l > ql[id]) {
			upd(a[l - 1], 1); l--;
		}
		while (r < qr[id]) {
			upd(a[r + 1], 1); r++;
		}
		while (r > qr[id]) {
			upd(a[r], -1); r--;
		}
		while (z < pre2[id]) {
			int loc = qori[z].first;
			if (ql[id] <= loc && loc <= qr[id]) {
				upd(a[loc], -1);
			}
			a[loc] = qupd[z].second;
			if (ql[id] <= loc && loc <= qr[id]) {
				upd(a[loc], 1);
			}
			z++;
		}
		while (z > pre2[id]) {
			int loc = qori[z - 1].first;
			if (ql[id] <= loc && loc <= qr[id]) {
				upd(a[loc], -1);
			}
			a[loc] = qori[z-1].second;
			if (ql[id] <= loc && loc <= qr[id]) {
				upd(a[loc], 1);
			}
			z--;
		}
		//cout << "hello " << id << "\n";
		ans[id] = query(qk[id]);
	}
	rep(i, q) {
		if (qtyp[i] == 1)cout << ans[i] << "\n";
	}
}


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init_f();
	//init();
	//while(true)
	//expr();
	//int t; cin >> t; rep(i, t)
	solve();
	return 0;
}