#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		int cnt = 0;
		int64_t tot = 0;
		int64_t hi = 0;
		for (int z = 0; z < N; z++) {
			int64_t a; cin >> a;
			int l = __builtin_ctzll(a);
			a >>= l;
			cnt += l;
			tot += a;
			if (a > hi) hi = a;
		}
		cout << tot + (hi << cnt) - hi << '\n';
	}

	return 0;
}