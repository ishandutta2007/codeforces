#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ll N, K;
	cin >> N >> K;
	if (N * (N-1) / 2 < K) {
		cout << "Impossible\n";
		return 0;
	}
	string res;
	while (N > 0 && (N-1) * (N-2) / 2 >= K) {
		res += "()";
		N--;
	}
	if (N > 0) {
		ll diff = N * (N-1) / 2 - K;
		assert(diff < N);
		// open n-1-diff
		for (ll i = 0; i < N - 1 - diff; i++) {
			res += '(';
		}
		// open/close the one
		res += "()";
		for (ll i = 0; i < diff; i++) {
			res += '(';
		}
		for (ll i = 0; i < N-1; i++) {
			res += ')';
		}
	}

	cout << res << '\n';

	return 0;
}