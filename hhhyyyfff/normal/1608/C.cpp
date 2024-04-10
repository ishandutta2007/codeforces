#include <bits/stdc++.h>

using namespace std;

vector<int> e[100001], tmp;
stack<int> st;
pair<int, int> a[100001], b[100001];
int t, n, tim, cnt, dfn[100001], low[100001], bel[100001];
bool v[100001], wins[100001];

void dfs(int x) {
	dfn[x] = low[x] = ++tim;
	v[x] = 1;
	st.push(x);
	for (int i : e[x])
		if (!dfn[i]) {
			dfs(i);
			low[x] = min(low[x], low[i]);
		} else if (v[i]) low[x] = min(low[x], low[i]);
	if (dfn[x] == low[x]) {
		++cnt;
		tmp.clear();
		while (st.top() != x) {
			v[st.top()] = 0;
			bel[st.top()] = cnt;
			tmp.push_back(st.top());
			st.pop();
		}
		v[st.top()] = 0;
		bel[st.top()] = cnt;
		tmp.push_back(st.top());
		st.pop();
		bool flag = 1;
		for (int i : tmp) {
			for (int j : e[i])
				if (bel[j] != cnt) {
					flag = 0;
					break;
				}
			if (!flag) break;
		}
		if (flag) for (int i : tmp) wins[i] = 1;
	}
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i].first);
			a[i].second = i;
			e[i].clear();
		}
		sort(a + 1, a + n + 1);
		for (int i = 1; i < n; ++i)
			e[a[i].second].push_back(a[i + 1].second);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &b[i].first);
			b[i].second = i;
		}
		sort(b + 1, b + n + 1);
		for (int i = 1; i < n; ++i)
			e[b[i].second].push_back(b[i + 1].second);
		memset(dfn, 0, sizeof(int) * (n + 1));
		memset(wins, 0, sizeof(bool) * (n + 1));
		st = stack<int>();
		for (int i = 1; i <= n; ++i)
			if (!dfn[i])
				dfs(i);
		for (int i = 1; i <= n; ++i) printf("%d", (int)wins[i]);
		puts("");
	}
	return 0;
}