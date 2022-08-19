#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int64_t D, K, A, B, T; cin >> D >> K >> A >> B >> T;
	if (D <= K) {
		cout << A * D << '\n';
		return 0;
	}
	assert(D > K);
	int64_t ans = A * K;
	D -= K;

	int64_t num_full = D / K;
	int64_t D_extra = D - num_full * K;
	//assert(1 <= D_extra && D_extra <= K);

	cout << ans + min({B * D, num_full * (A * K + T) + min(T + A * D_extra, B * D_extra)}) << '\n';

	return 0;
}