#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N, X; int64_t Y; cin >> N >> X >> Y;
		X &= 1;
		Y &= 1;
		for (int i = 0; i < N; i++) {
			int a; cin >> a; a &= 1;
			X ^= a;
		}
		cout << (X == Y ? "Alice" : "Bob") << '\n';
	}

	return 0;
}