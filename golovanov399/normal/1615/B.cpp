#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

const int N = 222'222;
const int L = 20;
int cnt[L][N];

void solve() {
	int l = nxt() - 1, r = nxt();
	int ans = 0;
	for (int i = 0; i < L; ++i) {
		ans = max(ans, cnt[i][r] - cnt[i][l]);
	}
	cout << r - l - ans << "\n";
}

int main() {
	for (int i = 0; i < L; ++i) {
		for (int j = 1; j < N; ++j) {
			cnt[i][j] = cnt[i][j - 1] + !!(j & (1 << i));
		}
	}

	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}