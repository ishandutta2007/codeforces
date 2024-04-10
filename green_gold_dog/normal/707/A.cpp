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
	ll n, m;
	cin >> n >> m;
	bool b = true;
	for (ll i = 0; i < n*m; i++) {
		char c;
		cin >> c;
		if (c == 'C' || c == 'Y' || c == 'M') {
			b = false;
			break;
		}
	}
	cout << (b ? "#Black&White" : "#Color");
}
/*
















*/