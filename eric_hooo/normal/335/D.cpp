#include <bits/stdc++.h>
using namespace std;

const int N = 3000;

int sum[3010][3010], a[3010][3010];
int row[3010][3010], col[3010][3010], sign[3010][3010], vis[3010][3010];

int main () {
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int x1, x2, y1, y2; scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		x1++, x2++, y1++, y2++;
		sum[x1][y1]++, sum[x1][y2]--, sum[x2][y1]--, sum[x2][y2]++;
		for (int x = x1; x < x2; x++) {
			for (int y = y1; y < y2; y++) {
				a[x][y] = i;
			}
		}
		sign[x1][y1] = i, vis[x2 - 1][y2 - 1] = 1;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			row[i][j] = row[i][j - 1] + (a[i][j] == a[i + 1][j]);
			col[i][j] = col[i - 1][j] + (a[i][j] == a[i][j + 1]);
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (sign[i][j] <= 0) continue;
			for (int len = 1; i + len - 1 <= N && j + len - 1 <= N; len++) {
				if (!vis[i + len - 1][j + len - 1]) continue;
				int x = i + len - 1, y = j + len - 1;
				if (sum[x][y] - sum[i - 1][y] - sum[x][j - 1] + sum[i - 1][j - 1] != len * len) continue;
				if (row[x][y] - row[x][j - 1] || row[i - 1][y] - row[i - 1][j - 1]) continue;
				if (col[x][y] - col[i - 1][y] || col[x][j - 1] - col[i - 1][j - 1]) continue;
				vector <int> ans;
				for (int xx = i; xx <= x; xx++) {
					for (int yy = j; yy <= y; yy++) {
						if (sign[xx][yy] != 0) ans.push_back(abs(sign[xx][yy]));
					}
				}
				sort(ans.begin(), ans.end()), ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
				printf("YES %d\n", ans.size());
				for (int i = 0; i < ans.size(); i++) {
					printf("%d ", ans[i]);
				}
				printf("\n");
				return 0;
			}
		}
	}
	printf("NO\n");
	return 0;
}