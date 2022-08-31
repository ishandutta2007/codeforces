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
const int max_n = 1 << 18;
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


struct edge2 { int to; ll cap; int rev; };
struct Dinic {
private:
	int n;
	vector<vector<edge2>> v;
	vector<int> dist, iter;
public:
	Dinic(int sz) :n(sz), v(sz), dist(sz), iter(sz) {}

	void addedge(int from, int to, ll cap) {
		int x = v[to].size(), y = v[from].size();
		v[from].push_back({ to,cap,x });
		v[to].push_back({ from,0,y });
	}

	void bfs(int s) {
		fill(dist.begin(), dist.end(), -1);
		queue<int> q;
		dist[s] = 0;
		q.push(s);
		while (q.size()) {
			int x = q.front(); q.pop();
			rep(i, v[x].size()) {
				edge2& e = v[x][i];
				if (e.cap > 0 && dist[e.to] < 0) {
					dist[e.to] = dist[x] + 1;
					q.push(e.to);
				}
			}
		}
	}

	ll dfs(int x, int t, ll f) {
		if (x == t)return f;
		for (int& i = iter[x]; i < (int)v[x].size(); ++i) {
			edge2& e = v[x][i];
			if (e.cap > 0 && dist[x] < dist[e.to]) {
				ll d = dfs(e.to, t, min(f, e.cap));
				if (d > 0) {
					e.cap -= d;
					v[e.to][e.rev].cap += d;
					return d;
				}
			}
		}
		return 0;
	}

	ll max_flow(int s, int t) {
		ll flow = 0;
		while (1) {
			bfs(s);
			if (dist[t] < 0)return flow;
			fill(iter.begin(), iter.end(), 0);
			ll f;
			while ((f = dfs(s, t, 1LL << 62)) > 0)flow += f;
		}
	}
	vector<int> tos(int le, int ri) {
		vector<int> res;
		for (int i = le; i < ri; i++)for (edge2 e : v[i]) {
			if (e.cap == 0 && e.to < le) {
				res.push_back(e.to);
			}
		}
		return res;
	}
};

