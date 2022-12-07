#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;
	vector<pair<int, int>> ans;
	for (int i = 1, j = n * 3 - 1; i < j; i += 3, j -= 3) {
		ans.emplace_back(i, j);
	}
	printf("%d\n", (int)ans.size());
	for (auto [x, y] : ans) {
		printf("%d %d\n", x, y);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}