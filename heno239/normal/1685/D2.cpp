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
mP operator+(mP a, mP b) {
	return { a.first + b.first,a.second + b.second };
}
mP operator+=(mP& a, mP b) {
	a = a + b; return a;
}
mP operator-(mP a, mP b) {
	return { a.first - b.first,a.second - b.second };
}
mP operator-=(mP& a, mP b) {
	a = a - b; return a;
}

mt19937 mt(time(0));

const string drul = "DRUL";
//DRUL
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
//-----------------------------------------

struct uf {
private:
	vector<int> par, ran;
public:
	uf(int n) {
		par.resize(n, 0);
		ran.resize(n, 0);
		rep(i, n) {
			par[i] = i;
		}
	}
	int find(int x) {
		if (par[x] == x)return x;
		else return par[x] = find(par[x]);
	}
	void unite(int x, int y) {
		x = find(x), y = find(y);
		if (x == y)return;
		if (ran[x] < ran[y]) {
			par[x] = y;
		}
		else {
			par[y] = x;
			if (ran[x] == ran[y])ran[x]++;
		}
	}
	bool same(int x, int y) {
		return find(x) == find(y);
	}
};

vector<int> trans(vector<int> v, int mk) {
	int chk = -1;
	rep(i, v.size())if (v[i] == mk)chk = i;
	assert(chk >= 0);
	rep(i, chk + 1)v.push_back(v[i]);
	v.erase(v.begin(), v.begin() + chk + 1);
	return v;
}
vector<int> sol(vector<int> p) {
	int n = p.size();
	vector<int> v(n); rep(i, n)v[i] = i;
	vector<int> res = { mod };
	int mi = mod;
	do {
		int s = 0;
		rep(i, n) {
			int ni = (i + 1) % n;
			s += abs(v[i] - p[v[ni]]);
		}
		if (s < mi) {
			mi = s, res = v;
		}
		else if (s == mi) {
			chmin(res, v);
		}
	} while (next_permutation(all(v)));
	return res;
}
vector<int> sol2(vector<int> p) {
	int n = p.size();
	vector<bool> used(n);
	vector<vector<int>> vs;
	rep(i, n) {
		if (used[i])continue;
		vector<int> v;
		int cur = i;
		while (!used[cur]) {
			v.push_back(cur);
			used[cur] = true;
			cur = p[cur];
		}
		reverse(all(v));
		vs.push_back(v);
	}
	vector<int> ans = vs[0];
	vs.erase(vs.begin());
	//coutarray(ans);

	vector<int> prev(n), nex(n);
	rep(i, n) {
		prev[i] = i - 1;
		nex[i] = i + 1;
	}
	vector<int> rem(n, -1);
	while (ans.size() < n) {
		//cout << "!! " << nex[4] << "\n";
		//coutarray(ans);
		vs.push_back(ans);
		vector<int> loc(n);
		rep(i, vs.size())for (int id : vs[i])loc[id] = i;
		uf u(vs.size());
		int c = 0;
		rep(i, n - 1) {
			int a = loc[i];
			int b = loc[i + 1];
			if (a != vs.size() - 1 && b != vs.size() - 1) {
				if (!u.same(a, b)) {
					c++; u.unite(a, b);
				}
			}
		}
		int chk = -1;
		ans = trans(ans, 0);
		ans.insert(ans.begin(), 0);
		ans.pop_back();

		int las = -1;
		per(j, ans.size()) {
			int x = prev[ans[j]];
			if (0 <= x && x < n) {
				int a = vs.size() - 1;
				int b = loc[x];
				if (!u.same(a, b)) {
					c++; u.unite(a, b);
					if (c == vs.size() - 1) {
						las = j; break;
					}
				}
			}
			x = nex[ans[j]];
			if (0 <= x && x < n) {
				int a = vs.size() - 1;
				int b = loc[x];
				if (!u.same(a, b)) {
					c++; u.unite(a, b);
					if (c == vs.size() - 1) {
						las = j; break;
					}
				}
			}
		}
		vector<int> pre(n);
		rep(i, vs.size()) {
			rep(j, vs[i].size()) {
				int nj = j + 1;
				if (nj >= vs[i].size())nj = 0;
				pre[vs[i][j]] = vs[i][nj];
			}
		}
		assert(las >= 0);
		//cout << "? " << las << "\n";
		vector<bool> used(vs.size());
		bool upd = false;
		rep(i, ans.size()) {
			uf u2(n);
			rep(i, n - 1) {
				int a = loc[i];
				int b = loc[i + 1];
				if (a != vs.size() - 1 && b != vs.size() - 1) {
					u2.unite(a, b);
				}
			}
			Rep(j, i + 1, ans.size()) {
				int x = prev[ans[j]];
				if (0 <= x && x < n) {
					int a = vs.size() - 1;
					int b = loc[x];
					u2.unite(a, b);
				}
				x = nex[ans[j]];
				if (0 <= x && x < n) {
					int a = vs.size() - 1;
					int b = loc[x];
					u2.unite(a, b);
				}
			}
			//try
			int mil = mod, mir = mod;
			fill(all(used), false);
			used[vs.size() - 1] = true;
			int tmp = ans[i];
			while (true) {
				tmp = prev[tmp];
				if (tmp < 0 || tmp >= n)break;
				if (used[loc[tmp]])break;
				used[loc[tmp]] = true;
				chmin(mil, pre[tmp]);
			}
			fill(all(used), false);
			used[vs.size() - 1] = true;
			tmp = ans[i];
			while (true) {
				tmp = nex[tmp];
				if (tmp < 0 || tmp >= n)break;
				if (used[loc[tmp]])break;
				used[loc[tmp]] = true;
				chmin(mir, pre[tmp]);
			}
			/*if (ans[i] > prev[ans[i]] + 1 && nex[ans[i]] - ans[i] > 1) {
				coutarray(p);
				cout << "ee " << ans[i] << "\n";
			}*/
			//assert(ans[i] - prev[ans[i]] == 1 || nex[ans[i]] - ans[i] == 1);
			if (mil<mod&&mir<mod) {
				if (ans[i] - prev[ans[i]] > 1) {
					u2.unite(loc[ans[i]], loc[prev[ans[i]]]);
					if (!u2.same(loc[ans[i]], loc[ans[i]+1])) {
						mil = mod - 1;
						//cout << "hello? " << ans[i] << " "<<ans.size()<<" "<<mir<<"\n";
					}
				}
				if (nex[ans[i]] - ans[i] > 1) {
					u2.unite(loc[ans[i]], loc[nex[ans[i]]]);
					if (!u2.same(loc[ans[i]], loc[ans[i]-1])) {
						mir = mod - 1;
					}
				}
			}
			
			//cout << "?? "<<i<<" " << mil << " " << mir << "\n";
			bool islef = false, isri = false;
			if (i == las) {
				if (mil < mir)islef = true;
				else isri = true;
			}
			else {
				if (min(mil, mir) < ans[i + 1]) {
					if (mil < mir)islef = true;
					else isri = true;
				}
			}
			//cout << "??? " << ans.size() << " " << islef << " " << isri << "\n";
			if ((islef || isri)&&mil<mod&&mir<mod) {
				int cl = prev[ans[i]];
				int cr = nex[ans[i]];
				bool valid = true;
				if (islef && ans[i] - prev[ans[i]] > 1)valid = false;
				if (isri && nex[ans[i]] - ans[i] > 1)valid = false;
				if (valid) {
					prev[cr] = cl;
					nex[cl] = cr;
				}
			}
			if (islef && ans[i] - prev[ans[i]] > 1) {
				nex[ans[i]] = n;
			}
			if (islef && nex[ans[i]] - ans[i] > 1) {
				nex[ans[i]] = n;
			}
			if (isri && nex[ans[i]] - ans[i] > 1) {
				prev[ans[i]] = -1;
			}
			if (isri && ans[i] - prev[ans[i]] > 1) {
				prev[ans[i]] = -1;
			}
			if (islef) {
				vector<int> nans = trans(ans, ans[i]);
				vector<vector<int>> nvs;

				fill(all(used), false);
				used[vs.size() - 1] = true;
				int tmp = ans[i];
				while (true) {
					tmp = prev[tmp];
					used[loc[tmp]] = true;
					if (mil == pre[tmp]) {
						int k = tmp;
						while (k < ans[i]) {
							int id = loc[k];
							vs[id] = trans(vs[id], k);
							for (int val : vs[id])nans.push_back(val);
							k = nex[k];
						}
						break;
					}
				}
				rep(i, vs.size())if (!used[i])nvs.push_back(vs[i]);
				swap(vs, nvs);
				swap(ans, nans);
				upd = true;
				break;
			}
			else if (isri) {
				vector<int> nans = trans(ans, ans[i]);
				vector<vector<int>> nvs;

				fill(all(used), false);
				used[vs.size() - 1] = true;
				int tmp = ans[i];
				while (true) {
					tmp = nex[tmp];
					used[loc[tmp]] = true;
					if (mir == pre[tmp]) {
						int k = tmp;
						while (k > ans[i]) {
							int id = loc[k];
							vs[id] = trans(vs[id], k);
							for (int val : vs[id])nans.push_back(val);
							k = prev[k];
						}
						break;
					}
					chmin(mir, pre[tmp]);
				}

				rep(i, vs.size())if (!used[i])nvs.push_back(vs[i]);
				swap(vs, nvs);
				swap(ans, nans);
				upd = true;
				break;
			}
			else {
				//
			}
		}
		assert(upd);
	}
	ans = trans(ans, 0);
	ans.insert(ans.begin(), 0);
	ans.pop_back();
	return ans;
}
void expr() {
	for (int n = 2;; n++) {
		vector<int> p(n); rep(i, n)p[i] = i;
		do {
			auto v1 = sol(p);
			auto v2 = sol2(p);
			if (v1 != v2) {
				coutarray(p);
				coutarray(v1);
				coutarray(v2);
			}
		} while (next_permutation(all(p)));
		cout << "fin " << n << "\n";
	}
}
void solve() {
	int n; cin >> n;
	vector<int> p(n);
	rep(i, n) {
		cin >> p[i]; p[i]--;
	}
	vector<int> ans = sol2(p);
	//coutarray(ans);
	//auto ans2 = sol(p);
	//coutarray(ans2);
	rep(i, n)ans[i]++;
	coutarray(ans);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init_f();
	//init();
	//while(true)
	//expr();
	int t; cin >> t; rep(i, t)
		solve();
	return 0;
}