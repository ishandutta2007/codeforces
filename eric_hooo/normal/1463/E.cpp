#include <bits/stdc++.h>
using namespace std;

int p[300010], pre[300010], suc[300010], in[300010];
vector <int> from[300010], G[300010];
set <int> S;
vector <int> ans;
int be[300010];
queue <int> q;
vector <vector <int> > parts;
int rt;

bool check(vector <int> ans) {
	S.clear(), S.insert(rt);
	for (int i = 0; i < ans.size(); i++) {
		int x = ans[i];
		if (!S.count(x)) return 0;
		S.erase(x);
		for (int j = 0; j < from[x].size(); j++) {
			S.insert(from[x][j]);
		}
	}
	return 1;
}

int main () {
	int n, k; scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &p[i]);
		if (!p[i]) rt = i;
		else from[p[i]].push_back(i);
	}
	memset(pre, -1, sizeof(pre)), memset(suc, -1, sizeof(suc));
	for (int i = 1; i <= k; i++) {
		int x, y; scanf("%d%d", &x, &y);
		pre[y] = x, suc[x] = y;
	}
	for (int i = 1; i <= n; i++) {
		if (pre[i] != -1) continue;
		int cur = i;
		parts.push_back({});
		while (cur != -1) parts.back().push_back(cur), be[cur] = (int)parts.size() - 1, cur = suc[cur];
	}
	for (int i = 1; i <= n; i++) {
		if (!p[i]) continue;
		int x = p[i];
		if (be[x] != be[i]) G[be[x]].push_back(be[i]), in[be[i]]++;
	}
	for (int i = 0; i < parts.size(); i++) {
		if (!in[i]) q.push(i);
	}
	vector <int> ans;
	while (!q.empty()) {
		int x = q.front(); q.pop();
		for (int i = 0; i < parts[x].size(); i++) {
			ans.push_back(parts[x][i]);
		}
		for (int i = 0; i < G[x].size(); i++) {
			int v = G[x][i];
			in[v]--;
			if (!in[v]) q.push(v);
		}
	}
	if (ans.size() != n) {
		printf("0\n");
		return 0;
	}
	if (!check(ans)) {
		printf("0\n");
		return 0;
	}
	for (int i = 0; i < ans.size(); i++) {
		printf("%d ", ans[i]);
	}
	printf("\n");
	return 0;
}