#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int arr[100002];

set<int> cand;

int T[100500], R[100500], last[100500];

void solve() {
  int n, k;
  scanf("%d%d", &n, &k);
  set<pair<int, int>> f;
  for (int i = 0; i < k; ++i) {
    scanf("%d", &arr[i]);
//    f.insert({arr[i], i});
  }

  cand.clear();
  int cnt[2] = {0}, zero = 0;
  for (int i = 0; i < k; ++ i)
    last[i] = -1;
  for (int i = 0; i + 1 < n; ++i) {
    scanf("%d%d", &T[i], &R[i]); --T[i];
    if (T[i] >= 0)
      last[T[i]] = i;
  }
  for (int i = 0; i < k; ++i)
    if (last[i] == -1)
      f.insert({arr[i], i});
  for (int i = 0; i + 1 < n; ++i) {
    int t = T[i], r = R[i];
      // if (!cand.count(t))
        // f.erase({arr[t], t});
    if (r == 0) {
    } else if (cand.size() == 0) {
      int mn = 1e+9;
      for (set<pair<int, int>>::iterator it = f.begin(); it != f.end();) {
        auto nx = it; ++nx;
        if (it->first <= zero && last[it->second] <= i) {
          mn = min(it->first, mn);
          cand.insert(it->second);
          f.erase(it);
        }
        it = nx;
      }
      zero -= mn;
      }
    if (t >= 0) {
      --arr[t];
      if (last[t] == i)
        f.insert({arr[t], t});
    } else {
      ++zero;
    }
  }
  for (int i = 0; i < k; ++i) {
    int left = arr[i] - zero;
    if (left <= 0 || cand.count(i)) printf("Y");
    else printf("N");
  }
  printf("\n");
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    solve();
  }
  return 0;
}