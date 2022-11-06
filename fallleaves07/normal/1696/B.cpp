#include<bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
	int n, lst = -1, ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int v;
		cin >> v;
		if (v == 0) {
			if (lst < i - 1) {
				++ans;
			}
			lst = i;
		}
	}
	if (lst < n - 1) {
		++ans;
	}
	ans = min(ans, 2);
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