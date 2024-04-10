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

bool dp[101][101][2][2];

void solve() {
	ll n;
	cin >> n;
	ll cc = 0, cn = 0;
	for (ll i = 0; i < n; i++) {
		ll x;
		cin >> x;
		cc += (x % 2) == 0;
		cn += (x % 2) != 0;
	}
	cout << (dp[cc][cn][0][0] ? "Alice" : "Bob") << '\n';
}

int main() {
	if (IS_FILE) {
		freopen("", "r", stdin);
		freopen("", "w", stdout);
	}
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	for (ll i = 0; i <= 100; i++) {
		dp[i][0][0][0] = true;
		dp[i][0][0][1] = false;
		dp[i][0][1][0] = false;
		dp[i][0][1][1] = true;
	}
	for (ll i = 0; i <= 100; i++) {
		dp[0][i][0][1] = ((i + 1) / 2) % 2;
		dp[0][i][0][0] = !dp[0][i][0][1];
		dp[0][i][1][0] = (i / 2) % 2;
		dp[0][i][1][1] = !dp[0][i][1][0];
	}
	for (ll i = 1; i <= 100; i++) {
		for (ll j = 1; j <= 100; j++) {
			dp[i][j][0][0] = !dp[i - 1][j][1][0] || !dp[i][j - 1][1][1];
			dp[i][j][0][1] = !dp[i - 1][j][1][1] || !dp[i][j - 1][1][0];
			dp[i][j][1][0] = !dp[i - 1][j][0][0] || !dp[i][j - 1][0][0];
			dp[i][j][1][1] = !dp[i - 1][j][0][1] || !dp[i][j - 1][0][1];
		}
	}
	ll t = 1;
	if (IS_TEST_CASES) {
		cin >> t;
	}
	for (ll i = 0; i < t; i++) {
		solve();
	}
}