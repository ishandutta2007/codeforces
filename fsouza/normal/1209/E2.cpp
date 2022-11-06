#include <algorithm>
#include <array>
#include <bitset>
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
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long lint;

const int maxn = 12;

int nr, nc;
lint dp[2][maxn+1][maxn][1<<maxn];
vector<vector<int>> cols;

int main() {
  int nt;
  scanf("%d", &nt);
  for (int t = 0; t < nt; ++t) {
    scanf("%d %d", &nr, &nc);
    cols = vector<vector<int>>(nc, vector<int>(nr));
    for (int y = 0; y < nr; ++y)
      for (int x = 0; x < nc; ++x)
        scanf("%d", &cols[x][y]);
    for (int x = 0; x < nc; ++x) {
      rotate(cols[x].begin(), max_element(cols[x].begin(), cols[x].end()),
             cols[x].end());
    }
    sort(cols.begin(), cols.end(),
         [](const vector<int> &a, const vector<int> &b) {
           return a.front() > b.front();
         });
    if (nc > nr) {
      cols.resize(nr);
      nc = nr;
    }

    memset(dp, -1, sizeof(dp));
    for (int c = nc - 1; c >= 0; --c) {
      memset(dp[c % 2], -1, sizeof(dp[c % 2]));

      for (int r = nr; r >= 0; --r) {
        for (int start = 0; start < nr; ++start) {
          for (int mask = 0; mask < (1<<nr); ++mask) {

            lint &result = dp[c % 2][r][start][mask];

            if (r == nr) {
              if (c == nc - 1) {
                if (mask == (1<<nr) - 1) {
                  result = 0LL;
                  continue;
                } else {
                  result = LLONG_MIN;
                  continue;
                }
              }
              result = LLONG_MIN;
              for (int s2 = 0; s2 < nr; ++s2)
                result = max(result, dp[(c + 1) % 2][0][s2][mask]);
              continue;
            }

            result = dp[c % 2][r + 1][start][mask];
            if ((mask & (1<<r)) == 0) {
              lint res = dp[c % 2][r + 1][start][mask | (1<<r)];
              if (res != LLONG_MIN) {
                int r2 = r + start;
                if (r2 >= nr) r2 -= nr;
                result = max(result, res + cols[c][r2]);
              }
            }
          }
        }
      }
    }

    lint result = LLONG_MIN;
    for (int y = 0; y < nr; ++y)
      result = max(result, dp[0][0][y][0]);
    printf("%lld\n", result);
  }
  return 0;
}