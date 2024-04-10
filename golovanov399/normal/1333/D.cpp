#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define itn int
#define make_unique(x) sort((x).begin(), (x).end()); (x).erase(unique((x).begin(), (x).end()), (x).end())

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

void solve() {
	int n = nxt(), k = nxt();
	string s;
	cin >> s;
	int mx = 0;
	{
		int cnt_r = 0;
		for (char c : s) {
			if (c == 'L') {
				mx += cnt_r;
			} else {
				++cnt_r;
			}
		}
	}
	if (k > mx) {
		cout << "-1\n";
		return;
	}
	
	queue<int> q;
	int timer = 0;
	vector<int> used(n);
	vector<vector<int>> ans;
	for (int i = 0; i < n - 1; ++i) {
		if (s[i] == 'R' && s[i + 1] == 'L') {
			q.push(i);
		}
	}
	while (!q.empty()) {
		int i = q.front();
		q.pop();
		if (used[i] == timer || used[i + 1] == timer) {
			ans.push_back({});
			++timer;
		}
		ans.back().push_back(i + 1);
		used[i] = used[i + 1] = timer;
		swap(s[i], s[i + 1]);
		if (i > 0 && s[i - 1] == 'R') {
			q.push(i - 1);
		}
		if (i + 2 < n && s[i + 2] == 'L') {
			q.push(i + 1);
		}
	}
	assert(is_sorted(all(s)));
	if ((int)ans.size() > k) {
		cout << "-1\n";
		return;
	}
	int i = 0, j = 0;
	while (k > (int)ans.size() - i) {
		printf("%d %d\n", 1, ans[i][j]);
		++j;
		if (j == (int)ans[i].size()) {
			i += 1;
			j = 0;
		}
		--k;
	}
	while (i < (int)ans.size()) {
		printf("%d", (int)ans[i].size() - j);
		while (j < (int)ans[i].size()) {
			printf(" %d", ans[i][j++]);
		}
		++i;
		j = 0;
		printf("\n");
	}
}

int main() {
	int t = 1; // nxt();
	while (t--) {
		solve();
	}

	return 0;
}