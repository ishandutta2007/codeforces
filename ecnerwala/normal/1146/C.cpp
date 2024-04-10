#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		int ans = 0;
		for (int i = 0; i < 9; i++) {
			vector<int> sets[2];
			for (int v = 0; v < N; v++) {
				sets[bool(v & (1 << i))].push_back(v);
			}
			if (sets[0].empty() || sets[1].empty()) continue;
			cout << sets[0].size() << ' ' << sets[1].size();
			for (int v : sets[0]) cout << ' ' << v+1;
			for (int v : sets[1]) cout << ' ' << v+1;
			cout << '\n' << flush;
			int res; cin >> res;
			if (res == -1) exit(0);
			ans = max(ans, res);
		}
		cout << -1 << ' ' << ans << '\n' << flush;
	}

	return 0;
}