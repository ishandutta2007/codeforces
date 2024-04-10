#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int64_t K, D, T; cin >> K >> D >> T;

	T *= 2;
	// it cooks 2 units per minute, and then 1 unit per minutes

	int64_t full_cycle = ((K+D-1) / D) * D;
	int64_t full_cycle_cook = full_cycle + K;

	int64_t ans = 0;
	ans += T / full_cycle_cook * full_cycle;
	T %= full_cycle_cook;

	ans *= 2;

	// cooks at 1 unit per minute, and then 1/2 unit per minute
	if (T <= K * 2) {
		ans += T; // cooks at full speed
	} else {
		ans += 2 * K;
		ans += 2 * (T - (2 * K));
	}

	cout << ans/2 << '.' << (ans % 2) * 5 << '\n';

	return 0;
}