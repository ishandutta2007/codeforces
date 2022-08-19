#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		for (int i = 0; i < N; i++) { int a; cin >> a; }
		cout << 3 * N << '\n';
		for (int i = 1; i <= N; i += 2) {
			cout << 1 << ' ' << i << ' ' << i+1 << '\n';
			cout << 2 << ' ' << i << ' ' << i+1 << '\n';
			cout << 1 << ' ' << i << ' ' << i+1 << '\n';
			cout << 1 << ' ' << i << ' ' << i+1 << '\n';
			cout << 2 << ' ' << i << ' ' << i+1 << '\n';
			cout << 1 << ' ' << i << ' ' << i+1 << '\n';
		}
	}

	return 0;
}