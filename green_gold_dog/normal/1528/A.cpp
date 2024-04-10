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

void dfs(ll v, ll p, vector<vector<ll>>& g, vector<pair<ll, ll>>& arr, vector<ll>& dp1, vector<ll>& dp2) {
	for (auto i : g[v]) {
		if (i != p) {
			dfs(i, v, g, arr, dp1, dp2);
			dp1[v] += max(abs(arr[v].first - arr[i].first) + dp1[i], abs(arr[v].first - arr[i].second) + dp2[i]);
			dp2[v] += max(abs(arr[v].second - arr[i].first) + dp1[i], abs(arr[v].second - arr[i].second) + dp2[i]);
		}
	}
}

void solve() {
	ll n;
	cin >> n;
	vector<pair<ll, ll>> arr(n);
	for (ll i = 0; i < n; i++) {
		cin >> arr[i].first >> arr[i].second;
	}
	vector<vector<ll>> g(n);
	for (ll i = 1; i < n; i++) {
		ll a, b;
		cin >> a >> b;
		a--;
		b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	vector<ll> dp1(n, 0), dp2(n, 0);
	dfs(0, 0, g, arr, dp1, dp2);
	cout << max(dp1[0], dp2[0]) << '\n';
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll t = 1;
	cin >> t;
	for (ll i = 0; i < t; i++) {
		solve();
	}
}