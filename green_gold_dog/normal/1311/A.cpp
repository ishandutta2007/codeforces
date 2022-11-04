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
	ll t;
	cin >> t;
	for (ll _ = 0; _ < t; _++) {
		ll a, b;
		cin >> a >> b;
		if (a == b) {
			cout << 0 << '\n';
			continue;
		}
		if ((a > b && (a - b) % 2 == 1) || (a < b && (b - a) % 2 == 0)) {
			cout << 2 << '\n';
		} else {
			cout << 1 << '\n';
		}
	}

}
/*
















*/