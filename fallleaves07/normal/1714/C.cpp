#include<bits/stdc++.h>
using LL = long long;

void solve() {
	int s;
	std::cin >> s;
	std::vector<int> ans;
	for (int i = 9; i >= 1; i--) {
		if (s >= i) {
			ans.push_back(i);
			s -= i;
		}
	}
	std::reverse(ans.begin(), ans.end());
	for (auto d : ans) {
		printf("%d", d);
	}
	puts("");
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
	int T;
	std::cin >> T;
	while (T--) {
		solve();
	}
    return 0;
}