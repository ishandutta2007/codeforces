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

void dfs(ll v, ll p, vector<ll>& f, vector<vector<ll>>& arr) {
	if (f[v] == 0) {
		f[v] = f[p] / arr[p].size();
	}
	for (auto i : arr[v]) {
		dfs(i, v, f, arr);
	}
}

void dfs2(ll v, vector<ll> &s, vector<ll> &f, vector<ll>& dp0, vector<ll>& dp1, vector<vector<ll>>& arr) {
	dp0[v] = f[v] * s[v];
	dp1[v] = (f[v] + 1) * s[v];
	if (arr[v].size() == 0) {
		return;
	}
	ll ost = f[v] % arr[v].size();
	vector<ll> all;
	for (auto i : arr[v]) {
		dfs2(i, s, f, dp0, dp1, arr);
		dp0[v] += dp0[i];
		dp1[v] += dp0[i];
		all.push_back(dp1[i] - dp0[i]);
	}
	sort(all.begin(), all.end());
	reverse(all.begin(), all.end());
	for (ll i = 0; i < ost; i++)  {
		dp0[v] += all[i];
		dp1[v] += all[i];
	}
	dp1[v] += all[ost];
}

void solve() {
	ll n, k;
	cin >> n >> k;
	vector<vector<ll>> arr(n);
	for (ll i = 1; i < n; i++) {
		ll p;
		cin >> p;
		p--;
		arr[p].push_back(i);
	}
	vector<ll> s(n, 0);
	for (ll i = 0; i < n; i++) {
		cin >> s[i];
	}
	vector<ll> f(n, 0);
	f[0] = k;
	dfs(0, 0, f, arr);
	vector<ll> dp0(n), dp1(n);
	dfs2(0, s, f, dp0, dp1, arr);
	cout << dp0[0] << '\n';
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