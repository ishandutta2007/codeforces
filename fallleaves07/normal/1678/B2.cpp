#include<bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
	int n;
	string s;
	cin >> n >> s;
	array<int, 2> ans = {n + 1, n + 1};
	int cnt = 0;
	if (s[0] == s[1]) {
		ans[s[0] - '0'] = 1;
	} else {
		ans = {1, 1}, ++cnt;
	}
	for (int i = 2; i < n; i += 2) {
		if (s[i] != s[i + 1]) {
			++cnt;
			auto d = ans;
			ans[0] = min(d[0], d[1] + 1);
			ans[1] = min(d[1], d[0] + 1);
		} else {
			int x = s[i] - '0';
			ans[x] = min(ans[x], ans[x ^ 1] + 1);
			ans[x ^ 1] = n + 1;
		}
	}
	printf("%d %d\n", cnt, min(ans[0], ans[1]));
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