#include<bits/stdc++.h>
#define FOR(i, n, m) for(int i = n; i < (int)m; i++)
#define REP(i, n) FOR(i, 0, n)
#define all(v) v.begin(), v.end()
#define pb push_back
using namespace std;
using ll = std::int_fast64_t;
using pi = pair<ll, ll>;
constexpr ll inf = 1000000000;
constexpr ll mod = 1000000007;
constexpr long double eps = 1e-15;
template<typename T1, typename T2>
ostream& operator<<(ostream& os, pair<T1, T2> p) {
	os << to_string(p.first) << " " << to_string(p.second);
	return os;
}
template<typename T>
ostream& operator<<(ostream& os, vector<T>& v) {
	REP(i, v.size()) {
		if(i) os << " ";
		os << to_string(v[i]);
	}
	return os;
}


//number//
ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

struct modint {
	ll n;
public:
	modint(const ll n = 0) : n((n % mod + mod) % mod) {}
	static modint pow(modint a, ll m) {
		// static vector<modint> v(1000010, -1);
		// if(m == mod - 2 && v[a.n] != -1) return v[a.n];
		// int tmp = a.n;
		modint r = 1;
		while(m > 0) {
			if(m & 1) { r *= a; }
			a = (a * a); m /= 2;
		}
		// if(m == mod - 2) return v[tmp] = r;
		return r;
	}
	modint &operator++() { *this += 1; return *this; }
	modint &operator--() { *this -= 1; return *this; }
	modint operator++(int) { modint ret = *this; *this += 1; return ret; }
	modint operator--(int) { modint ret = *this; *this -= 1; return ret; }
	modint operator~() const { return (this -> pow(n, mod - 2)); } // inverse
	friend bool operator==(const modint& lhs, const modint& rhs) {
		return lhs.n == rhs.n;
	}
	friend bool operator<(const modint& lhs, const modint& rhs) {
		return lhs.n < rhs.n;
	}
	friend bool operator>(const modint& lhs, const modint& rhs) {
		return lhs.n > rhs.n;
	}
	friend modint &operator+=(modint& lhs, const modint& rhs) {
		lhs.n += rhs.n;
		if (lhs.n >= mod) lhs.n -= mod;
		return lhs;
	}
	friend modint &operator-=(modint& lhs, const modint& rhs) {
		lhs.n -= rhs.n;
		if (lhs.n < 0) lhs.n += mod;
		return lhs;
	}
	friend modint &operator*=(modint& lhs, const modint& rhs) {
		lhs.n = (lhs.n * rhs.n) % mod;
		return lhs;
	}
	friend modint &operator/=(modint& lhs, const modint& rhs) {
		lhs.n = (lhs.n * (~rhs).n) % mod;
		return lhs;
	}
	friend modint operator+(const modint& lhs, const modint& rhs) {
		return modint(lhs.n + rhs.n);
	}
	friend modint operator-(const modint& lhs, const modint& rhs) {
		return modint(lhs.n - rhs.n);
	}
	friend modint operator*(const modint& lhs, const modint& rhs) {
		return modint(lhs.n * rhs.n);
	}
	friend modint operator/(const modint& lhs, const modint& rhs) {
		return modint(lhs.n * (~rhs).n);
	}
};
istream& operator>>(istream& is, modint m) { is >> m.n; return is; }
ostream& operator<<(ostream& os, modint m) { os << m.n; return os; }

struct binomial_coefficient {
private:
	int m;
	vector<modint> fact;
public:
	binomial_coefficient(int m) : m(m) {
		fact.resize(m);
		fact[0] = 1;
		for(int i = 1; i < m; i++) fact[i] = fact[i - 1] * i;
	}
	modint combination(int n, int k) {
		if(n < 0 || k < 0 || n < k) return 0;
		return fact[n] / fact[n - k] / fact[k];
	}
};


