#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double db;
typedef long double ldb;
typedef complex<double> cd;

const ll INF64 = 9'000'000'000'000'000'000, INF32 = 2'000'000'000, MOD = 1'000'000'007;
const db PI = acos(-1);

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

void solve() {
	ll n, m;
	cin >> n >> m;
	vector<vector<pair<ll, ll>>> arr(n);
	for (ll i = 0; i < m; i++) {
		ll a, b, c;
		cin >> a >> b >> c;
		arr[a].push_back(make_pair(b, c));
	}
	for (ll i = 0; i < n; i++) {
		vector<ll> dist(n, INF32);
		vector<bool> used(n, false);
		for (auto[b, c] : arr[i]) {
			dist[b] = c;
		}
		for (ll j = 0; j < n; j++) {
			ll md = INF32, mv = 0;
			for (ll k = 0; k < n; k++) {
				if (!used[k] && assign_min(md, dist[k])) {
					mv = k;
				}
			}
			used[mv] = true;
			assign_min(dist[(mv + 1) % n], dist[mv] + 1);
			for (auto[b, c] : arr[mv]) {
				assign_min(dist[(b + md) % n], dist[mv] + c);
			}
		}
		assign_min(dist[i], 0ll);
		for (auto j : dist) {
			cout << j << ' ';
		}
		cout << '\n';
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