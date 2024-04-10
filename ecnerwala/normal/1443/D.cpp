#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		const int INF = 1e9;
		int a = INF, b = 0;
		for (int i = 0; i < N; i++) {
			int v; cin >> v;
			if (a < 0) continue;
			int na = min(a, v-b);
			int nb = max(v-a, b);
			assert(na + nb == v);
			a = na, b = nb;
		}
		cout << (a >= 0 ? "YES" : "NO") << '\n';
	}

	return 0;
}