#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int64_t C, D; cin >> C >> D;
		cout << [&]() -> int {
			if (C == 0 && D == 0) return 0;
			if ((C + D) & 1) return -1;
			if (C == D) return 1;
			return 2;
		}() << '\n';
	}

	return 0;
}