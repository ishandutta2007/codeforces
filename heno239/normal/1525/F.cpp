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
const int max_n = 1 << 1;
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
struct edge { int to; ll cap; int rev; };
struct Dinic {
private:
	int n;
	vector<vector<edge>> v;
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
				edge& e = v[x][i];
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
			edge& e = v[x][i];
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
	vector<int> query(int s) {
		vector<bool> used(n);
		used[s] = true;
		queue<int> q;
		q.push(s);
		while (!q.empty()) {
			int id = q.front(); q.pop();
			for (edge e : v[id])if (e.cap > 0) {
				if (!used[e.to]) {
					used[e.to] = true;
					q.push(e.to);
				}
			}
		}
		vector<int> res;
		rep(i, s / 2) {
			if (!used[i])res.push_back(i);
			if (used[i + s / 2])res.push_back(i + s / 2);
		}
		return res;
	}
};

void solve() {
	int n, m, k; cin >> n >> m >> k;
	vector<vector<int>> G(n);
	rep(i, m) {
		int a, b; cin >> a >> b; a--; b--;
		G[a].push_back(b);
	}
	vector<int> x(k), y(k);
	rep(i, k)cin >> x[i] >> y[i];
	int sz = 2 * n + 2;
	Dinic dc(sz);
	rep(i, n)for (int to : G[i]) {
		dc.addedge(to, i + n, mod);
	}
	rep(i, n) {
		dc.addedge(2 * n, i, 1);
		dc.addedge(i + n, 2 * n + 1, 1);
	}
	int f=dc.max_flow(2 * n, 2 * n + 1);
	vector<int> v = dc.query(2*n);
	int dif = n - 1 - k;
	rep(i, dif)if (v.size())v.pop_back();
	rep(i, v.size()) {
		if (v[i] >= n) {
			v[i] -= n; v[i]++;
		}
		else {
			v[i] *= -1; v[i]--;
		}
	}
	vector<int> mi(k), mito(k);
	rep(i, k) {
		mi[i] = y[i], mito[i] = i;
		if (i > 0) {
			if (mi[i] > mi[i - 1]) {
				mi[i] = mi[i - 1];
				mito[i] = mito[i - 1];
			}
		}
	}
	vector<int> cnt(k);
	rep(i, v.size()) {
		cnt[mito[k - 1 - i]]++;
	}
	ll score = 0;
	vector<int> ans;
	int loc = 0;
	rep(i, k) {
		score +=max(0ll, x[i] - (ll)cnt[i] * y[i]);
		rep(j, cnt[i]) {
			ans.push_back(v[loc]); loc++;
		}
		ans.push_back(0);
	}
	rep(g, k) {
		ll sum = 0;
		vector<int> c(k);
		vector<int> cans;
		rep(i, v.size()) {
			int id = k - 1 - i;
			if (id < g) {
				c[mito[id]]++;
			}
			else {
				c[g]++;
			}
		}
		int tmp = 0;
		rep(i, k) {
			sum += max(0ll,x[i] - (ll)c[i] * y[i]);
			rep(j, c[i]) {
				cans.push_back(v[tmp]); tmp++;
			}
			cans.push_back(0);
		}
		if (score < sum) {
			//cout << "! " << score << " " << sum << "\n";
			swap(score, sum);
			swap(cans, ans);
		}
	}
	cout << ans.size() << "\n";
	rep(i, ans.size()) {
		if (i > 0)cout << " "; cout << ans[i];
	}cout << "\n";
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