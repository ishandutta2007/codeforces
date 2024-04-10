#include<bits/extc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	unordered_map<int, unordered_map<int, int>> mp;
	const int INF = int(1e9) + 10;
	int Q; cin >> Q;
	for (int q = 0; q < Q; q++) {
		int op; cin >> op;
		int t, x; cin >> t >> x;
		auto& bit = mp[x];
		if (op == 1 || op == 2) {
			int v = (op == 1) ? 1 : -1;
			for (int a = t; a < INF; a += a & -a) {
				bit[a] += v;
			}
		} else if (op == 3) {
			int ans = 0;
			for (int a = t; a; a -= a & -a) {
				ans += bit[a];
			}
			cout << ans << '\n';
		} else assert(false);
	}

	return 0;
}