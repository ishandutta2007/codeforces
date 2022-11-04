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
		ll a, b, c, n;
		cin >> a >> b >> c >> n;
		n -= max(a, max(b, c)) - a;
		n -= max(a, max(b, c)) - b;
		n -= max(a, max(b, c)) - c;
		cout << (n >= 0 && n % 3 == 0 ? "YES" : "NO") << '\n';
	}
}
/*
















*/