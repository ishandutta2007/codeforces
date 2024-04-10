#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double db;
typedef long double ldb;
typedef complex<double> cd;

const ll INF64 = 9'000'000'000'000'000'000, INF32 = 2'000'000'000, MOD = 1'000'000'007;
const db PI = acos(-1);
const bool IS_FILE = false, IS_TEST_CASES = true;

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
	vector<tuple<ll, ll, ll>> all;
	for (ll i = 0; i < m; i++) {
		ll a, b, c;
		cin >> a >> b >> c;
		a--;
		b--;
		all.emplace_back(a, b, c);
		all.emplace_back(b, a, c);
		arr[a].push_back(make_pair(b, c));
		arr[b].push_back(make_pair(a, c));
	}
	vector<vector<ll>> d(n, vector<ll>(n, INF32));
	for (ll i = 0; i < n; i++) {
		d[i][i] = 0;
		queue<ll> q;
		q.push(i);
		while (!q.empty()) {
			ll x = q.front();
			q.pop();
			for (auto[a, c] : arr[x]) {
				if (assign_min(d[i][a], d[i][x] + 1)) {
					q.push(a);
				}
			}
		}
	}
	vector<ll> p(n, INF32);
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < n; j++) {
			assign_min(p[i], d[i][j] + 1 + d[j][0] + d[j][n - 1]);
		}
	}
	ll ans = INF64;
	for (auto[a, b, c] : all) {
		ll now = min(d[0][a] + d[b][n - 1], min(p[a], p[b])) + 1;
		assign_min(ans, now * c);
	}
	cout << ans << '\n';
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