#include <cstdio>

#include <limits>

using namespace std;

typedef long long ll;

const int N = 110;

int n, m;
int g[N][N];
int col[N], row[N];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			scanf("%d", &g[i][j]);
	for (int i = n; i; --i)
		for (int j = m; j; --j)
			g[i][j] -= g[i - 1][j] + g[i][j - 1] - g[i - 1][j - 1];
	for (int i = 2; i <= n; ++i)
		for (int j = 2; j <= m; ++j) {
			if (g[i][j]) {
				puts("-1");
				return 0;
			}
		}
	int cnt, ansk, anscnt = numeric_limits<int>::max();
	for (int k = 0; k <= g[1][1]; ++k) {
		for (int i = 1; i <= n; ++i)
			col[i] = g[i][1];
		for (int i = 1; i <= m; ++i)
			row[i] = g[1][i];
		col[1] = k;
		row[1] -= k;
		cnt = 0;
		bool flag = true;
		for (int i = 1; i <= n; ++i) {
			if (col[i] < 0) {
				flag = false;
				break;
			}
			cnt += col[i];
			col[i + 1] += col[i];
		}
		if (!flag)
			continue;
		for (int i = 1; i <= m; ++i) {
			if (row[i] < 0) {
				flag = false;
				break;
			}
			cnt += row[i];
			row[i + 1] += row[i];
		}
		if (!flag)
			continue;
		if (cnt < anscnt) {
			anscnt = cnt;
			ansk = k;
		}
	}
	printf("%d\n", anscnt);
	for (int i = 1; i <= n; ++i)
		col[i] = g[i][1];
	for (int i = 1; i <= m; ++i)
		row[i] = g[1][i];
	col[1] = ansk;
	row[1] -= ansk;
	cnt = 0;
	for (int i = 1; i <= n; ++i) {
		for (int rep = 0; rep < col[i]; ++rep)
			printf("row %d\n", i);
		col[i + 1] += col[i];
	}
	for (int i = 1; i <= m; ++i) {
		for (int rep = 0; rep < row[i]; ++rep)
			printf("col %d\n", i);
		row[i + 1] += row[i];
	}
	return 0;
}