struct edge {
	int to, c, t,id;
};
void solve() {
	int n, m; cin >> n >> m;
	vector<int> a(m), b(m), c(m), t(m);
	rep(i, m) {
		cin >> a[i] >> b[i] >> c[i] >> t[i];
		a[i]--; b[i]--;
	}
	vector<int> col = c;
	sort(all(col));
	col.erase(unique(all(col)), col.end());
	rep(i, m) {
		c[i] = lower_bound(all(col), c[i]) - col.begin();
	}
	vector<int> tim = t; tim.push_back(0);
	sort(all(tim));
	tim.erase(unique(all(tim)), tim.end());
	rep(i, m) {
		t[i] = lower_bound(all(tim), t[i]) - tim.begin();
	}
	vector<vector<int>> cs(col.size());
	rep(i, m) {
		cs[c[i]].push_back(i);
	}
	vector<int> num(n);
	vector<bool> used(n);

	vector<vector<edge>> g(n);
	int ans = 0;
	vector<pair<P, P>> mem1;
	vector<pair<vector<int>, vector<int>>>memid1;
	vector<pair<P, P>> mem2;
	vector<pair<vector<int>, vector<int>>>memid2;
	vector<int> ansid;
	rep(i, col.size()) {
		vector<int> ids;
		for (int id : cs[i]) {
			g[a[id]].push_back({ b[id],c[id],t[id],id });
			g[b[id]].push_back({ a[id],c[id],t[id],id });
			ids.push_back(a[id]);
			ids.push_back(b[id]);
		}
		sort(all(ids));
		ids.erase(unique(all(ids)), ids.end());
		queue<int> q;
		rep(j, ids.size()) {
			if (used[ids[j]])continue;
			q.push(ids[j]);
			used[ids[j]] = true;
			vector<int> cur;
			while (!q.empty()) {
				int v = q.front(); q.pop();
				cur.push_back(v);
				for (edge e : g[v]) {
					if (!used[e.to]) {
						used[e.to] = true;
						q.push(e.to);
					}
				}
			}
			int cnt = 0;
			for (int id : cur) {
				if (g[id].size() > 2) {
					cout << "No\n"; return;
				}
				cnt += g[id].size();
			}
			cnt /= 2;
			if (cnt == 1)continue;
			if (cnt > cur.size()) {
				cout << "No\n"; return;
			}
			else {
				int start = cur[0];
				for (int id : cur)if (g[id].size() == 1)start = id;
				vector<int> rw;
				rw.push_back(start);
				rw.push_back(g[start][0].to);
				int fr = start, sc = g[start][0].to;
				vector<int> costs; vector<int> ansids;
				costs.push_back(g[start][0].t);
				ansids.push_back(g[start][0].id);
				rep(j, cur.size() - 2) {
					int nex;
					if (g[sc][0].to != fr) {
						nex = g[sc][0].to;
						costs.push_back(g[sc][0].t);
						ansids.push_back(g[sc][0].id);
					}
					else {
						nex = g[sc][1].to;
						costs.push_back(g[sc][1].t);
						ansids.push_back(g[sc][1].id);
					}
					rw.push_back(nex);
					fr = sc, sc = nex;
				}
				if (cnt == cur.size()) {
					costs.push_back(g[start][1].t);
					ansids.push_back(g[start][1].id);
				}
				int t0 = 0, t1 = 0;
				rep(i, costs.size()) {
					if (i % 2 == 0)t0 = max(t0, costs[i]);
					else t1 = max(t1, costs[i]);
				}
				if (cnt == cur.size()) {
					if (cur.size() % 2) {
						cout << "No\n"; return;
					}
					else {
						for (int id : cur)num[id]++;
						ans = max(ans, min(tim[t0],tim[t1]));
						if (t0 < t1) {
							for (int j = 0; j < ansids.size();j+=2) {
								ansid.push_back(ansids[j]);
							}
						}
						else {
							for (int j = 1; j < ansids.size(); j += 2) {
								ansid.push_back(ansids[j]);
							}
						}
					}
				}
				else {
					vector<int> ev, od;
					rep(j, ansids.size()) {
						if (j % 2 == 0)ev.push_back(ansids[j]);
						else od.push_back(ansids[j]);
					}
					for (int j = 1; j < rw.size() - 1; j++)num[rw[j]]++;
					if (rw.size() % 2 == 0) {
						mem2.push_back({ {t0,t1},{rw[0],rw.back() } });
						memid2.push_back({ ev,od });
					}
					else {
						mem1.push_back({ {t0,t1},{rw[0],rw.back()} });
						memid1.push_back({ ev,od });
					}
				}
			}
			
		}

		for (int id : ids) {
			used[id] = false;
			g[id].clear();
		}
	}
	rep(i, n)if (num[i] > 1) {
		cout << "No\n"; return;
	}
	vector<int> rnum(n);
	for (int id : ansid) {
		rnum[a[id]]++;
		rnum[b[id]]++;
	}
	rep(i, n) {
		assert(num[i] >= rnum[i]);
	}
	int le = -1, ri = tim.size();
	while (ri - le > 1) {
		int mid = (le + ri) / 2;
		//can with lower or equal to mid time
		Dinic dc(n+mem1.size()+2);
		vector<int> cop = num;
		bool valid = true;
		for (auto p : mem2) {
			if (p.first.second<=mid) {
				//
			}
			else {
				if (p.first.first <= mid) {
					cop[p.second.first]++;
					cop[p.second.second]++;
				}
				else {
					valid = false;
				}
			}
		}
		rep(i, n)if (cop[i] > 1)valid = false;
		int sta = n+mem1.size(), goa = n +mem1.size()+ 1;
		if (valid) {
			rep(i, mem1.size()) {
				auto p = mem1[i];
				dc.addedge(sta, i + n, 1);
				if (p.first.first <= mid) {
					dc.addedge(i + n, p.second.first, 1);
				}
				if (p.first.second <= mid) {
					dc.addedge(i + n, p.second.second, 1);
				}
			}
			rep(i, n)if (cop[i] == 0)dc.addedge(i, goa, 1);
			int f = dc.max_flow(sta, goa);
			//cout << "? " << mid << " " << f <<" "<<mem1.size()<< "\n";
			if (f != mem1.size())valid = false;
		}
		if (valid)ri = mid;
		else le = mid;
	}
	if (ri == tim.size()) {
		cout << "No" << "\n"; return;
	}
	int mid = ri;
	Dinic dc(n + mem1.size() + 2);
	vector<int> cop = num;
	rep(i, mem2.size()) {
		auto p = mem2[i];
		if (p.first.second <= mid) {
			for (int id : memid2[i].second) {
				ansid.push_back(id);
			}
		}
		else {
			if (p.first.first <= mid) {
				cop[p.second.first]++;
				cop[p.second.second]++;
				for (int id : memid2[i].first) {
					ansid.push_back(id);
				}
			}
		}
	}
	int sta = n+mem1.size(), goa = n +mem1.size()+ 1;
	rep(i, mem1.size()) {
		auto p = mem1[i];
		dc.addedge(sta, i + n, 1);
		if (p.first.first <= mid) {
			dc.addedge(i + n, p.second.first, 1);
		}
		if (p.first.second <= mid) {
			dc.addedge(i + n, p.second.second, 1);
		}
	}
	rep(i, n)if (cop[i] == 0)dc.addedge(i, goa, 1);
	int f = dc.max_flow(sta, goa);
	vector<int> ts = dc.tos(n, n + mem1.size());
	rep(i, mem1.size()) {
		auto p = mem1[i];
		if (p.second.first == ts[i]) {
			for (int id : memid1[i].first)ansid.push_back(id);
		}
		else {
			for (int id : memid1[i].second)ansid.push_back(id);
		}
	}
	ans = max(ans, tim[ri]);
	cout << "Yes\n";
	cout << ans << " " << ansid.size() << "\n";
	sort(all(ansid));
	rep(j, ansid.size()) {
		if (j > 0)cout << " "; cout << ansid[j] + 1;
	}cout << "\n";
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