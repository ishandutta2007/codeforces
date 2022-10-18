#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int n, m;
int arr[200005];

int solve(int ind, int len, int dir, int prev, int cnt) {
  if (cnt == 2) {
    return ind;
  }
  if (dir == 1) {
    int l = ind, r = n;
    while (r - l > 1) {
      int m = (l + r) >> 1;
      if (arr[m] - arr[ind] <= len) l = m;
      else r = m;
    }

    if (l != ind) {
      if (l == prev) {
        int nlen = len - (arr[l] - arr[ind]);
        nlen %= 2 * abs(arr[l] - arr[ind]);
        return solve(l, nlen, -1, ind, 0);
      }
      return solve(l, len - (arr[l] - arr[ind]), -1, ind, 0);
    }

    return solve(ind, len, -1, ind, cnt + 1);
  } else {
    int l = -1, r = ind;
    while (r - l > 1) {
      int m = (l + r) >> 1;
      if (arr[ind] - arr[m] <= len) r = m;
      else l = m;
    }

    if (r != ind) {
      if (r == prev) {
        int nlen = len - (arr[ind] - arr[r]);
        nlen %= 2 * abs(arr[ind] - arr[r]);
        return solve(r, nlen, 1, ind, 0);
      }
      return solve(r, len - (arr[ind] - arr[r]), 1, ind, 0);
    }

    return solve(ind, len, 1, ind, cnt + 1);
  }

  return ind;
}

pair<int, int> tmp[200002];
int wh[200002];

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &arr[i]);
    tmp[i].first = arr[i];
    tmp[i].second = i;
  }
  sort(tmp, tmp + n);
  for (int i = 0; i < n; ++i) {
    arr[i] = tmp[i].first;
    wh[tmp[i].second] = i;
  }
  while (m--) {
    int a, l;
    scanf("%d%d", &a, &l); --a;
    printf("%d\n", tmp[solve(wh[a], l, 1, -1, 0)].second + 1);
  }
  return 0;
}