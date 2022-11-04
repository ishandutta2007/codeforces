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
ll square(T a) {
	return a * a;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n;
	cin >> n;
	ll a1 = 0, a2 = 0;
	for (ll i = 0; i < n; i++) {
		ll a, b;
		cin >> a >> b;
		a1 += a < b;
		a2 += a > b;
	}
	cout << (a1 == a2 ? "Friendship is magic!^^" : (a1 > a2 ? "Chris" : "Mishka"));
}
/*
















*/