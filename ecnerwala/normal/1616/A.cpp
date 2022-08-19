#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		std::vector<bool> used(300);
		for (int i = 0; i < N; i++) {
			int a; cin >> a;
			if (!used[150+a]) {
				used[150+a] = true;
			} else {
				used[150-a] = true;
			}
		}
		int ans = 0;
		for (bool b : used) ans += b;
		cout << ans << '\n';
	}

	return 0;
}