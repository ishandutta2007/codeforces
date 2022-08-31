#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int N; cin >> N;

	auto query = [&](int a) -> int {
		cout << '?' << ' ' << a << '\n' << flush;
		int h; cin >> h;
		return h;
	};

	int mi = 0;
	int ma = int(1e8);
	while (ma - mi > 1) {
		int md = (mi + ma) / 2;
		if (query(md) != 1) {
			mi = md;
		} else {
			ma = md;
		}
	}

	int tot_length = ma + 1;
	int ans = 0;
	ans = tot_length - 1;
	for (int h = 2; h <= N; h++) {
		int w = (tot_length - 1) / h;
		int h_real = query(w);
		if (h_real != 0) ans = std::min(ans, w * h_real);
	}
	cout << '!' << ' ' << ans << '\n' << flush;

	return 0;
}