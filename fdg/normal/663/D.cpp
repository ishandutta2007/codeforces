#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int score[3][5005];
int cost[6] = {500, 1000, 1500, 2000, 2500, 3000};
int whatType[5005];

int getScore(int type, int tm) {
  if (tm == 0) return 0;
  return cost[type] * (250 - abs(tm)) / 250;
}

int dp[2][91][91][91];

int main() {
  int n;
  scanf("%d", &n);

  for (int i = 0; i <= n; ++i) {
    if (n < 2 * i && 2 * i <= 2 * n) whatType[i] = 0;
    if (n < 4 * i && 4 * i <= 2 * n) whatType[i] = 1;
    if (n < 8 * i && 8 * i <= 2 * n) whatType[i] = 2;
    if (n < 16 * i && 16 * i <= 2 * n) whatType[i] = 3;
    if (n < 32 * i && 32 * i <= 2 * n) whatType[i] = 4;
    if (32 * i <= n) whatType[i] = 5;
  }

  vector<int> who, other;
  int solved[3] = {0}, canHack[3] = {0};
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 3; ++j) {
      scanf("%d", &score[j][i]);
      if (score[j][i] != 0) ++solved[j];
      if (score[j][i] < 0) ++canHack[j];
    }
    if (score[0][i] < 0 || score[1][i] < 0 || score[2][i] < 0)
      who.push_back(i);
    else
      other.push_back(i);
  }
  if (canHack[0] + canHack[1] + canHack[2] >= 90) {
    puts("1");
    return 0;
  }

  int c[3] = {0}, ans = n;
  for (c[0] = 0; c[0] < 6; ++c[0]) {
    for (c[1] = 0; c[1] < 6; ++c[1]) {
      for (c[2] = 0; c[2] < 6; ++c[2]) {
        int maxHacks[3] = {0}, ok = 1;
        for (int t = 0; t < 3; ++t) {
          if (whatType[solved[t] - canHack[t]] < c[t] || whatType[solved[t]] > c[t]) ok = 0;
          for (int i = 0; i <= n; ++i) {
            if (whatType[i] == c[t]) {
              maxHacks[t] = min(canHack[t], solved[t] - i);
              break;
            }
          }
        }
        if (!ok) continue;
        int myScore = 100 * (maxHacks[0] + maxHacks[1] + maxHacks[2]) + getScore(c[0], score[0][0]) + getScore(c[1], score[1][0]) + getScore(c[2], score[2][0]);
        
        int cur = 0, next = 1;
        for (int x : who) {
          for (int a = 0; a <= maxHacks[0]; ++a) {
            for (int b = 0; b <= maxHacks[1]; ++b) {
              for (int cc = 0; cc <= maxHacks[2]; ++cc) {
                for (int mask = 0; mask < 8; ++mask) {
                  int cs = 0, addA = 0, addB = 0, addC = 0;
                  if ((mask & 1) && score[0][x] < 0) {
                    addA = 1;
                  } else {
                    cs += getScore(c[0], score[0][x]);
                  }
                  if ((mask & 2) && score[1][x] < 0) {
                    addB = 1;
                  } else {
                    cs += getScore(c[1], score[1][x]);
                  }
                  if ((mask & 1) && score[2][x] < 0) {
                    addC = 1;
                  } else {
                    cs += getScore(c[2], score[2][x]);
                  }
                  dp[next][a + addA][b + addB][cc + addC] = max(dp[next][a + addA][b + addB][cc + addC], dp[cur][a][b][cc] + (cs <= myScore));
                }
              }
            }
          }
          cur ^= 1; next ^= 1;
          for (int i = 0; i <= maxHacks[0] + 1; ++i)
            for (int j = 0; j <= maxHacks[1] + 1; ++j)
              for (int t = 0; t <= maxHacks[2] + 1; ++t)
                dp[next][i][j][t] = 0;
        }

        int ls = dp[cur][maxHacks[0]][maxHacks[1]][maxHacks[2]];
        for (int x : other) {
          int cs = getScore(c[0], score[0][x]) + getScore(c[1], score[1][x]) + getScore(c[2], score[2][x]);
          ls += (cs <= myScore);
          // cout << x << "  " << cs << "  " << myScore << endl;
        }
        ans = min(ans, n - ls + 1);

        for (int i = 0; i <= maxHacks[0] + 1; ++i)
          for (int j = 0; j <= maxHacks[1] + 1; ++j)
            for (int t = 0; t <= maxHacks[2] + 1; ++t)
              dp[cur][i][j][t] = 0;
      }
    }
  }
  cout << ans << endl;

  return 0;
}