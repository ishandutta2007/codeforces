#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int H, W; cin >> H >> W;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				cout << int([&]() -> bool {
					if ((i == 0 || i == H-1) && (j == 0 || j == W-1)) return true;
					if ((i == 0 || i == H-1)) {
						if (j == 1 || j == W-2) return false;
						return j % 2 == 0;
					}
					if ((j == 0 || j == W-1)) {
						if (i == 1 || i == H-2) return false;
						return i % 2 == 0;
					}

					return false;
				}());
			}
			cout << '\n';
		}
		cout << '\n';
	}

	return 0;
}