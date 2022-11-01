// October 7, 2018
// http://codeforces.com/contest/1033/problem/A

/*

*/


#include <bits/stdc++.h>

using namespace std;


struct point {
	int x, y;
};

const int MAXN = 1000;

int N;
point a, b, c;
bool allowed[MAXN][MAXN];
bool visited[MAXN][MAXN];
pair<int, int> dirs[8] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {1, -1}};

bool in_range(int x, int y) {
	return 0 <= x && x < N && 0 <= y && y < N;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG


	cin >> N >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
	a.x--; a.y--; b.x--; b.y--; c.x--; c.y--;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			allowed[i][j] = true;
		}
	}
	allowed[a.x][a.y] = false;
	for (int i = 0; i < N; i++) {
		if (in_range(a.x - i, a.y - i)) allowed[a.x - i][a.y - i] = false;
		if (in_range(a.x - i, a.y + i)) allowed[a.x - i][a.y + i] = false;
		if (in_range(a.x + i, a.y - i)) allowed[a.x + i][a.y - i] = false;
		if (in_range(a.x + i, a.y + i)) allowed[a.x + i][a.y + i] = false;
		if (in_range(a.x, a.y - i)) allowed[a.x][a.y - i] = false;
		if (in_range(a.x, a.y + i)) allowed[a.x][a.y + i] = false;
		if (in_range(a.x - i, a.y)) allowed[a.x - i][a.y] = false;
		if (in_range(a.x + i, a.y)) allowed[a.x + i][a.y] = false;
	}
	queue< pair<int, int> > q;
	q.push({b.x, b.y});
	visited[b.x][b.y] = true;
	while (!q.empty()) {
		int x, y;
		tie(x, y) = q.front(); q.pop();
		for (auto u : dirs) {
			int nx = x + u.first, ny = y + u.second;
			if (!in_range(nx, ny) || !allowed[nx][ny] || visited[nx][ny]) continue;
			visited[nx][ny] = true;
			q.push({nx, ny});
		}
	}
	cout << (visited[c.x][c.y] ? "YES" : "NO") << '\n';


	return 0;
}