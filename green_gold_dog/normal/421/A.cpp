#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

const ll INF = 1'000'000'000'000'000;

template<typename T>
bool assign_min(T& a, T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}

template<typename T>
bool assign_max(T& a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}

template<typename T>
T square(T& a) {
	return a * a;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n, a, b;
	cin >> n >> a >> b;
	vector<ll> arr(n, 0);
	for (ll i = 0; i < a; i++) {
		ll c;
		cin >> c;
		arr[c - 1] = 1;
	}
	for (ll i = 0; i < b; i++) {
		ll c;
		cin >> c;
		arr[c - 1] = 2;
	}
	for (auto i : arr) {
		cout << i << ' ';
	}
}
/*
















*/