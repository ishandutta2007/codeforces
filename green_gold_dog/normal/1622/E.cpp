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
	ll n, m;
	cin >> n >> m;
	vector<ll> o(n, 0);
	for (ll i = 0; i < n; i++) {
		cin >> o[i];
	}
	vector<string> solved(n);
	for (ll i = 0; i < n; i++) {
		cin >> solved[i];
	}
	ll ans = -INF64;
	vector<ll> a;
	for (ll i = 0; i < (1 << n); i++) {
		bool b = true;
		vector<pair<ll, ll>> cost(m);
		for (ll j = 0; j < m; j++) {
			cost[j].first = 0;
			for (ll k = 0; k < n; k++) {
				cost[j].first += (solved[k][j] == '1') * (((i >> k) & 1) ? 1 : -1);
			}
			cost[j].second = j;
		}
		sort(cost.begin(), cost.end());
		vector<ll> na(m);
		ll nans = 0;
		for (ll j = 0; j < m; j++) {
			nans += (j + 1) * cost[j].first;
			na[cost[j].second] = j + 1;
		}
		for (ll j = 0; j < n; j++) {
			ll sum = 0;
			for (ll k = 0; k < m; k++) {
				sum += (solved[j][k] == '1') * na[k];
			}
			if ((i >> j) & 1) {
				//if (sum < o[j]) {
				//	b = false;
				//}
				nans -= o[j];
			} else {
				//if (sum > o[j]) {
				//	b = false;
				//}
				nans += o[j];
			}
		}
		if (b && assign_max(ans, nans)) {
			a = na;
		}
	}
	for (auto i : a) {
		cout << i << ' ';
	}
	cout << '\n';
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