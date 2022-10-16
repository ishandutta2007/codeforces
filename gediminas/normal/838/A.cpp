/*input
3 5
00100
10110
11001
*/
#include <bits/stdc++.h>

using namespace std;

int dal[2501][2501] = {};
int n, m;
bool mat[2501][2501];

int get(int x, int y) {
	x = min(x, n);
	y = min(y, m);
	return dal[x][y];
}

int get(int x1, int y1, int x2, int y2) {
	return get(x2, y2) + get(x1, y1) - get(x2, y1) - get(x1, y2);
}

int main () {
	ios_base::sync_with_stdio(false), cin.tie(0);
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char x;
			cin >> x;
			mat[i][j] = x == '1';
			dal[i + 1][j + 1] = dal[i + 1][j] + dal[i][j + 1] - dal[i][j] + mat[i][j];
		}
	}

	int ats = n * m;

	for (int k = 2; k < max(n, m); k++) {
		int temp = 0;

		for (int i = 0; i < n; i += k) {
			for (int j = 0; j < m; j += k)
				temp += min(get(i, j, i + k, j + k), k * k - get(i, j, i + k, j + k));
		}

		ats = min(ats, temp);
	}

	cout << ats;

	return 0;
}