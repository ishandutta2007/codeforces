#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		int v = N - 6 - 10 - 14;
		if (v <= 0) {
			cout << "NO" << '\n';
		} else if (v == 6 || v == 10 || v == 14) {
			cout << "YES" << '\n';
			cout << 6 << ' ' << 10 << ' ' << 15 << ' ' << v-1 << '\n';
		} else {
			cout << "YES" << '\n';
			cout << 6 << ' ' << 10 << ' ' << 14 << ' ' << v << '\n';
		}
	}

	return 0;
}