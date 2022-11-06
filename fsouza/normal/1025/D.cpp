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

const int maxn = 700;

bool dp[maxn][maxn][2];
bool has_edge[maxn][maxn];

int gcd(int a, int b) {
  if (a == 0) return b;
  return gcd(b%a, a);
}

int main() {
  int n;
  scanf("%d", &n);
  vector<int> values(n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &values[i]);

  for (int i = 0; i < n; ++i)
    for (int j = i + 1; j < n; ++j)
      has_edge[i][j] = has_edge[j][i] = (gcd(values[i], values[j]) > 1);

  for (int s = 1; s <= n; ++s)
    for (int i = 0; i + s <= n; ++i) {
      const int j = i + s - 1;
      for (int dir = 0; dir < 2; ++dir) {
        bool &res = dp[i][j][dir];
        res = false;

        int parent;
        if (dir == 0) {
          if (i == 0) continue;
          parent = i - 1;
        } else {
          if (j == n - 1) continue;
          parent = j + 1;
        }

        for (int k = i; k <= j; ++k) {
          if (!has_edge[k][parent])
            continue;
          bool ok_left, ok_right;
          if (k == i) ok_left = true;
          else ok_left = dp[i][k - 1][1];
          if (k == j) ok_right = true;
          else ok_right = dp[k + 1][j][0];
          if (ok_left && ok_right) {
            res = true;
            break;
          }
        }
      }
    }

  bool result = false;
  const int i = 0, j = n - 1;
  for (int k = i; k <= j; ++k) {
    bool ok_left, ok_right;
    if (k == i) ok_left = true;
    else ok_left = dp[i][k - 1][1];
    if (k == j) ok_right = true;
    else ok_right = dp[k + 1][j][0];
    if (ok_left && ok_right) {
      result = true;
      break;
    }
  }

  printf(result ? "Yes\n" : "No\n");

  return 0;
}