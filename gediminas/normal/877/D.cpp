/*input
3 4 4
....
###.
....
1 1 3 1
*/
#include <bits/stdc++.h>

using namespace std;

int main () {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	bool mas[n][m];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char x;
			cin >> x;
			mas[i][j] = x == '.';
		}
	}

	bool filled[n][m][4] = {};

	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	x1--, y1--, x2--, y2--;
	queue<pair<int, int> > eil;
	eil.push(make_pair(x1, y1));

	int trunk[n][m] = {};
	trunk[x1][y1] = 0;
	filled[x1][y1][0] = true;
	filled[x1][y1][1] = true;
	filled[x1][y1][2] = true;
	filled[x1][y1][3] = true;

#define isvis(x,y) (!filled[x][y][0] and !filled[x][y][1] and !filled[x][y][2] and !filled[x][y][3])

	while (!eil.empty()) {
		int x = eil.front().first;
		int y = eil.front().second;
		eil.pop();

		if (x == x2 and y == y2) {
			cout << trunk[x][y];
			return 0;
		}

		for (int xi = x + 1; xi < n and abs(xi - x) <= k and !filled[xi][y][0] and mas[xi][y]; xi++) {
			if (isvis(xi, y)) {
				trunk[xi][y] = trunk[x][y] + 1;
				eil.push(make_pair(xi, y));
			}

			filled[xi][y][0] = true;
		}

		for (int xi = x - 1; xi >= 0 and abs(xi - x) <= k and !filled[xi][y][1] and mas[xi][y]; xi--) {
			if (isvis(xi, y)) {
				trunk[xi][y] = trunk[x][y] + 1;
				eil.push(make_pair(xi, y));
			}

			filled[xi][y][1] = true;
		}

		for (int yi = y + 1; yi < m and abs(yi - y) <= k and !filled[x][yi][2] and mas[x][yi]; yi++) {
			if (isvis(x, yi)) {
				trunk[x][yi] = trunk[x][y] + 1;
				eil.push(make_pair(x, yi));
			}

			filled[x][yi][2] = true;
		}

		for (int yi = y - 1; yi >= 0 and abs(yi - y) <= k and !filled[x][yi][3] and mas[x][yi]; yi--) {
			if (isvis(x, yi)) {
				trunk[x][yi] = trunk[x][y] + 1;
				eil.push(make_pair(x, yi));
			}

			filled[x][yi][3] = true;
		}
	}

	cout << -1;

	return 0;
}