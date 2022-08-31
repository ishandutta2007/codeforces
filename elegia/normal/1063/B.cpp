#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cstdlib>

#include <algorithm>
#include <numeric>
#include <limits>
#include <functional>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <queue>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int N = 2010;

int dx[4] = {0, 0, -1, 1},
    dy[4] = {-1,1,  0, 0};

int n, m;
char s[N];
bool g[N][N];
int dis[N][N];

int main() {
#ifdef LBT
	freopen("test.in", "r", stdin);
	int nol_cl = clock();
#endif

	int x, y, a, b;
	int y1;
	scanf("%d%d%d%d%d%d", &n, &m, &x, &y, &a, &b);
	y1 = y;
	memset(dis, -1, sizeof(dis));
	for (int i = 1; i <= n; ++i) {
		scanf("%s", s + 1);
		for (int j = 1; j <= m; ++j)
			g[i][j] = s[j] == '.';
	}
	dis[x][y] = 0;
	queue<int> qx, qy;
	stack<int> tx, ty;
	qx.push(x);
	qy.push(y);
	while (!qx.empty() || !tx.empty()) {
		if (!tx.empty()) {
			x = tx.top();
			y = ty.top();
			tx.pop();
			ty.pop();
		} else {
			x = qx.front();
			y = qy.front();
			qx.pop();
			qy.pop();
		}
		for (int dir = 0; dir < 4; ++dir)
			if (g[x + dx[dir]][y + dy[dir]] && (dis[x + dx[dir]][y + dy[dir]] == -1 || dis[x + dx[dir]][y + dy[dir]] > dis[x][y] + (dir == 0))) {
				if (dir == 0) {
					dis[x + dx[dir]][y + dy[dir]] = dis[x][y] + 1;
					qx.push(x + dx[dir]);
					qy.push(y + dy[dir]);
				} else {
					dis[x + dx[dir]][y + dy[dir]] = dis[x][y];
					tx.push(x + dx[dir]);
					ty.push(y + dy[dir]);
				}
			}
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			if (g[i][j] && dis[i][j] != -1) {
				int aa = dis[i][j], bb = aa - y1 + j;
				if (aa <= a && bb <= b)
					++ans;
			}
	printf("%d\n", ans);

#ifdef LBT
	LOG("Time: %dms\n", int((clock() - nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
	return 0;
}