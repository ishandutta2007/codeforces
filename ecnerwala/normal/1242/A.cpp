#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll N; cin >> N;
	if (N == 1) {
		cout << 1 << '\n';
		exit(0);
	}
	for (ll p = 2; true; p++) {
		if (p * p > N) p = N;
		if (N % p == 0) {
			ll v = N;
			while (v % p == 0) v /= p;
			if (v == 1) {
				cout << p << '\n';
			} else {
				cout << 1 << '\n';
			}
			exit(0);
		}
	}

	return 0;
}