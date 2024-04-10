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
	deque<ll> ans;
	for (ll i = 9; i > 0; i--) {
		if (n >= i) {
			ans.push_front(i);
			n -= i;
		}
	}
	for (auto i : ans) {
		cout << i;
	}
	cout << '\n';
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