#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double db;
typedef long double ldb;
typedef complex<double> cd;

const ll INF64 = 9'000'000'000'000'000'000, INF32 = 2'000'000'000, MOD = 1'000'000'007;
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

void change(ll &ans, vector<ll> &arr, ll i, ll x) {
	ll n = arr.size();
	if (i == 0 && i == n - 1) {
		return;
	}
	if (x == arr[i]) {
		return;
	}
	if (i == 0) {
		if (arr[1] == arr[0]) {
			ans += n - 1;
		}
		if (arr[1] == x) {
			ans -= n - 1;
		}
		arr[i] = x;
		return;
	}
	if (i == n - 1) {
		if (arr[i] == arr[i - 1]) {
			ans += n - 1;
		}
		if (arr[i - 1] == x) {
			ans -= n - 1;
		}
		arr[i] = x;
		return;
	}
	if (arr[i] == arr[i - 1]) {
		ans += (n - i) * i;
	}
	if (x == arr[i - 1]) {
		ans -= (n - i) * i;
	}
	if (arr[i] == arr[i + 1]) {
		ans += (n - i - 1) * (i + 1);
	}
	if (x == arr[i + 1]) {
		ans -= (n - i - 1) * (i + 1);
	}
	arr[i] = x;
}

void solve() {
	ll n, m;
	cin >> n >> m;
	vector<ll> arr(n, 0);
	ll ans = n * (n + 1) / 2;
	for (ll i = 0; i < n; i++) {
		ll x;
		cin >> x;
		change(ans, arr, i, x);
	}
	for (ll i = 0; i < m; i++) {
		ll j, x;
		cin >> j >> x;
		j--;
		change(ans, arr, j, x);
		cout << ans << '\n';
	}
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