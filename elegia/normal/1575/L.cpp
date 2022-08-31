#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;

const int N = 200010;

int stk[N];
std::pair<int, int> pr[N];

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);

	// a[i] < a[j]
	// j - a[j] >= i - a[i]
	// j - a[j]

	int n; std::cin >> n;
	for (int i = 1; i <= n; ++i) {
		int ai; std::cin >> ai; pr[i] = std::make_pair(ai, -i);
	}
	std::sort(pr + 1, pr + n + 1);
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		int x = -(pr[i].first + pr[i].second);
		if (x < 0) continue;
		int pos = std::upper_bound(stk + 1, stk + ans + 1, x) - stk;
		stk[pos] = x;
		ans = std::max(ans, pos);
	}
	std::cout << ans << '\n';

	return 0;
}