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
	vector<ll> a1, a2;
	for (auto i : arr) {
		if (i % 2 == 0) {
			a1.push_back(i);
		} else {
			a2.push_back(i);
		}
	}
	bool b = true;
	for (ll i = 1; i < a1.size(); i++) {
		if (a1[i] < a1[i - 1]) {
			b = false;
			break;
		}
	}
	for (ll i = 1; i < a2.size(); i++) {
		if (a2[i] < a2[i - 1]) {
			b = false;
			break;
		}
	}
	cout << (b ? "Yes" : "No") << '\n';
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