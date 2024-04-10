#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

#define MAXN 500013
int T, N;
int nxt[MAXN];
int ans[MAXN];

bool solve(int s, int e, int lo, int hi) {
	// [s, e), [lo, hi]
	if (s >= e)
		return true;
	if (nxt[s] == -2) {
		ans[s] = lo;
		return solve(s + 1, e, lo + 1, hi);
	}
	if (nxt[s] > e)
		return false;
	int len = nxt[s] - s;
	ans[s] = lo + len - 1;
	if (!solve(s + 1, nxt[s], lo, lo + len - 2))
		return false;
	return solve(nxt[s], e, lo + len, hi);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> nxt[i];
			--nxt[i];
		}
		bool ok = solve(0, N, 1, N);
		if (!ok)
			cout << -1 << '\n';
		else {
			for (int i = 0; i < N; i++)
				cout << ans[i] << ' ';
			cout << '\n';
		}
	}

	cout.flush();
	return 0;
}