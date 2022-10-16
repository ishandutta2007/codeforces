#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EDEBUG
#if defined(LOCAL) && defined(EDEBUG)
#include "includes/debug.cpp"
#else
#define debug(...)
#define dbgarr(...)
#define dbgline
#endif

/*input
2
1 1 1 1
10
1 1 1 1
1 1 1 2
1 1 2 1
1 1 2 2
1 2 1 2
1 2 2 1
1 2 2 2
2 1 2 1
2 1 2 2
2 2 2 2
*/
/*input
4
1 1 1 1
2 1 2 2
3 2 1 3
6
2 4 4 3
4 4 3 3
1 2 3 3
2 2 4 4
1 4 2 3
1 1 4 4
*/

long long

const int log2n = 17;
const int maxn = 100010;
long long din[log2n][2][2][maxn];
pair<long long, long long> doran(pair<long long, long long> a) {
	return {a.first + 1, a.second};
}
pair<long long, long long> dorbn(pair<long long, long long> a) {
	return {a.first, a.second + 1};
}
pair<long long, long long> dorap(pair<long long, long long> a) {
	return {a.first - 1, a.second};
}
pair<long long, long long> dorbp(pair<long long, long long> a) {
	return {a.first, a.second - 1};
}
long long dist(pair<int, int> a, pair<int, int> b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	long long n;
	cin >> n;
	pair<int, int> dora[n];
	pair<int, int> dorb[n];

	for (int i = 0; i < n - 1; ++i) {
		cin >> dora[i].first >> dora[i].second;
		cin >> dorb[i].first >> dorb[i].second;
		dora[i].first--;
		dora[i].second--;
		dorb[i].first--;
		dorb[i].second--;
	}

	for (int i = 0; i < n - 2; ++i) {
		din[0][0][0][i] = 1 + min(dist(doran(dora[i]), dora[i + 1]),
		                          dist(dora[i], dorb[i]) + dist(dorbn(dorb[i]), dora[i + 1]));
		din[0][0][1][i] = 1 + min(dist(doran(dora[i]), dorb[i + 1]),
		                          dist(dora[i], dorb[i]) + dist(dorbn(dorb[i]), dorb[i + 1]));
		din[0][1][0][i] = 1 + min(dist(dorbn(dorb[i]), dora[i + 1]),
		                          dist(dora[i], dorb[i]) + dist(doran(dora[i]), dora[i + 1]));
		din[0][1][1][i] = 1 + min(dist(dorbn(dorb[i]), dorb[i + 1]),
		                          dist(dora[i], dorb[i]) + dist(doran(dora[i]), dorb[i + 1]));
		debug(i, din[0][0][0][i], din[0][0][1][i], din[0][1][0][i], din[0][1][1][i]);
	}

	for (int j = 1; j < log2n; ++j) {
		const int po = (1 << j);

		for (int t = 0; t < 2; ++t) {
			for (int y = 0; y < 2; ++y) {
				for (int i = 0; i + po / 2 < n - 1; ++i) {
					din[j][t][y][i] = 10000000000000000;

					for (int v = 0; v < 2; ++v) {
						din[j][t][y][i] = min(din[j][t][y][i],
						                      din[j - 1][t][v][i] + din[j - 1][v][y][i + po / 2]
						                     );
					}
				}
			}
		}
	}

	debug(din[1][0][0][0], din[1][0][1][0], din[1][1][0][0], din[1][1][1][0]);


	int m;
	cin >> m;

	for (int i = 0; i < m; ++i) {
		long long ax, ay, bx, by;
		cin >> ax >> ay >> bx >> by;
		ax--, ay--;
		bx--, by--;
		long long a = max(ax, ay);
		long long b = max(bx, by);
		debug(ax, ay, bx, by);

		if (a == b) {
			cout << dist({ax, ay}, {bx, by}) << "\n";
			continue;
		}

		if (a > b) {
			swap(a, b);
			swap(ax, bx);
			swap(ay, by);
		}

		int dbr = a;
		long long dc[2][2] = {{0, dist(dora[a], dorb[a])}, {dist(dora[a], dorb[a]), 0}};

		for (int j = log2n - 1; j >= 0; --j) {
			const int po = (1 << j);

			if (dbr + po >= b) {
				continue;
			}

			long long dcne[2][2] = {};

			for (int t = 0; t < 2; ++t) {
				for (int y = 0; y < 2; ++y) {
					dcne[t][y] = 10000000000000000;

					for (int v = 0; v < 2; ++v) {
						dcne[t][y] = min(dcne[t][y],
						                 dc[t][v] + din[j][v][y][dbr]
						                );
					}
				}
			}

			for (int t = 0; t < 2; ++t) {
				for (int y = 0; y < 2; ++y) {
					dc[t][y] = dcne[t][y];
				}
			}

			debug(dbr, po, dc[0][0], dc[0][1], dc[1][0], dc[1][1]);
			dbr += po;
		}

		long long ans = 10000000000000000;
		debug(dist({ax, ay}, dora[a]), dc[0][0], dist({bx, by}, doran(dora[b - 1])));
		ans = min(ans, dist({ax, ay}, dora[a]) + dc[0][0] + dist({bx, by}, doran(dora[b - 1])));
		ans = min(ans, dist({ax, ay}, dora[a]) + dc[0][1] + dist({bx, by}, dorbn(dorb[b - 1])));
		ans = min(ans, dist({ax, ay}, dorb[a]) + dc[1][0] + dist({bx, by}, doran(dora[b - 1])));
		ans = min(ans, dist({ax, ay}, dorb[a]) + dc[1][1] + dist({bx, by}, dorbn(dorb[b - 1])));
		cout << ans + 1 << "\n";
	}
}