#include <math.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <set>
#include <string>
#include <cassert>
#include <queue>
#include <vector>
#define PB push_back
#define REP(i, n) for (int i = 0; i < n; ++i)
#define TR(it, n) for (__typeof(n.begin()) it = n.begin(); it != n.end(); ++it)

using namespace std;

int num[41][41][41][41];
int dp[41][41][41][41];

int par[41][41];
char img[41][41];
int n, m;

int go(int x1, int y1, int x2, int y2) {
  if (x1 > x2 || y1 > y2) return 0;
  int &res = dp[x1][y1][x2][y2];
  if (res != -1) return res;
  res = num[x1][y1][x2][y2];
  REP(i, 2) REP(j, 2) {
    if (!i && !j) continue;
    int nx2 = x2 - i;
    int ny2 = y2 - j;
    res += (((i + j) & 1) ? 1 : -1) * go(x1, y1, nx2, ny2);
  }
  return res;
}

int main() {
  int q;
  cin >> n >> m >> q;
  REP(i, n) cin >> img[i];
  memset(dp, -1, sizeof(dp));
  REP(i, n) REP(j, m) {
    int maxi = m;
    for (int k = i; k < n; ++k) {
      for (int r = j; r < maxi; ++r) {
        if (img[k][r] == '1') {
          maxi = min(maxi, r);
          break;
        }
        num[i][j][k][r] = 1;
      }
    }
  }
  REP(i, n) REP(j, m) {
    for (int k = i; k >= 0; --k) {
      for (int r = j; r >= 0; --r) {
        REP(x, 2) REP(y, 2) {
          if (!x && !y) continue;
          int nk = k + x;
          int nr = r + y;
          if (nk <= i && nr <= j) {
            int coef = (x + y == 2) ? -1 : 1;
            num[k][r][i][j] += coef * num[nk][nr][i][j];
          }
        }
      }
    }
  }//cout << num[0][0][1][1] << endl;
  REP(i, q) {
    int l1, r1, l2, r2;
    scanf("%d%d%d%d", &l1, &l2, &r1, &r2);
    --l1; --l2; --r1; --r2;
    cout << go(l1, l2, r1, r2) << endl;
  }
  return 0;
}