/*input
*/
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200000;
const int SQRT = 450; // 450
const int KIB = MAXN / SQRT + 2;
short a[MAXN];
list<short> keisti[KIB][101];
int main () {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;

	for (int i = 0; i < KIB; i++) {
		for (short j = 1; j <= 100; j++)
			keisti[i][j].push_back(j);
	}

	for (int i = 0; i < n; i++)
		cin >> a[i];

	int m;
	cin >> m;

	for (int i = 0; i < m; i++) {
		int f, t, x, y;
		cin >> f >> t >> x >> y;
		f--, t--;

		for (int kur : {
					f / SQRT, t / SQRT
				}) {
			short keist[101] = {};

			for (short i = 1; i <= 100; i++) {
				for (auto && x : keisti[kur][i])
					keist[x] = i;
			}

			for (int i = kur * SQRT; i < (kur + 1)*SQRT; i++) {
				a[i] = keist[a[i]];

				if (a[i] == x and f <= i and i <= t)
					a[i] = y;
			}

			for (short i = 1; i <= 100; i++)
				keisti[kur][i] = {i};
		}

		for (int i = f / SQRT + 1; i < t / SQRT; i++)
			keisti[i][y].merge(keisti[i][x]);
	}

	for (int kur = 0; kur <= MAXN / SQRT; kur++) {
		int keist[101] = {};

		for (int i = 1; i <= 100; i++) {
			for (auto && x : keisti[kur][i])
				keist[x] = i;
		}

		for (int i = kur * SQRT; i < (kur + 1) * SQRT; i++)
			a[i] = keist[a[i]];


		for (int i = 1; i <= 100; i++)
			keisti[kur][i].resize(0);
	}

	for (int i = 0; i < n; i++)
		cout << a[i] << " ";


	return 0;
}