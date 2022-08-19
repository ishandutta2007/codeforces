#include<bits/stdc++.h>
using namespace std;

using ll = long long;

ll solve(ll v) {
	if (v == 0) return 0;
	if (v % 3 == 2) {
		return solve(v / 3 + 1) * 3;
	} else {
		return max(solve(v / 3) * 3, v);
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int Q; cin >> Q;
	while (Q--) {
		ll N; cin >> N;
		cout << solve(N) << '\n';
	}

	return 0;
}