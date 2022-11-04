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
	ll n, k, l, c, d, p, nl, np;
	cin >> n >> k >> l >> c >> d >> p >> nl >> np;
	ll i;
	for (i = 0; (k * l >= n * nl * i) && (c * d >= n * i) && (p >= n * i * np); i++) {}
	cout << i - 1;
}
/*
















*/