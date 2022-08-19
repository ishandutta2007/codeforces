#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		int L, R; cin >> L >> R;
		if (2 * L <= R) {
			cout << L << ' ' << 2 * L << '\n';
		} else {
			cout << -1 << ' ' << -1 << '\n';
		}
	}

	return 0;
}