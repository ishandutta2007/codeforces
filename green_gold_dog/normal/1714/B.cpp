#include<iostream>
#include<vector>
#include<map>

using namespace std;

typedef long long ll;

template<typename T>
bool assign_min(T &a, T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}

template<typename T>
bool assign_max(T &a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}

void solve() {
	ll n;
	cin >> n;
	vector<ll> arr(n);
	map<ll, ll> m;
	ll now = 0;
	for (ll i = 0; i < n; i++) {
		cin >> arr[i];
		if (m[arr[i]] != 0) {
			now++;
		}
		m[arr[i]]++;
	}
	for (ll i = 0; i < n; i++) {
		if (now == 0) {
			cout << i << '\n';
			return;
		}
		m[arr[i]]--;
		if (m[arr[i]] != 0) {
			now--;
		}
	}
}

int main() {
	cin.tie(0)->ios_base::sync_with_stdio(false);
	ll t = 1;
	if (1) {
		cin >> t;
	}
	for (ll i = 0; i < t; i++) {
		solve();
	}
}