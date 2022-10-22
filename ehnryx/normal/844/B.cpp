#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	long long ans;
	int cnt[2];
	int n, m;
	cin >> n >> m;

	ans = -m*n;
	int grid[n][m];
	for (int i = 0; i < n; i++) {
		cnt[0] = cnt[1] = 0;
		for (int j = 0; j < m; j++) {
			cin >> grid[i][j];
			cnt[grid[i][j]]++;
		}
		ans += (1LL<<cnt[0]) - 1;
		ans += (1LL<<cnt[1]) - 1;
	}
	for (int j = 0; j < m; j++) {
		cnt[0] = cnt[1] = 0;
		for (int i = 0; i < n; i++)
			cnt[grid[i][j]]++;
		ans += (1LL<<cnt[0]) - 1;
		ans += (1LL<<cnt[1]) - 1;
	}
	cout << ans << endl;

	return 0;
}