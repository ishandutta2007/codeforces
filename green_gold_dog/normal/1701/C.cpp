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

bool check(vector<ll> cols, ll t) {
	ll ns = 0;
	for (ll i = 0; i < cols.size(); i++) {
		if (cols[i] >= t) {
			ns += cols[i] - t;
		} else {
			ns -= (t - cols[i]) / 2;
		}
	}
	return ns <= 0;
}

void solve() {
	ll n, m;
	cin >> n >> m;
	vector<ll> cols(n, 0);
	for (ll i = 0; i < m; i++) {
		ll x;
		cin >> x;
		x--;
		cols[x]++;
	}
	sort(cols.begin(), cols.end());
	ll l = 0, r = 2 * m;
	while (r - l > 1) {
		ll mid = (l + r) / 2;
		if (check(cols, mid)) {
			r = mid;
		} else {
			l = mid;
		}
	}
	cout << r << '\n';
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