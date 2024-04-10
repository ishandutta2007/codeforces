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
	ll n;
	cin >> n;
	vector<pair<ll, ll>> arr(n);
	for (auto&[x, t] : arr) {
		cin >> x;
		x *= 2;
	}
	for (auto&[x, t] : arr) {
		cin >> t;
		t *= 2;
	}
	sort(arr.begin(), arr.end());
	vector<ll> pref(1, arr[0].second);
	for (ll i = 1; i < n; i++) {
		pref.push_back(max(pref.back() + arr[i].first - arr[i - 1].first, arr[i].second));
	}
	vector<ll> suf(1, arr.back().second);
	for (ll i = n - 2; i >= 0; i--) {
		suf.push_back(max(suf.back() + arr[i + 1].first - arr[i].first, arr[i].second));
	}
	reverse(suf.begin(), suf.end());
	ll ans = pref.back(), a = arr.back().first;
	for (ll i = 0; i < n - 1; i++) {
		if (assign_min(ans, max(max(pref[i], suf[i + 1]), (pref[i] + suf[i + 1] + arr[i + 1].first - arr[i].first) / 2))) {
			if (ans == pref[i]) {
				a = arr[i].first;
			} else {
				a = arr[i + 1].first - (ans - suf[i + 1]);
			}
		}
	}
	cout << a / 2 << (a % 2 == 1 ? ".5" : "") << '\n';
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