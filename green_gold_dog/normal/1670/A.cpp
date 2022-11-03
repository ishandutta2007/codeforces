#pragma GCC target("sse,sse2,sse3,avx,avx2,popcnt,abm,mmx,sse4")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Ofast")
#include<iostream>
#include<vector>
#include<map>
#include<deque>

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
	vector<ll> arr(n, 0);
	ll col = 0;
	for (ll i = 0; i < n; i++) {
		cin >> arr[i];
		if (arr[i] < 0) {
			col++;
			arr[i] = -arr[i];
		}
	}
	for (ll i = 0; i < col; i++) {
		arr[i] = -arr[i];
	}
	for (ll i = 1; i < n; i++) {
		if (arr[i] < arr[i - 1]) {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
}

int main() {
	cin.tie(0)->ios_base::sync_with_stdio(false);
	ll t;
	if (true) {
		cin >> t;
	}
	for (ll i = 0; i < t; i++) {
		solve();
	}
}