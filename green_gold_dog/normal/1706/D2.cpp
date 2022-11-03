#include <bits/stdc++.h>

using namespace std;

typedef int ll;
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

void solve() {
	ll n, k;
	cin >> n >> k;
	vector<ll> arr(n);
	for (ll i = 0; i < n; i++) {
		cin >> arr[i];
	}
	arr.resize(unique(arr.begin(), arr.end()) - arr.begin());
	ll ans = INF32;
	ll sq = min(arr[0], 1000);
	ll mi = arr[0];
	for (ll i = 1; i <= sq; i++) {
		ll ma = i;
		for (auto j : arr) {
			ll x = j / i;
			if (j / x < i) {
				x--;
			}
			assign_min(x, k);
			assign_max(ma, j / x);
		}
		assign_min(ans, ma - i);
	}
	if (sq != arr[0]) {
		vector<vector<ll>> be(arr.back() + 1);
		sq++;
		ll nm = sq;
		for (auto i : arr) {
			ll x = i / sq;
			if (i / x < sq) {
				x--;
			}
			assign_min(x, k);
			be[i / x].push_back(i);
			assign_max(nm, i / x);
		}
		arr.clear();
		assign_min(ans, nm - sq);
		for (ll i = sq + 1; i <= mi; i++) {
			for (ll l = 0; l < be[i - 1].size(); l++) {
				auto j = be[i - 1][l];
				ll x = j / (i + 1);
				if (j / x < (i + 1)) {
					x--;
				}
				be[j / x].push_back(j);
				assign_max(nm, j / x);
			}
			be[i - 1].clear();
			assign_min(ans, nm - i);
		}
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