// graph //
using weight = long long;
struct edge { int to; weight w; };
template <typename T> struct vedge : edge { T v; };
struct graph {
private:
	int n;
	bool weighted;
	bool tree;
	vector<vector<edge>> g;
public:
	graph(int n, bool tree = false) : n(n), weighted(false), tree(tree), g(vector<vector<edge>>(n)) { }
	vector<edge>& operator[] (int i) { return g[i]; }
	int size() { return n; }
	bool isweighted() { return weighted; }
	bool istree() { return tree; }
	void add_edge(int s, int t, weight w = 1) {
		g[s].push_back({t, w});
		g[t].push_back({s, w});
		if(w != 1) weighted = true;
	}
	void add_dedge(int s, int t, weight w = 1) {
		g[s].push_back({t, w});
		if(w != 1) weighted = true;
	}
};
template <typename T> struct vgraph {
public:
private:
	int n;
	bool weighted;
	bool tree;
	vector<vector<vedge<T>>> g;
	vgraph(int n, bool tree = false) : n(n), weighted(false), tree(tree), g(vector<vector<vedge<T>>>(n)) { }
	vector<edge>& operator[] (int i) { return g[i]; }
	int size() { return n; }
	bool isweighted() { return weighted; }
	bool istree() { return tree; }
	void add_edge(int s, int t, T v, weight w = 1) {
		g[s].push_back({t, w, v});
		g[t].push_back({s, w, v});
		if(w != 1) weighted = true;
	}
	void add_dedge(int s, int t, T v, weight w = 1) {
		g[s].push_back({t, w, v});
		if(w != 1) weighted = true;
	}
	graph build_graph() {
		graph ret(n);
		for(auto v: g) for(auto e: g[v]) {
			ret.add_dedge(v, e.to, e.w);
		}
		return ret;
	}
};

vector<weight> shortest_path(graph& g, int s) {
	int n = g.size();
	vector<weight> path(n, -1);
	if(g.isweighted() && !g.istree()) { // dijkstra
		priority_queue<pair<weight, int>, vector<pair<weight, int>>, greater<pair<weight, int>>> q;
		path[s] = 0;
		q.push({0, s});
		while(!q.empty()) {
			weight cost = q.top().first;
			int p = q.top().second;
			q.pop();
			if(path[p] != cost) continue;
			for(auto e: g[p]) {
				if(path[e.to] == -1 || path[e.to] > cost + e.w) {
					path[e.to] = cost + e.w;
					q.push({path[e.to], e.to});
				}
			}
		}
	} else { // bfs
		queue<int> q;
		path[s] = 0;
		q.push(s);
		while(!q.empty()) {
			int p = q.front();
			q.pop();
			for(auto e: g[p]) {
				if(path[e.to] == -1) {
					path[e.to] = path[p] + 1;
					q.push(e.to);
				}
			}
		}
	}
	return path;
}


using mi = modint;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<ll> dp(10, -1);
	dp[0] = 0;
	REP(i, n) {
		int k;
		cin >> k;
		vector<ll> c1, c2, c3;
		REP(j, k) {
			ll c, d;
			cin >> c >> d;
			if(c == 1) c1.pb(d);
			if(c == 2) c2.pb(d);
			if(c == 3) c3.pb(d);
		}
		vector<ll> ndp(10, 0);
		REP(j, 10) ndp[j] = dp[j];
		sort(all(c1));
		sort(all(c2));
		sort(all(c3));
		REP(j, 4) REP(k, 4) REP(l, 4) {
			if(j == 0 && k == 0 && l == 0) continue;
			if(j * 1 + k * 2 + l * 3 > 3) continue;
			if(j > (int)c1.size() || k > (int)c2.size() || l > (int)c3.size()) continue;
			vector<ll> v;
			REP(m, j) v.pb(c1[(int)c1.size() - 1 - m]);
			REP(m, k) v.pb(c2[(int)c2.size() - 1 - m]);
			REP(m, l) v.pb(c3[(int)c3.size() - 1 - m]);
			ll sum = 0, mx = 0;
			REP(m, v.size()) {
				sum += v[m];
				mx = max(mx, v[m]);
			}
			REP(m, 10) {
				if(dp[(m - (j + k + l) + 10) % 10] == -1) continue;
				if(m - (j + k + l) < 0) {
					ndp[m] = max(ndp[m], dp[(m - (j + k + l) + 10) % 10] + (sum - mx) + 2 * mx);
				} else {
					ndp[m] = max(ndp[m], dp[(m - (j + k + l) + 10) % 10] + sum);
				}
			}
		}
		dp = ndp;
	}
	ll ans = 0;
	REP(i, 10) ans = max(ans, dp[i]);
	cout << ans << endl;
	return 0;
}

// ---------------------------------------