#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while (T--) {
		int D, M; cin >> D >> M;
		int64_t ans = 1;
		for (int l = 0; (1<<l) <= D; l++) {
			int cnt = min((1<<l), D+1 - (1<<l));
			ans *= cnt+1;
			ans %= M;
		}
		ans --;
		if (ans < 0) ans += M;
		cout << ans << '\n';
	}

	return 0;
}