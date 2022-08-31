#include <cstdio>
#include <cstring>

#include <algorithm>

using namespace std;

const int N = 110;

int n, m, sx, sy, cx, cy;
int perm[] = {0, 1, 2, 3};
int dx[] = {0, 0, 1, -1}, dy[] = {-1, 1, 0, 0};
char d[N];
char mz[N][N];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%s", mz[i] + 1);
		for (int j = 1; j <= m; ++j)
			if (mz[i][j] == 'S') {
				sx = i;
				sy = j;
			}
	}
	scanf("%s", d);
	memset(mz[0] + 1, '#', sizeof(char) * m);
	memset(mz[n + 1] + 1, '#', sizeof(char) * m);
	for (int i = 1; i <= n; ++i)
		mz[i][0] = mz[i][m + 1] = '#';
	int ans = 0;
	do {
		cx = sx;
		cy = sy;
		for (char* p = d; *p; ++p) {
			cx += dx[perm[*p - '0']];
			cy += dy[perm[*p - '0']];
			if (mz[cx][cy] == 'E') {
				++ans;
				break;
			}
			if (mz[cx][cy] == '#')
				break;
		}
	} while (next_permutation(perm, perm + 4));
	printf("%d\n", ans);
	return 0;
}