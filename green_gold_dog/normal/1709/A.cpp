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
	ll x;
	ll a[4];
	cin >> x >> a[1] >> a[2] >> a[3];
	if (a[x] == 0 || a[a[x]] == 0) {
		cout << "NO";
	} else {
		cout << "YES";
	}
	cout << '\n';
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