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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll k, r;
	cin >> k >> r;
	for (ll i = 1; i < 10; i++) {
		if (k * i % 10 == r || k * i % 10 == 0) {
			cout << i;
			return 0;
		}
	}
	cout << 10;
}

/*
















*/