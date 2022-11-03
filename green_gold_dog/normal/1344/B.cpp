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

void dfs(ll x, ll y, vector<vector<char>>& arr, vector<vector<bool>>& used) {
	used[x][y] = true;
	vector<pair<ll, ll>> go;
	go.emplace_back(-1, 0);
	go.emplace_back(1, 0);
	go.emplace_back(0, 1);
	go.emplace_back(0, -1);
	for (auto[px, py] : go) {
		if (!used[x + px][y + py] && arr[x + px][y + py] == '#') {
			dfs(x + px, y + py, arr, used);
		}
	}
}

void solve() {
	ll n, m;
	cin >> n >> m;
	vector<vector<char>> arr(n + 2, vector<char>(m + 2, '.'));
	for (ll i = 1; i <= n; i++) {
		for (ll j = 1; j <= m; j++) {
			cin >> arr[i][j];
		}
	}
	bool b = true, bg = false, bv = false;
	for (ll i = 1; i <= n; i++) {
		bool bb = false;
		for (ll j = 1; j <= m + 1; j++) {
			if (arr[i][j] == '#' && bb) {
				b = false;
				break;
			}
			if (arr[i][j] == '.' && arr[i][j - 1] == '#') {
				bb = true;
			}
		}
		if (!bb) {
			bg = true;
		}
	}
	for (ll j = 1; j <= m; j++) {
		bool bb = false;
		for (ll i = 1; i <= n + 1; i++) {
			if (arr[i][j] == '#' && bb) {
				b = false;
				break;
			}
			if (arr[i][j] == '.' && arr[i - 1][j] == '#') {
				bb = true;
			}
		}
		if (!bb) {
			bv = true;
		}
	}
	if (!b || bg != bv) {
		cout << -1 << '\n';
		return;
	}
	ll ans = 0;
	vector<vector<bool>> used(n + 2, vector<bool>(m + 2, false));
	for (ll i = 1; i <= n; i++) {
		for (ll j = 1; j <= m; j++) {
			if (!used[i][j] && arr[i][j] == '#') {
				dfs(i, j, arr, used);
				ans++;
			}
		}
	}
	cout << ans << '\n';
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