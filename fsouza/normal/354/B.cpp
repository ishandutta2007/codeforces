#include <iostream>
#include <cstdio>
#include <algorithm>
#include <numeric>
#include <climits>
#include <sstream>
#include <cstring>
#include <cassert>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <map>
#include <set>

#define INF (INT_MAX/3)
#define MAXN 20

typedef long long lint;

using namespace std;

char table[MAXN][MAXN];

/* diag, player, mask */
int dp[2][2][1<<MAXN];

int nextmask[1<<MAXN];
int cmask[26];

int main(int argc, char ** argv)
{
	int n;

	scanf("%d", &n);
	
	for (int y = 0; y < n; y++)
		for (int x = 0; x < n; x++)
			scanf(" %c", &table[y][x]);

	int now = 0, prev = 1;

	for (int player = 0; player < 2; player++)
		dp[prev][player][1] = 0;

	for (int sum = 2*(n-1)-1; sum >= 0; sum--) {
		static int diagx[MAXN], diagy[MAXN];
		int ndiag = 0;

		for (int x = 0; x < n; x++) {
			int y = sum - x;
			if (0 <= y && y < n) {
				diagx[ndiag] = x;
				diagy[ndiag] = y;
				ndiag ++;
			}
		}

		memset(nextmask, 0, sizeof(int)*(1<<ndiag));
		memset(cmask, 0, sizeof(int)*26);

		for (int i = 0; i < ndiag; i++) {
			int x = diagx[i], y = diagy[i];

			static int dx[] = {0, 1}, dy[] = {1, 0};
			for (int d = 0; d < 2; d++) {
				int x2 = x + dx[d], y2 = y + dy[d];
				if (0 <= x2 && x2 < n && 0 <= y2 && y2 < n) {
					int nextp;

					if (sum < n-1)
						nextp = i+(d==1);
					else
						nextp = i-(d==0);

					nextmask[1<<i] |= 1<<nextp;

					cmask[table[y2][x2]-'a'] |= 1<<nextp;
				}
			}
		}

		for (int mask = 1; mask < (1<<ndiag); mask++)
			if (mask != (mask&-mask))
				nextmask[mask] = nextmask[mask&-mask] | nextmask[mask-(mask&-mask)];

		for (int player = 0; player < 2; player++) {
			for (int mask = 1; mask < (1<<ndiag); mask++) {
				int &res = dp[now][player][mask];

				res = ((player == 0) ? (-INF) : INF);

				for (int c = 0; c < 26; c++) {
					int nm = nextmask[mask] & cmask[c];
					if (nm) {
						int delta = 0;
						if (c == 0) delta = 1;
						if (c == 1) delta = -1;

						if (player == 0) {
							res = max(res, delta + dp[prev][player^1][nm]);
						} else {
							res = min(res, delta + dp[prev][player^1][nm]);
						}
					}
				}
			}
		}

		swap(now, prev);
	}


	int result = 0;
	if (table[0][0] == 'a') result ++;
	if (table[0][0] == 'b') result --;
	result += dp[prev][1][1];

	if (result > 0)
		printf("FIRST\n");
	else if (result < 0)
		printf("SECOND\n");
	else
		printf("DRAW\n");

	return 0;
}