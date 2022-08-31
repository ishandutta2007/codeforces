#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int N; cin >> N;
	stack<pair<int, int>> stk;
	stk.push({-1, N});
	vector<int> ans(N);
	int num_placed = 0;
	for (int z = 0; z < 2 * N; z++) {
		char c; cin >> c;
		if (c == '+') {
			stk.push({num_placed++, 0});
		} else if (c == '-') {
			int v; cin >> v;
			if (stk.top().second >= v) {
				cout << "NO" << '\n';
				exit(0);
			}
			ans[stk.top().first] = v;
			stk.pop();
			stk.top().second = max(stk.top().second, v);
		} else assert(false);
	}

	cout << "YES" << '\n';
	for (int i = 0; i < N; i++) {
		cout << ans[i] << " ";
	}
	cout << '\n';
	return 0;
}