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
modint combP(int a, int b) {
	if (a < 0 || b < 0 || a < b)return 0;
	return fact[a] * factinv[a - b];
}

void solve() {
	int n, m; cin >> n >> m;
	vector<vector<int>> v(m);
	rep(i, m) {
		int len; cin >> len;
		v[i].resize(len);
		rep(j, len) {
			cin >> v[i][j]; v[i][j]--;
		}
	}
	/*per(i, m) {
		if (v[i].size()==1) {
			v.erase(v.begin() + i);
		}
	}
	m = v.size();*/
	vector<vector<int>> ids(n);
	rep(i, m)rep(j, v[i].size())ids[v[i][j]].push_back(i);
	vector<bool> used(m);
	modint pro = 1;
	int cnt = 0;
	vector<P> vv;
	rep(i, m) {
		vv.push_back({ v[i].size(),i });
	}
	sort(all(vv), greater<P>());
	function<int(vector<int>)> dfs = [&](vector<int> vid) {
		//cout << "hello" << " " << vid.size() << "\n";
		int cnt = 0;
		rep(_, vid.size()) {
			int i = vid[_];
			if (used[i])continue;
			used[i] = true;
			vector<vector<int>> vals;
			vals.push_back(v[i]);
			priority_queue<P> q;
			for (int id : v[i])for (int iid : ids[id]) {
				if (!used[iid]) {
					q.push({ v[iid].size(),iid });
					used[iid] = true;
				}
			}
			cnt++;
			if (q.empty()) {
				pro *= fact[v[i].size()];
				continue;
			}
			bool exiz = false;
  			auto merge = [&](int x)->bool {
				int l = mod, r = -mod;
				bool exi = false;
				vector<int> cnt(vals.size());
				vector<int> trans(n, -1);
				rep(i, vals.size())rep(j, vals[i].size())trans[vals[i][j]] = i;
				vector<bool> isin(n);
				for (int id : v[x])isin[id] = true;
				for (int id : v[x]) {
					if (trans[id] < 0) {
						exi = true;
						continue;
					}
					cnt[trans[id]]++;
					l = min(l, trans[id]);
					r = max(r, trans[id]);
				}
				//[l,r]
				if (r - l > 1) {
					for (int j = l + 1; j < r; j++) {
						if (cnt[j] != vals[j].size()) {
							cout << 0 << "\n"; exit(0);
						}
					}
				}
				if (exi) {
					bool isleft = false;
					bool isright = false;
					if (l == 0) {
						isleft = true;
						if (r > 0 && vals[0].size() != cnt[0])isleft = false;
					}
					if (r == vals.size() - 1) {
						isright = true;
						if (l < r && vals[r].size() != cnt[r])isright = false;
					}
					if (!isleft && !isright) {
						cout << 0 << "\n"; exit(0);
					}
					if (isleft) {
						if (vals[r].size() != cnt[r]) {
							vector<int> cl, cr;
							for (int id : vals[r]) {
								if (isin[id])cl.push_back(id);
								else cr.push_back(id);
							}
							vals.erase(vals.begin() + r);
							vals.insert(vals.begin() + r, cr);
							vals.insert(vals.begin() + r, cl);
						}
						vector<int> cl;
						for (int id : v[x])if (trans[id] < 0)cl.push_back(id);
						vals.insert(vals.begin(), cl);
					}
					else {
						if (vals[l].size() != cnt[l]) {
							vector<int> cl, cr;
							for (int id : vals[l]) {
								if (isin[id])cr.push_back(id);
								else cl.push_back(id);
							}
							vals.erase(vals.begin() + l);
							vals.insert(vals.begin() + l, cr);
							vals.insert(vals.begin() + l, cl);
						}
						vector<int> cr;
						for (int id : v[x])if (trans[id] < 0)cr.push_back(id);
						vals.push_back(cr);
					}
				}
				else {
					if (l < r) {
						if (vals[r].size() != cnt[r]) {
							vector<int> cl, cr;
							for (int id : vals[r]) {
								if (isin[id])cl.push_back(id);
								else cr.push_back(id);
							}
							vals.erase(vals.begin() + r);
							vals.insert(vals.begin() + r, cr);
							vals.insert(vals.begin() + r, cl);
						}
						if (vals[l].size() != cnt[l]) {
							vector<int> cl, cr;
							for (int id : vals[l]) {
								if (isin[id])cr.push_back(id);
								else cl.push_back(id);
							}
							vals.erase(vals.begin() + l);
							vals.insert(vals.begin() + l, cr);
							vals.insert(vals.begin() + l, cl);
						}
					}
					else {
						return false;
					}
				}
				exiz = true;
				return true;
			};
			vector<int> zr;
			while (!q.empty()) {
				int x = q.top().second; q.pop();
				for (int id : v[x])for (int iid : ids[id]) {
					if (!used[iid]) {
						q.push({ v[iid].size(),iid });
						used[iid] = true;
					}
				}
				if (!merge(x)) {
					zr.push_back(x);
				}
			}
			while (zr.size()) {
				bool fin = false;
				rep(j, zr.size()) {
					if (merge(zr[j])) {
						zr.erase(zr.begin() + j);
						fin = true; break;
					}
				}
				if (!fin)break;
			}
			//cout << "?? " << zr.size() << "\n";
			for (int id : zr) {
				used[id] = false;
			}
			vector<vector<int>> zid(vals.size());
			vector<int> trans(n);
			rep(i, vals.size())rep(j, vals[i].size())trans[vals[i][j]] = i;
			for (int id : zr) {
				zid[trans[v[id][0]]].push_back(id);
			}
			vector<bool> aft(n);
			for (int id : zr)for (int iid : v[id])aft[iid] = true;
			rep(i, vals.size()) {
				vector<P> nv;
				for (int id : zid[i])nv.push_back({ v[id].size(),id });
				sort(all(nv), greater<P>());
				rep(j, nv.size()) {
					zid[i][j] = nv[j].second;
				}
				int c = dfs(zid[i]);
				for (int id : vals[i])if (!aft[id]) {
					pro *= c + 1;
					c++;
				}
			}
			//cout << exiz << "\n";
			if(exiz)pro *= 2;
		}
		pro *= fact[cnt];
		return cnt;
	};
	vector<int> ori(m);
	rep(i, m) {
		ori[i] = vv[i].second;
	}
	int c=dfs(ori);
	vector<int> exi(n);
	rep(i, m)rep(j, v[i].size())exi[v[i][j]] = true;
	rep(i, n)if(!exi[i]) {
		pro *= c + 1; c++;
	}
	cout << pro << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(12);
	init_f();
	//init();
	//expr();
	//int t; cin >> t; rep(i, t)
	solve();
	return 0;
}