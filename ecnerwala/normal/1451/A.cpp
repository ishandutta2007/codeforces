#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		if (N == 1) {
			cout << 0 << '\n';
		} else if (N == 2) {
			cout << 1 << '\n';
		} else if (N == 3) {
			cout << 2 << '\n';
		} else if (N % 2 == 0) {
			cout << 2 << '\n';
		} else {
			cout << 3 << '\n';
		}
	}

	return 0;
}