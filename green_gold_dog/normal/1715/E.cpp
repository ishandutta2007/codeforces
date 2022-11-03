#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double db;
typedef long double ldb;
typedef complex<double> cd;

const ll INF64 = 1'000'000'000'000'000'000, INF32 = 2'000'000'000, MOD = 1'000'000'007;
const db PI = acos(-1);
const bool IS_FILE = false, IS_TEST_CASES = false;

random_device rd;
mt19937 rnd32(rd());
mt19937_64 rnd64(rd());

template<typename T>
bool assign_max(T& a, T b) {
	if (b > a) {
		a = b;
		return true;
	}
	return false;
}

template<typename T>
bool assign_min(T& a, T b) {
	if (b < a) {
		a = b;
		return true;
	}
	return false;
}

template<typename T>
T square(T a) {
	return a * a;
}

template<>
struct std::hash<pair<ll, ll>> {
	ll operator() (pair<ll, ll> p) {
		return ((__int128)p.first * MOD + p.second) % INF64;
	}
};

struct line {
	ll k, b;
	line(ll k = -INF64, ll b = INF64): k(k), b(b) {}
	double get(double x) {
		return x * k + b;
	}
	double operator* (line l) {
		return (l.b - b) / (double)(k - l.k);
	}
	ll get(ll x) {
		return x * k + b;
	}
};

struct CHT {
	vector<line> all;
	vector<double> per;
	ll last = 0;
	CHT() {
		all.push_back(line());
	}
	ll get(ll x) {
		while (last < all.size() && all[last].get(x) > all[last + 1].get(x)) {
			last++;
		}
		return all[last].get(x);
	}
	void insert(line l) {
		while (!per.empty() && l.get(per.back()) < all.back().get(per.back())) {
			all.pop_back();
			per.pop_back();
		}
		per.push_back(l * all.back());
		all.push_back(l);
	}
	void insert(ll v, ll x) {
		insert(line(-v * 2, v * v + x));
	}
};

void relax(vector<ll> &dist, vector<vector<pair<ll, ll>>> &arr) {
	set<pair<ll, ll>> s;
	ll n = dist.size();
	for (ll i = 0; i < n; i++) {
		s.insert(make_pair(dist[i], i));
	}
	while (!s.empty()) {
		auto[a, b] = *s.begin();
		s.erase(s.begin());
		if (a != dist[b]) {
			continue;
		}
		for (auto[v, c] : arr[b]) {
			if (assign_min(dist[v], a + c)) {
				s.insert(make_pair(dist[v], v));
			}
		}
	}
}

void solve() {
	ll n, m, k;
	cin >> n >> m >> k;
	vector<vector<pair<ll, ll>>> arr(n);
	for (ll i = 0; i < m; i++) {
		ll a, b, c;
		cin >> a >> b >> c;
		a--;
		b--;
		arr[a].emplace_back(b, c);
		arr[b].emplace_back(a, c);
	}
	vector<ll> dist(n, INF64);
	dist[0] = 0;
	relax(dist, arr);
	for (ll i = 0; i < k; i++) {
		CHT c;
		for (ll j = 0; j < n; j++) {
			c.insert(j, dist[j]);
		}
		for (ll j = 0; j < n; j++) {
			dist[j] = j * j + c.get(j);
		}
		relax(dist, arr);
	}
	for (ll i = 0; i < n; i++) {
		cout << dist[i] << ' ';
	}
	cout << '\n';
}

int main() {
	if (IS_FILE) {
		freopen("", "r", stdin);
		freopen("", "w", stdout);
	}
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll t = 1;
	if (IS_TEST_CASES) {
		cin >> t;
	}
	for (ll i = 0; i < t; i++) {
		solve();
	}
}