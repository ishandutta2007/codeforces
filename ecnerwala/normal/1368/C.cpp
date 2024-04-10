#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int N; cin >> N;
	cout << 1 + 7 * (N + 1) << '\n';
	cout << 0 << ' ' << 0 << '\n';
	for (int z = 0; z <= N; z++) {
		int d = (z & 1) ? -1 : 1;
		cout << 2 * z + 0 << ' ' << 1 * d << '\n';
		cout << 2 * z + 0 << ' ' << 2 * d << '\n';
		cout << 2 * z + 1 << ' ' << 0 * d << '\n';
		cout << 2 * z + 1 << ' ' << 2 * d << '\n';
		cout << 2 * z + 2 << ' ' << 0 * d << '\n';
		cout << 2 * z + 2 << ' ' << 1 * d << '\n';
		cout << 2 * z + 2 << ' ' << 2 * d << '\n';
	}

	return 0;
}