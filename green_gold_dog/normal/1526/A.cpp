#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double db;
typedef long double ldb;
typedef complex<double> cd;

const ll INF = 9'000'000'000'000'000'000;
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

void solve() {
	ll n;
	cin >> n;
	vector<ll> arr(n * 2, 0);
	for (ll i = 0; i < n * 2; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	for (ll i = 0; i < n * 2; i++) {
		if (i % 2 == 0) {
			cout << arr[i / 2] << ' ';
		} else {
			cout << arr[n * 2 - 1 - i / 2] << ' ';
		}
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