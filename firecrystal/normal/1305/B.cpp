#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 1005;
char s[N];
int n, st[N], d[N], top, cnt = 0;
bool vis[N];
vector<int> ans[N];
bool check() {
	int l = 1, r = n;
	while (l < r) {
		while (l <= n && (s[l] != '(' || vis[l])) l++;
		while (r >= 1 && (vis[r] || s[r] != ')')) r--;
		if (l > n || r < 1 || l >= r) break;
		ans[cnt].push_back(l);
		ans[cnt].push_back(r);
		vis[l]=true,vis[r]=true;
		l++, r--;
	}
	return ans[cnt].size();
}
int main() {
	scanf("%s", s + 1);
	n = strlen(s + 1);
	while (1) {
		if (check()) {
			++cnt;
		} else break;
	}
	printf("%d\n", cnt);
	for (int i = 0; i < cnt; i++) {
		printf("%d\n", ans[i].size());
		sort(ans[i].begin(), ans[i].end());
		for (int j = 0; j < ans[i].size(); j++)
			printf("%d ", ans[i][j]);
		puts("");
	}
	return 0;
}