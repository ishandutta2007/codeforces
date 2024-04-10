#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int N; cin >> N;
	const int64_t L = 2;
	int64_t mi = 0;
	int64_t ma = 1 << N;
	for (int i = 0; i < N; i++) {
		int64_t md = (mi + ma) / 2;
		cout << md / 2 + 10 << ' ' << md % 2 + 10 << '\n' << flush;
		string res; cin >> res;
		if (res == "black") {
			ma = md;
		} else if (res == "white") {
			mi = md;
		} else assert(false);
	}
	assert(ma - mi == 1);
	if (ma % 2 == 1) {
		cout << ma/2 - 1 + 10 << ' ' << 13 << ' ' << mi / 2 + 1 + 10 << ' ' << 8 << '\n';
	} else {
		cout << ma/2 + 10 << ' ' << 13 << ' ' << mi / 2 + 10 << ' ' << 8 << '\n';
	}

	return 0;
}