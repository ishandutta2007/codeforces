#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double db;
typedef long double ldb;
typedef complex<double> cd;

const ll INF64 = 9'000'000'000'000'000'000, INF32 = 2'000'000'000, MOD = 998'244'353;
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
	ll n;
	cin >> n;
	vector<ll> mind(n + 1, -1);
	vector<ll> primes;
	for (ll i = 2; i <= n; i++) {
		if (mind[i] == -1) {
			mind[i] = primes.size();
			primes.push_back(i);
		}
		for (ll j = 0; (i * primes[j] <= n) && (j <= mind[i]); j++) {
			mind[i * primes[j]] = j;
		}
	}
	vector<ll> col(n + 1, 1), ans(n + 1, 1), pref(n + 1, 1);
	for (ll i = 2; i <= n; i++) {
		ll now = i, c = 1;
		ll md = primes[mind[i]];
		while (now % md == 0) {
			now /= md;
			c++;
		}
		col[i] = col[now] * c;
		ans[i] = (pref[i - 1] + col[i]) % MOD;
		pref[i] = (ans[i] + pref[i - 1]) % MOD;
	}
	cout << ans[n] << '\n';
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