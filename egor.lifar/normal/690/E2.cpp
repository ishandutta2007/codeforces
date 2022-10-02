#include <iostream>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
#include <set>
#include <map>
#include <cmath>
#include <cassert>
#include <queue>


using namespace std;


int q;
int h, w, k;
int a[600][600];
int dist[17][17];
int dp[17][65539];
int from[17][65539];
int pos[17];


int getdown(int x, int y) {
	int sum = 0;
	for (int i = x - 4; i <= x; i++) {
		for (int j = y - 2; j <= y + 2; j++) {
			sum += a[i][j];
		}
	}
	return sum;
}


int getup(int x, int y) {
	int sum = 0;
	for (int i = x; i <= x + 4; i++) {
		for (int j = y - 2; j <= y + 2; j++) {
			sum += a[i][j];
		}
	}
	return sum;
}


int main() {
	//freopen("outputx.txt", "r", stdin);
	cin >> q;
	for (int ii = 0; ii < q; ii++) {
		scanf("%d %d %d", &h, &w, &k);
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				scanf("%d", &a[i][j]);
			}
		}
		for (int i = 0; i < k; i++) {
			for (int j = 0; j < k; j++) {
				if (i != j) {
					dist[i][j] = 0;
					for (int kk = 5; kk < w - 5; kk++) {
						dist[i][j] += abs(getdown((i + 1) * (h / k) - 1, kk) - getup(j * (h / k), kk));
					}
				}
			}
		}
		// for (int i = 0; i < k; i++) {
		// 	for (int j = 0; j < k; j++) {
		// 		cout << dist[i][j] << ' ';
		// 	}
		// 	cout << endl;
		// }
		for (int mask = 0; mask < (1 << k); mask++) {
			for (int who = 0; who < k; who++) {
				dp[who][mask] = 1000000000;
			}
		}
		for (int mask = 0; mask < (1 << k); mask++) {
			for (int who = 0; who < k; who++) {
				if (!((1 << who) & mask)) {
					continue;
				}
				if (mask == (1 << who)) {
					dp[who][mask] = 0;
				}
				if (dp[who][mask] == 1000000000) {
					continue;
				}
				for (int next = 0; next < k; next++) {
					if (!((1 << next) & mask)) {
						int NewMask = mask | (1 << next);
						if (dp[next][NewMask] > dp[who][mask] + dist[who][next]) {
							dp[next][NewMask] = dp[who][mask] + dist[who][next];
							from[next][NewMask] = who;
						}
					}
				}	
			}
		}
		int ans = 1000000000;
		int i, j;
		for (int who = 0; who < k; who++) {
			ans = min(ans, dp[who][(1 << k) - 1]);
			if (ans == dp[who][(1 << k) - 1]) {
				i = who;
				j = (1 << k) - 1;
			}
		}
		//cout << ans << endl;
		vector<int> anss;
		//cout << "opa" << endl;
		while (j != 0) {
			int ni = from[i][j];
			anss.push_back(i + 1);
			j ^= (1 << i);
			i = ni;
		}
		reverse(anss.begin(), anss.end());
		for (int i = 0; i < (int)anss.size(); i++) {
			pos[anss[i]] = i + 1;
		}
		for (int i = 1; i <= k; i++) {
			printf("%d ", pos[i]);
		}
		printf("\n");
	}
	return 0;
}