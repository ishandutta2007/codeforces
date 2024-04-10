#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

const int inf = 100000000;
int dp[1<<20];
bool was[1<<20];
char c[22]; int t[22];
int n, m;
int arr[102] = {0};

int solve(int it, int mask) {
  if (it == m) {
    return 0;
  }
  if (was[mask]) return dp[mask];
  was[mask] = true;
  int ret = inf - 1;
  if (c[it] == 'p') {
    if (t[it] == 1) {
      int mx = -inf;
      for (int i = 0; i < n; ++i) {
        if ((mask & (1<<i)) == 0) {
          int val = solve(it + 1, mask | (1<<i));
          mx = max(mx, val + arr[i]);
        }
      }
      ret = mx;
    }
    else {
      int mn = inf;
      for (int i = 0; i < n; ++i) {
        if ((mask & (1<<i)) == 0) {
          int val = solve(it + 1, mask | (1<<i));
          mn = min(mn, val - arr[i]);
        }
      }
      ret = mn;
    }
  } else {
    if (t[it] == 1) {
      int mxb = -inf;
      for (int i = 0; i < n; ++i) {
        if ((mask & (1<<i)) == 0) {
          int val = solve(it + 1, mask | (1<<i));
          mxb = max(mxb, val);
        }
      }
      ret = mxb;
    }
    else {
      int mnb = inf;
      for (int i = 0; i < n; ++i) {
        if ((mask & (1<<i)) == 0) {
          int val = solve(it + 1, mask | (1<<i));
          mnb = min(mnb, val);
        }
      }
      ret = mnb;
    }
  }

  return dp[mask] = ret;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &arr[i]);
  }
  sort(arr, arr + n);
  reverse(arr, arr + n);
  n = min(n, 20);

  scanf("%d\n", &m);
  for (int i = 0; i < m; ++i) {
    scanf("%c %d\n", &c[i], &t[i]);
  }
  printf("%d\n", solve(0, 0));
  return 0;
}