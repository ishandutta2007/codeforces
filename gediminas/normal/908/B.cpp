/*input
5 3
...
.S.
###
.E.
...
3
*/
#include <bits/stdc++.h>

using namespace std;

int main () {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	char lent[n][m];
	int sx, sy;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> lent[i][j];

			if (lent[i][j] == 'S')
				sx = i, sy = j;
		}
	}

	string ej;
	cin >> ej;

	pair<int, int> mas[4] = {{0, 1}, {1, 0}, {0, -1}, { -1, 0}};
	sort(mas, mas + 4);
	int ats = 0;

	do {
		int dx = sx, dy = sy;

		for (auto && x : ej) {
			dx += mas[x - '0'].first;
			dy += mas[x - '0'].second;

			if (dx<0 or dy<0 or dx >= n or dy >= m)
				break;

			if (lent[dx][dy] == '#')
				break;

			if (lent[dx][dy] == 'E') {
				ats++;
				break;
			}

		}
	}
	while (next_permutation(mas, mas + 4));

	cout << ats;

	return 0;
}