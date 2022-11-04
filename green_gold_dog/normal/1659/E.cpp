#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double db;
typedef long double ldb;
typedef complex<double> cd;

const ll INF = 9'000'000'000'000'000'000;
const db PI = acos(-1);

mt19937 rnd32(time(0));
mt19937_64 rnd64(time(0));

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

struct DSU {
	vector<ll> p, s;
	vector<bool> eb1;
	DSU(ll n = 0) {
		p.resize(n, 0);
		s.resize(n, 1);
		eb1.resize(n, false);
		for (ll i = 0; i < n; i++) {
			p[i] = i;
		}
	}
	ll get(ll v) {
		return (p[v] == v ? v : p[v] = get(p[v]));
	}
	bool check(ll v) {
		return eb1[get(v)];
	}
	void unite(ll a, ll b, ll w) {
		a = get(a);
		b = get(b);
		if (s[a] < s[b]) {
			swap(a, b);
		}
		s[a] += s[b];
		p[b] = a;
		eb1[a] = eb1[a] | eb1[b];
		if ((w & 1) == 0) {
			eb1[a] = true;
		}
	}
};

void solve() {
	ll log = 31;
	ll n, m;
	cin >> n >> m;
	vector<vector<pair<ll, ll>>> arr(n);
	vector<tuple<ll, ll, ll>> all;
	for (ll i = 0; i < m; i++) {
		ll a, b, w;
		cin >> a >> b >> w;
		a--;
		b--;
		all.emplace_back(a, b, w);
		arr[a].emplace_back(b, w);
		arr[b].emplace_back(a, w);
	}
	vector<DSU> c0(log, DSU(n));
	for (ll i = 0; i < log; i++) {
		for (auto[a, b, w] : all) {
			if (!(w & 1)) {
				c0[i].eb1[a] = true;
				c0[i].eb1[b] = true;
			}
		}
		for (auto[a, b, w] : all) {
			if (w & (1 << i)) {
				c0[i].unite(a, b, w);
			}
		}
		//for (auto[a, b, w] : all) {
		//	if (c0[i].get(a) == c0[i].get(b)) {
		//		c0[i].unite(a, b, w);
		//	}
		//}
	}
	ll q;
	cin >> q;
	for (ll i = 0; i < q; i++) {
		ll a, b;
		cin >> a >> b;
		a--;
		b--;
		bool f = false;
		for (ll j = 0; j < log; j++) {
			if (c0[j].get(a) == c0[j].get(b)) {
				f = true;
				break;
			}
		}
		if (f) {
			cout << 0 << '\n';
		} else {
			f = false;
			for (ll j = 1; j < log; j++) {
				if (c0[j].check(a)) {
					f = true;
					break;
				}
			}
			cout << (f ? 1 : 2) << '\n';
		}
	}
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll t = 1;
	//cin >> t;
	for (ll i = 0; i < t; i++) {
		solve();
	}
}