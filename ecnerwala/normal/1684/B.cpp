#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int64_t A, B, C; cin >> A >> B >> C;

		cout << A + B * C << ' ' << B << ' ' << C << '\n';
	}

	return 0;
}