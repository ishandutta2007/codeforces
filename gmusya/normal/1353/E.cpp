#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int cnt(int l, int r, vector <int> &pre) {
	if (l > r) return 0;
	int x = pre[r] - (l ? pre[l - 1] : 0);
	return x;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		vector <int> a;
		for (int i = 0; i < n; i++) {
			char c;
			cin >> c;
			a.push_back(c - '0');
		}
		vector <int> c0(k), c1(k);
		for (int i = 0; i < n; i++) {
			if (a[i] == 0) c0[i % k]++;
			else c1[i % k]++;
		}
		int s0 = 0, s1 = 0;
		for (int i = 0; i < k; i++) {
			s0 += c0[i];
			s1 += c1[i];
		}
		int ans = s1;
		for (int it = 0; it < k; it++) {
			int cur_ans = 0;
			cur_ans += s1 - c1[it];
			vector <int> arr;
			for (int i = it; i < n; i += k)
				arr.push_back(a[i]);
			int m = arr.size();
			vector <int> pre(m);
			pre[0] = arr[0];
			for (int i = 1; i < m; i++)
				pre[i] = pre[i - 1] + arr[i];
			vector <int> dp(m);
			for (int i = 0; i < m; i++)
				dp[i] = min(cnt(0, i - 1, pre) + (arr[i] != 1), (i ? dp[i - 1] : 0) + (arr[i] != 1));
			int hm = cnt(0, m - 1, pre);
			for (int i = 0; i < m; i++)
				hm = min(hm, dp[i] + cnt(i + 1, m - 1, pre));
			ans = min(ans, cur_ans + hm);
		}
		cout << ans << '\n';
	}
	return 0;
}