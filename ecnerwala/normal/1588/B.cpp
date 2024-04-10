#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;

		auto query = [&](int l, int r) -> int64_t {
			cout << '?' << ' ' << l+1 << ' ' << r << '\n' << flush;
			int64_t resp; cin >> resp;
			if (resp == -1) exit(0);
			return resp;
		};

		int64_t all = query(0, N);
		int64_t v_mi = 0;
		int mi = 0;
		int ma = N;
		while (ma - mi > 1) {
			int md = (mi + ma) / 2;
			int64_t v = query(0, md);
			if (v == all) {
				ma = md;
			} else {
				mi = md;
				v_mi = v;
			}
		}
		int k = ma;
		int j = k - 1 - int(all - v_mi);
		int i = j - 1 - int(query(0, j) - query(0, j-1));
		cout << '!' << ' ' << i+1 << ' ' << j+1 << ' ' << k << '\n' << flush;
	}

	return 0;
}