#include <bits/stdc++.h>
using namespace std;

vector <int> arr[60][60];
int path[60][60][110];
int adj[60][60];

int main () {
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int x, y; scanf("%d%d", &x, &y);
		adj[x][y] = 1;
		int k; scanf("%d", &k);
		while (k--) {
			int val; scanf("%d", &val);
			arr[x][y].push_back(val);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (!adj[i][j]) continue;
			int p = -1;
			for (int k = 1; k < arr[i][j].size(); k++) {
				if (arr[i][j][k - 1] == i && arr[i][j][k] == j) {
					if (p == -1) p = k - 1;
					else if (p >= 0) p = -2;
				}
			}
			if (p < 0) continue;
			int len = 1;
			vector <int> path;
			queue <int> q; int cur = i; path.push_back(cur);
			for (int k = p - 1; k >= 0; k--) {
				q.push(arr[i][j][k]);
			}
			int flag = 1;
			while (!q.empty()) {
				int x = q.front(); q.pop();
				len++, path.push_back(x);
				if (!adj[x][cur]) {
					flag = 0;
					break;
				}
				for (int k = (int)arr[x][cur].size() - 1; k >= 0; k--) {
					q.push(arr[x][cur][k]);
				}
				cur = x;
			}
			if (!flag) continue;
			reverse(path.begin(), path.end());
			int L = cur; cur = j, len++, path.push_back(cur);
			for (int k = p + 2; k < arr[i][j].size(); k++) {
				q.push(arr[i][j][k]);
			}
			while (!q.empty()) {
				int x = q.front(); q.pop();
				len++, path.push_back(x);
				if (!adj[cur][x]) {
					flag = 0;
					break;
				}
				for (int k = 0; k < arr[cur][x].size(); k++) {
					q.push(arr[cur][x][k]);
				}
				cur = x;
			}
			if (!flag) break;
			int R = cur;
			if (len <= 2 * n) {
				printf("%d\n", path.size());
				for (int i = 0; i < path.size(); i++) {
					printf("%d ", path[i]);
				}
				printf("\n");
				return 0;
			}
		}
	}
	printf("0\n");
	return 0;
}