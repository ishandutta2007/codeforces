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
const int max_n = 1<<1;
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




vector<int> trans;
struct edge {
	int to, cost;
};
struct Centroid_Decomposition {
private:
	int n;
	vector<vector<edge>> G;

	vector<vector<int>> fG; int root;
	vector<int> par, parid;
	vector<vector<vector<ll>>> dists;
	vector<vector<vector<int>>> ids;
	vector<vector<ll>> pdist;
	vector<vector<int>> pid;
	vector<vector<LP>> pars;

	vector<ll> dep;
public:
	Centroid_Decomposition(int n_) {
		n = n_;
		G.resize(n);
		par.resize(n);
		parid.resize(n);
		pars.resize(n);

		fG.resize(n); root = -1;
		dists.resize(n);
		ids.resize(n);
		pdist.resize(n);
		pid.resize(n);
	}
	void add_edge(int a, int b,int c) {
		G[a].push_back({ b,c });
		G[b].push_back({ a,c });
	}

	void complete() {
		vector<int> exi(n, 0);
		vector<int> ori(n); rep(i, n)ori[i] = i;


		int tmp = 0;
		function<int(int, int, int&, int&)> szdfs = [&](int id, int fr, int& g, int& sz)->int {
			int res = 1;
			int ma = 0;
			for (edge e : G[id]) {
				if (tmp != exi[e.to])continue;
				if (e.to == fr)continue;
				int nex = szdfs(e.to, id, g, sz);
				ma = max(ma, nex);
				res += nex;
			}
			if (ma <= sz / 2 && sz - res <= sz / 2)g = id;
			return res;
		};

		function<int(vector<int>)> cdfs = [&](vector<int> v)->int {
			tmp++;
			if (v.empty())return 0;

			for (int id : v) {
				exi[id]++;
			}
			int g;
			int sz = v.size();
			szdfs(v[0], -1, g, sz);

			pdist[g].push_back(0);
			pid[g].push_back(trans[g]);
			pars[g].push_back({ g,0 });

			for (edge e : G[g]) {
				if (!exi[e.to])continue;
				if (exi[e.to] != tmp)continue;
				int t = dists[g].size();
				dists[g].push_back({});
				ids[g].push_back({});

				queue<pair<P,ll>> vs;
				vs.push({ {e.to,g},e.cost });
				vector<int> nex;
				while (!vs.empty()) {
					pair<P, ll> p = vs.front(); vs.pop();
					int v = p.first.first, fr = p.first.second;
					nex.push_back(v);
					pdist[g].push_back(p.second);
					pid[g].push_back(trans[v]);
					dists[g][t].push_back(p.second);
					ids[g][t].push_back(trans[v]);
					pars[v].push_back({ g,p.second });
					for (edge e : G[v]) {
						if (e.to == fr)continue;
						if (tmp != exi[e.to])continue;
						vs.push({ { e.to,v },p.second + e.cost });
					}
				}

				int ng = cdfs(nex);
				fG[g].push_back(ng);
				par[ng] = g;
				parid[ng] = t;

			}
			for (int id : v) {
				exi[id]--;
			}
			tmp--;
			return g;
		};
		root = cdfs(ori); par[root] = -1;
		auto yaru = [&](vector<int>& id, vector<ll>& dist) {
			vector<LP> cop(id.size());
			rep(j, id.size()) {
				cop[j] = { id[j],dist[j] };
			}
			sort(all(cop));
			ll sum = 0;
			rep(j, id.size()) {
				dist[j] = sum;
				id[j] = cop[j].first;
				sum += cop[j].second;
			}
			dist.push_back(sum);
		};
		rep(i, n) {
			//pdist
			yaru(pid[i], pdist[i]);

			//dists
			rep(j, dists[i].size()) {
				yaru(ids[i][j], dists[i][j]);
			}
		}



		dep.resize(n);
		dep[0] = 0;
		function<void(int, int)> depdfs = [&](int id, int fr) {
			for (edge e : G[id])if (e.to != fr) {
				dep[e.to] = dep[id] + e.cost;
				depdfs(e.to, id);
			}
		}; depdfs(0, -1);
	}
	void chupd(vector<int>& v,vector<ll> &dist, int loc) {
		if (loc > 0 && v[loc - 1] >= v[loc]) {
			//cout << "hello\n";
			swap(v[loc - 1], v[loc]);
			ll d2 = dist[loc + 1] - dist[loc];
			dist[loc] = dist[loc - 1] + d2;
		}
		else if (loc + 1 < v.size() && v[loc] >= v[loc + 1]) {
			//cout << "hello\n";
			swap(v[loc], v[loc + 1]);
			ll d2 = dist[loc + 2] - dist[loc + 1];
			dist[loc + 1] = dist[loc] + d2;
		}
	}
	void upd(int c,bool isadd) {
		int loc = trans[c];
		int coef = -1;
		if (isadd)coef = 1;
		int g = c;
		int id;
		while (g >= 0) {
			int t = lower_bound(all(pid[g]), loc) - pid[g].begin();
			pid[g][t] += coef;
			if(isadd)chupd(pid[g], pdist[g],t);
			if (g == c) {

			}
			else {
				t = lower_bound(all(ids[g][id]), loc) - ids[g][id].begin();
				ids[g][id][t] += coef;
				if(isadd)chupd(ids[g][id],dists[g][id], t);
			}
			id = parid[g];
			g = par[g];
		}
	}
	ll getsum(int c, int l,int r) {
		ll res = 0;
		int g = c;
		int id;
		int tmp = pars[c].size() - 1;
		while (g >= 0) {
			/*rep(j, pid[g].size() - 1) {
				assert(pid[g][j] < pid[g][j + 1]);
			}*/
			if (g == c) {
				//cout << "?? " << g << "\n";
				int t = lower_bound(all(pid[g]), r) - pid[g].begin();
				res += pdist[g][t];
				t = lower_bound(all(pid[g]), l) - pid[g].begin();
				res -= pdist[g][t];
			}
			else {
				ll dec = pars[c][tmp].second;
				int t = lower_bound(all(pid[g]), r) - pid[g].begin();
				res += pdist[g][t] + dec * t;
				t = lower_bound(all(ids[g][id]), r) - ids[g][id].begin();
				res -= dists[g][id][t] + dec * t;
				t = lower_bound(all(pid[g]), l) - pid[g].begin();
				res -= pdist[g][t] + dec * t;
				t = lower_bound(all(ids[g][id]), l) - ids[g][id].begin();
				res += dists[g][id][t] + dec * t;
			}
			id = parid[g];
			g = par[g];
			tmp--;
		}
		return res;
	}
};



void solve() {
	int n, q; cin >> n >> q;
	vector<int> a(n);
	rep(i, n) {
		cin >> a[i]; a[i]--;
	}
	trans.resize(n);
	rep(i, n)trans[a[i]] = i;
	Centroid_Decomposition cd(n);
	rep(i, n - 1) {
		int a, b, c; cin >> a >> b >> c; a--; b--;
		cd.add_edge(a, b, c);
	}
	cd.complete();
	ll las = 0;
	rep(i, q) {
		las %= (1 << 30);
		int typ; cin >> typ;
		if (typ == 1) {
			int l, r, v; cin >> l >> r >> v;
			l ^= las;
			r ^= las;
			v ^= las;
			l--; r--; v--;
			ll ans = cd.getsum(v, l, r + 1);
			//cout << "ans is ";
			cout << ans << "\n";
			las = ans;
		}
		else {
			int x; cin >> x;
			x ^= las;
			x--;
			cd.upd(a[x], true);
			cd.upd(a[x + 1], false);
			trans[a[x]]++;
			trans[a[x + 1]]--;
			swap(a[x], a[x + 1]);
		}
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