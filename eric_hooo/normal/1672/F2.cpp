#include <bits/stdc++.h>
using namespace std;

int a[200010], b[200010];
int cnt[200010];
int in[200010];
vector <int> G[200010];

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int n; scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			cnt[i] = 0, in[i] = 0, G[i].clear();
		}
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			cnt[a[i]]++;
		}
		for (int i = 1; i <= n; i++) {
			scanf("%d", &b[i]);
		}
		int maxj = -1, p = -1;
		for (int i = 1; i <= n; i++) {
			if (maxj < cnt[i]) maxj = cnt[i], p = i;
		}
		for (int i = 1; i <= n; i++) {
			if (a[i] != p && b[i] != p) G[a[i]].push_back(b[i]), in[b[i]]++;
		}
		static queue <int> q;
		for (int i = 1; i <= n; i++) {
			if (!in[i]) q.push(i);
		}
		while (!q.empty()) {
			int x = q.front(); q.pop();
			for (auto v : G[x]) {
				in[v]--;
				if (in[v] == 0) q.push(v);
			}
		}
		for (int i = 1; i <= n; i++) {
			if (in[i]) {
				printf("WA\n");
				goto END;
			}
		}
		printf("AC\n");
		END:;
	}
	return 0;
}