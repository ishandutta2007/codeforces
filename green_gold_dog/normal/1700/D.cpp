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
	ll n;
	cin >> n;
	vector<ll> arr(n, 0), ps(1, 0);
	for (ll i = 0; i < n; i++) {
		cin >> arr[i];
		ps.push_back(ps.back() + arr[i]);
	}
	vector<ll> tp(n, 0), ta(n, 0);
	tp[0] = arr[0];
	for (ll i = 1; i < n; i++) {
		tp[i] = max(tp[i - 1], (ps[i + 1] + i) / (i + 1));
	}
	for (ll i = 0; i < n; i++) {
		ta[i] = max(tp[i], (ps.back() + i) / (i + 1));
	}
	ll q;
	cin >> q;
	for (ll i = 0; i < q; i++) {
		ll t;
		cin >> t;
		ll l = -1, r = n;
		while (r - l > 1) {
			ll mid = (l + r) / 2;
			if (ta[mid] > t) {
				l = mid;
			} else {
				r = mid;
			}
		}
		cout << (r == n ? -1 : r + 1) << '\n';
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