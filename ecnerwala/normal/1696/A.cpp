#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N, Z; cin >> N >> Z;
		int ans = 0;
		while (N--) {
			int a; cin >> a;
			ans = std::max(ans, a | Z);
		}
		cout << ans << '\n';
	}

	return 0;
}