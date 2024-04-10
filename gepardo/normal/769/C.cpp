#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	const int inf = 1234567890;
	const char dnam[4] = {'D', 'L', 'R', 'U'};
	const int    dx[4] = { +1,   0,   0,  -1};
	const int    dy[4] = {  0,  -1,  +1,   0};
	static char mat[1024][1024];
	static int  dst[1024][1024];
	int n, m, k; cin >> n >> m >> k;
	int sx, sy;
	for (int i = 0; i < n; i++) {
		cin >> mat[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mat[i][j] == 'X') {
				tie(sx, sy) = make_tuple(i, j);
				mat[i][j] = '.';
			} 
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			dst[i][j] = inf;
		}
	}
	auto good = [&](int x, int y) -> bool {
		return 0 <= x && x < n &&
		       0 <= y && y < m &&
		       mat[x][y] == '.';
	};
	queue< pair<int, int> > q;
	q.emplace(sx, sy);
	dst[sx][sy] = 0;
	while (!q.empty()) {
		int x, y;
		tie(x, y) = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (good(nx, ny) && dst[nx][ny] == inf) {
				q.emplace(nx, ny);
				dst[nx][ny] = dst[x][y] + 1;
			}
		} 
	}
	int qx = sx, qy = sy;
	string res = "";
	for (; k > 0; k--) {
		bool ok = false;
		for (int i = 0; i < 4; i++) {
			int nx = qx + dx[i], ny = qy + dy[i];
			if (good(nx, ny) && dst[nx][ny] < k) {
				tie(qx, qy) = make_tuple(nx, ny);
				res += dnam[i];
				ok = true;
				break;
			}
		}
		if (!ok) {
			cout << "IMPOSSIBLE" << endl;
			return 0;
		}
	}
	cout << res << endl;
	return 0;
}