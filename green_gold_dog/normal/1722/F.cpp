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
	ll n, m;
	cin >> n >> m;
	vector<vector<char>> arr(n + 2, vector<char>(m + 2, '.'));
	for (ll i = 1; i <= n; i++) {
		for (ll j = 1; j <= m; j++) {
			cin >> arr[i][j];
		}
	}
	vector<vector<set<pair<ll, ll>>>> sos(n + 2, vector<set<pair<ll, ll>>>(m + 2));
	for (ll i = 1; i <= n; i++) {
		for (ll j = 1; j <= m; j++) {
			if (arr[i][j] == '.') {
				continue;
			}
			for (ll x = -1; x <= 1; x++) {
				for (ll y = -1; y <= 1; y++) {
					if (arr[i + x][j + y] == '*') {
						sos[i][j].insert(make_pair(i + x, j + y));
					}
				}
			}
		}
	}
	for (ll i = 1; i <= n; i++) {
		for (ll j = 1; j <= m; j++) {
			if (arr[i][j] == '.') {
				continue;
			}
			if (sos[i][j].size() != 3) {
				cout << "NO\n";
				return;
			}
			for (auto[x, y] : sos[i][j]) {
				if (sos[x][y] != sos[i][j]) {
					cout << "NO\n";
					return;
				}
			}
		}
	}
	cout << "YES\n";
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