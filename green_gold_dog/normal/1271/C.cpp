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

ll get(ll sx, ll sy, ll ex, ll ey, vector<pair<ll, ll>>& arr) {
	ll ans = 0;
	for (auto[x, y] : arr) {
		if (abs(x - ex) + abs(y - ey) + abs(ex - sx) + abs(ey - sy) == abs(x - sx) + abs(y - sy)) {
			ans++;
		}
	}
	return ans;
}

void solve() {
	ll n;
	cin >> n;
	ll sx, sy;
	cin >> sx >> sy;
	vector<pair<ll, ll>> arr(n);
	for (ll i = 0; i < n; i++) {
		cin >> arr[i].first >> arr[i].second;
	}
	ll ma = 0;
	for (ll i = -1; i <= 1; i++) {
		for (ll j = -1; j <= 1; j++) {
			if (abs(i) + abs(j) == 1) {
				assign_max(ma, get(sx, sy, sx + i, sy + j, arr));
			}
		}
	}
	cout << ma << '\n';
	for (ll i = -1; i <= 1; i++) {
		for (ll j = -1; j <= 1; j++) {
			if (abs(i) + abs(j) == 1) {
				if (ma == get(sx, sy, sx + i, sy + j, arr)) {
					cout << sx + i << ' ' << sy + j << '\n';
					return;
				}
			}
		}
	}
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