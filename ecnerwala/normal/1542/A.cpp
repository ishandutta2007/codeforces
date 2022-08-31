#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N; N *= 2;
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			int a; cin >> a;
			cnt += (a & 1);
		}
		cout << (cnt * 2 == N ? "Yes" : "No") << '\n';
	}

	return 0;
}