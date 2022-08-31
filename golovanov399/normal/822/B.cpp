#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define itn int

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

int main() {
	int n = nxt(), m = nxt();
	string s, t;
	cin >> s >> t;
	vector<int> ans(s.length() + t.length());
	for (int i = 0; i + n <= m; ++i) {
		vector<int> cur;
		for (int j = 0; j < n; ++j) {
			if (t[i + j] != s[j]) {
				cur.push_back(j);
			}
		}
		if (cur.size() < ans.size()) {
			ans = cur;
		}
	}

	printf("%d\n", ans.size());
	for (int x : ans) {
		printf("%d ", x + 1);
	}
	printf("\n");

	return 0;
}