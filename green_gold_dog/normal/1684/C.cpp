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
	vector<vector<ll>> a(n, vector<ll>(m, 0));
	vector<ll> arr(m);
	ll p1 = -1, p2 = -1;
	for (ll j = 0; j < n; j++) {
		for (ll i = 0; i < m; i++) {
			cin >> arr[i];
			a[j][i] = arr[i];
		}
		vector<ll> sa = arr;
		sort(sa.begin(), sa.end());
		if (p1 == -1) {
			if (sa != arr) {
				for (ll i = 0; i < m; i++) {
					if (arr[i] != sa[i]) {
						if (p1 == -1) {
							p1 = i;
						} else {
							p2 = i;
						}
					}
				}
			}
		}
	}
	for (ll j = 0; j < n; j++) {
		vector<ll> sa = a[j];
		sort(sa.begin(), sa.end());
		if (p1 != -1) {
			swap(a[j][p1], a[j][p2]);
		}
		if (a[j] != sa) {
			cout << -1 << '\n';
			return;
		}
	}
	if (p1 == -1) {
		cout << 1 << ' ' << 1 << '\n';
	} else {
		cout << p1 + 1 << ' ' << p2 + 1 << '\n';
	}
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