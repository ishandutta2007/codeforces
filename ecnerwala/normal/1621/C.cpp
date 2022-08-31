#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		std::vector<int> P(N, -1);

		auto query = [](int i) -> int {
			cout << '?' << ' ' << i+1 << '\n' << flush;
			int v; cin >> v;
			if (v == 0) exit(0);
			v--;
			return v;
		};

		for (int i = 0; i < N; i++) {
			if (P[i] != -1) continue;
			int st = query(i);
			int prv = st;
			do {
				int nxt = query(i);
				P[prv] = nxt;
				prv = nxt;
			} while (prv != st);
		}
		cout << '!';
		for (int i = 0; i < N; i++) {
			cout << ' ' << P[i]+1;
		}
		cout << '\n' << flush;
	}

	return 0;
}