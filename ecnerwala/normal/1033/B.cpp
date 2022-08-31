#include<bits/stdc++.h>
using namespace std;

using ll = long long;

bool isPrime(ll v) {
	for (ll i = 2; i * i <= v; i++) {
		if (v % i == 0) return false;
	}
	return true;
}

bool isPrime(ll A, ll B) {
	assert(A > B);
	if (A - B > 1) {
		return false;
	}
	assert(A - B == 1);
	return isPrime(A + B);
}

int main() {
	int T; cin >> T;
	while (T --> 0) {
		ll A, B;
		cin >> A >> B;
		assert(A > B);
		cout << (isPrime(A, B) ? "YES" : "NO") << '\n';
	}

	return 0;
}