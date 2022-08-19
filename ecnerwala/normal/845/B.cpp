#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	string S; cin >> S;
	int ans = 5;
	for (int msk = 0; msk < 64; msk++) {
		int lo0 = 0;
		int hi0 = 0;
		int lo1 = 0;
		int hi1 = 0;
		for (int i = 0; i < 6; i++) {
			int l = S[i] - '0', h = S[i] - '0';
			if (msk & (1 << i)) {
				l = 0;
				h = 9;
			}
			if (i < 3) {
				lo0 += l;
				hi0 += h;
			} else {
				lo1 += l;
				hi1 += h;
			}
		}
		if (std::max(lo0, lo1) <= std::min(hi0, hi1)) {
			ans = std::min(ans, __builtin_popcount(msk));
		}
	}
	cout << ans << '\n';

	return 0;
}