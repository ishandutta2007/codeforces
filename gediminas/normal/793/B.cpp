/*input
5 5
S....
****.
.....
.****
..T..
*/
#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

#define mp make_pair
#define x first
#define y second
struct bang {
	pair<int, int> koord;
	int kryp, gal;
	bang(pair<int, int> koord, int kryp): koord(koord), kryp(kryp), gal(2) { }
	bang(int x, int y, int kryp, int gal): koord(mp(x, y)), kryp(kryp), gal(gal) { }
};

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	bool zem[n][m];

	pair<int, int> pra, pab;
	bool apl[n][m][4][3];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char x;
			cin >> x;
			zem[i][j] = x == '.' or x == 'T';

			if (x == 'S')
				pra = mp(i, j);

			if (x == 'T')
				pab = mp(i, j);

			for (int l = 0; l < 4; l++)
				for (int k = 0; k < 3; k++)
					apl[i][j][l][k] = false;
		}
	}

	queue<bang> eil;

	for (int i = 0; i < 4; i++)
		eil.push(bang(pra, i));

	while (!eil.empty()) {
		bang d = eil.front();
		eil.pop();

		//cout << d.koord.x << " "  << d.koord.y << " "  << d.kryp << " " << d.gal << "\n";

		if (d.koord == pab) {
			cout << "YES";
			return 0;
		}

		if (d.koord.x > 0 and zem[d.koord.x - 1][d.koord.y]) {
			if (d.kryp == 0 and !apl[d.koord.x - 1][d.koord.y][0][d.gal]) {
				eil.push(bang(d.koord.x - 1, d.koord.y, 0, d.gal));
				apl[d.koord.x - 1][d.koord.y][0][d.gal] = true;
			}
			else if (d.gal > 0 and d.kryp != 2 and !apl[d.koord.x - 1][d.koord.y][0][d.gal - 1]) {
				eil.push(bang(d.koord.x - 1, d.koord.y, 0, d.gal - 1));
				apl[d.koord.x - 1][d.koord.y][0][d.gal - 1] = true;
			}
		}

		if (d.koord.y > 0 and zem[d.koord.x][d.koord.y - 1]) {
			if (d.kryp == 1 and !apl[d.koord.x][d.koord.y - 1][1][d.gal]) {
				eil.push(bang(d.koord.x, d.koord.y - 1, 1, d.gal));
				apl[d.koord.x][d.koord.y - 1][1][d.gal] = true;
			}
			else if (d.gal > 0 and d.kryp != 3 and !apl[d.koord.x][d.koord.y - 1][1][d.gal - 1]) {
				eil.push(bang(d.koord.x, d.koord.y - 1, 1, d.gal - 1));
				apl[d.koord.x][d.koord.y - 1][1][d.gal - 1] = true;
			}
		}

		if (d.koord.x < n - 1 and zem[d.koord.x + 1][d.koord.y]) {
			if (d.kryp == 2 and !apl[d.koord.x + 1][d.koord.y][2][d.gal]) {
				eil.push(bang(d.koord.x + 1, d.koord.y, 2, d.gal));
				apl[d.koord.x + 1][d.koord.y][2][d.gal] = true;
			}
			else if (d.gal > 0 and d.kryp != 0 and !apl[d.koord.x + 1][d.koord.y][2][d.gal - 1]) {
				eil.push(bang(d.koord.x + 1, d.koord.y, 2, d.gal - 1));
				apl[d.koord.x + 1][d.koord.y][2][d.gal - 1] = true;
			}
		}

		if (d.koord.y < m - 1 and zem[d.koord.x][d.koord.y + 1]) {
			if (d.kryp == 3 and !apl[d.koord.x][d.koord.y + 1][3][d.gal]) {
				eil.push(bang(d.koord.x, d.koord.y + 1, 3, d.gal));
				apl[d.koord.x][d.koord.y + 1][3][d.gal] = true;
			}
			else if (d.gal > 0 and d.kryp != 1 and !apl[d.koord.x][d.koord.y + 1][3][d.gal - 1]) {
				eil.push(bang(d.koord.x, d.koord.y + 1, 3, d.gal - 1));
				apl[d.koord.x][d.koord.y + 1][3][d.gal - 1] = true;
			}
		}
	}

	cout << "NO";

	return 0;
}