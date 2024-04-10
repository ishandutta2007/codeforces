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
	int m = 2750132;
	vector<bool> used(m, false);
	unordered_map<int, int> dict;
	int c = 1;
	FOR(i, 2, m) {
		if(!used[i]) {
			dict[i] = c;
			c++;
			for(int j = 2; i * j < m; j++) {
				used[i * j] = true;
			}
		}
	}
	set<pair<int, int>> s;
	REP(i, 2 * n) {
		int b;
		cin >> b;
		s.insert({b, i});
	}
	vector<int> a;
	while(!s.empty()) {
		auto p = *(--s.end());
		int d = -1;
		for(int i = 2; i * i <= p.first; i++) {
			if(p.first % i == 0) {
				d = p.first / i;
				break;
			}
		}
		if(d == -1) {
			a.pb(dict[p.first]);
			auto ite = s.lower_bound({dict[p.first], -1});
			s.erase(ite);
			s.erase(--s.end());
		} else {
			a.pb(p.first);
			auto ite = s.lower_bound({d, -1});
			s.erase(ite);
			s.erase(--s.end());
		}
	}
	cout << a << endl;
	return 0;
}

// ---------------------------------------