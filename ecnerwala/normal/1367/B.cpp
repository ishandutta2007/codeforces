#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		int cnt[2] = {0, 0};
		for (int i = 0; i < N; i++) {
			int a; cin >> a;
			if ((a & 1) != (i & 1)) {
				cnt[i&1]++;
			}
		}
		if (cnt[0] != cnt[1]) cout << -1 << '\n';
		else cout << cnt[0] << '\n';
	}

	return 0;
}