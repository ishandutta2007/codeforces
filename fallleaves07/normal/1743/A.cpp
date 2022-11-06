#include<bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
	int n;
	vector<bool> vis(10, true);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int v;
		cin >> v;
		vis[v] = false;
	}
	int ans = 0;
	for (int i = 0; i <= 9; i++) {
		for (int j = i + 1; j <= 9; j++) {
			if (vis[i] && vis[j]) {
				ans += 6;
			}
		}
	}
	printf("%d\n", ans);
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