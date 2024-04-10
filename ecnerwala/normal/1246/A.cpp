#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll N, P; cin >> N >> P;
	for (int k = 1; true; k++) {
		ll v = N - P * k;
		if (v < k) {
			cout << -1 << '\n';
			break;
		} else if (__builtin_popcountll(v) <= k) {
			cout << k << '\n';
			break;
		}
	}

	return 0;
}