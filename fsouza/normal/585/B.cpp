#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long lint;

int main() {
  int nt;
  scanf("%d", &nt);
  for (int t = 0; t < nt; ++t) {
    int ncol, ntrain;
    scanf("%d %d", &ncol, &ntrain);
    vector<string> field(3, string(ncol, ' '));
    for (int y = 0; y < 3; y++) scanf("%s", &field[y][0]);

    ncol += 3;
    for (int y = 0; y < 3; ++y) field[y] += string("...");

    int sy = -1, sx = -1;
    for (int y = 0; y < 3; ++y)
      for (int x = 0; x < ncol; ++x)
	if (field[y][x] == 's') {
	  sy = y, sx = x;
	  field[y][x] = '.';
	}

    vector<vector<bool>> dp(3, vector<bool>(ncol, false));
    for (int y = 0; y < 3; ++y)
      dp[y][ncol-1] = dp[y][ncol-2] = dp[y][ncol-3] = true;

    for (int x = ncol-4; x >= 0; --x) {
      for (int y = 0; y < 3; ++y) {
	if (field[y][x+1] != '.') continue;
	if (y > 0 && field[y-1][x+1] == '.' && field[y-1][x+2] == '.' && field[y-1][x+3] == '.' && dp[y-1][x+3])
	  dp[y][x] = true;
	if (y+1 < 3 && field[y+1][x+1] == '.' && field[y+1][x+2] == '.' && field[y+1][x+3] == '.' && dp[y+1][x+3])
	  dp[y][x] = true;
	if (field[y][x+2] == '.' && field[y][x+3] == '.' && dp[y][x+3])
	  dp[y][x] = true;
      }
    }

    if (dp[sy][sx]) printf("YES\n");
    else printf("NO\n");
  }

  return 0;
}