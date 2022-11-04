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
		arr[i] = i + 1;
	}
	reverse(arr.begin(), arr.end());
	for (auto i : arr) {
		cout << i << ' ';
	}
	cout << '\n';
	for (ll i = 0; i < n - 1; i++) {
		swap(arr[i], arr[i + 1]);
		for (auto i : arr) {
			cout << i << ' ';
		}
		cout << '\n';
		swap(arr[i], arr[i + 1]);
	}
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll t;
	cin >> t;
	for (ll i = 0; i < t; i++) {
		solve();
	}
}
/*
















*/