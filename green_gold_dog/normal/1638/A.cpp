#include <bits/stdc++.h>
typedef long long ll;

const ll INF = 9'000'000'000'000'000'000;

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

using namespace std;

void solve() {
	ll n;
	cin >> n;
	vector<ll> arr(n, 0);
	for (ll i = 0; i < n; i++) {
		cin >> arr[i];
	}
	ll x = 0;
	for (ll i = 0; i < n; i++) {
		if (arr[i] == i + 1) {
			x++;
		} else {
			break;
		}
	}
	if (x == n) {
		for (auto i : arr) {
			cout << i << ' ';
		}
		cout << '\n';
		return;
	}
	ll y;
	for (ll i = x; i < n; i++) {
		if (arr[i] == x + 1) {
			y = i;
		}
	}
	for (ll j = x; j <= (x + y) / 2; j++) {
		swap(arr[j], arr[y + x - j]);
	}
	for (auto i : arr) {
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
	for (ll _ = 0; _ < t; _++) {
		solve();
	}
}
/*
















*/