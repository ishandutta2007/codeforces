/*input
2 13
ABCDEFGHIJKLM
NOPQRSTUVWXYZ

*/
#include <bits/stdc++.h>

using namespace std;

int ilg[50 + 2][50 + 2];

int main () {
	int n, m;
	cin >> n >> m;

	char lent[n + 2][m + 2] = {};

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> lent[i][j];
			ilg[i][j] = -1;
		}
	}

	bool ar = false;

	for (int i = 1; i <= n and !ar; i++) {
		for (int j = 1; j <= m and !ar; j++) {
			if (ilg[i][j] == -1) {
				queue<pair<int, int> > eil;
				eil.push(make_pair(i, j));
				ilg[i][j] = 0;

				while (!eil.empty() and !ar) {
					int di = eil.front().first, dj = eil.front().second;
					int dilg = ilg[di][dj];
					//cout << di << " " << dj << " " << dilg << endl;
					eil.pop();

#define bang(x,y) { \
	if (lent[di][dj] == lent[x][y]){\
		if(ilg[x][y] == -1){\
			eil.push(make_pair(x, y)); \
			ilg[x][y] = dilg + 1; \
		} \
		else if(ilg[x][y]>dilg){ \
			ar = true; \
		} \
	} \
}
					bang(di - 1, dj);
					bang(di + 1, dj);
					bang(di, dj - 1);
					bang(di, dj + 1);

#undef bang
				}

				//cout << endl;
			}
		}
	}

	cout << (ar ? "Yes" : "No");

	return 0;
}