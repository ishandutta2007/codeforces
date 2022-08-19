#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int N; int K; cin >> N >> K;
	auto query = [&](int i) -> int {
		cout << '?' << ' ' << i+1 << '\n' << flush;
		int v; cin >> v;
		return v;
	};

	int mi = 0, ma = N;
	int num_big = 0;
	while (ma - mi > 1) {
		if (2 * num_big + 1 >= ma - mi) {
			int md = (mi + ma) / 2;
			int v = query(md);
			if (v == K) {
				mi = md, ma = md+1;
			} else if (v > K) {
				ma = md;
			} else {
				mi = md + 1;
			}
		} else {
			int md = mi + num_big;
			int v = query(md);
			if (v > K) {
				ma = md;
			} else {
				mi = md;
			}
		}
		num_big = min(num_big+1, (N-2)/2);
	}
	assert(ma - mi == 1);
	cout << '!' << ' ' << mi+1 << '\n' << flush;

	return 0;
}