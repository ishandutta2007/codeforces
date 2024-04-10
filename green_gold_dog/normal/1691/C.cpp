#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double db;
typedef long double ldb;
typedef complex<double> cd;

const ll INF64 = 9'000'000'000'000'000'000, INF32 = 2'000'000'000, MOD = 1'000'000'007;
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
	ll n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	ll ans = 0;
	for (auto i : s) {
		ans += (i - '0') * 11;
	}
	for (ll i = n - 1; i >= 0 && n - i - 1 <= k; i--) {
		if (s[i] == '1') {
			swap(s[i], s[n - 1]);
			k -= n - i - 1;
			ans -= 10;
			break;
		}
	}
	for (ll i = 0; i < n - 1 && i <= k; i++) {
		if (s[i] == '1') {
			swap(s[0], s[i]);
			k -= i;
			ans -= 1;
			break;
		}
	}
	cout << ans << '\n';
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