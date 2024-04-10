#include<bits/stdc++.h>
using namespace std;

int64_t trans[3][4] = {
	{0, 1, 2, 3},
	{0, 2, 3, 1},
	{0, 3, 1, 2},
};

int64_t solve(int64_t N) {
	N--;
	int64_t tripNum = N/3;
	int numDig = 0;
	while (tripNum >= (int64_t(1) << (2*numDig))) {
		tripNum -= (int64_t(1) << (2*numDig));
		numDig++;
	}
	int64_t v = (int64_t(1) << (2*numDig)) + tripNum;
	int64_t ans = 0;
	for (int d = 0; d <= numDig; d++) {
		ans |= trans[N%3][(v >> (2 * d)) & 3] << (2*d);
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int64_t N; cin >> N;
		int64_t ans = solve(N);
		cout << ans << '\n';
	}

	return 0;
}