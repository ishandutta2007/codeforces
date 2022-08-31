#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		int64_t curMax = -1e18;
		int64_t maxDrop = 0;
		for (int i = 0; i < N; i++) {
			int64_t a; cin >> a;
			curMax = max(curMax, a);
			maxDrop = max(maxDrop, curMax - a);
		}
		int x = 0;
		while ((int64_t(1) << x)-1 < maxDrop) {
			x++;
		}
		cout << x << '\n';
	}

	return 0;
}