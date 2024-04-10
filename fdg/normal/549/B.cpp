#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int main() {
  int n;
  scanf("%d\n", &n);
  char f[102][102] = {0};
  int cnt[102] = {0}, used[102] = {0};
  for (int i = 0; i < n; ++i) {
    gets(f[i]);
    for (int j = 0; j < n; ++j) {
      cnt[j] += f[i][j] == '1';
    }
  }
  for (int i = 0; i < n; ++i) {
    int a;
    scanf("%d", &a);
    cnt[i] -= a;
  }
  for (int it = 0; it <= n; ++it) {
    int ind = -1;
    for (int i = 0; i < n; ++i) {
      if (cnt[i] == 0 && !used[i]) {
        ind = i;
      }
    }
    if (ind == -1) {
      printf("%d\n", n - it);
      for (int i = 0; i < n; ++i) {
        if (!used[i])
          printf("%d ", i + 1);
      }
      printf("\n");
      return 0;
    }
    used[ind] = true;
    for (int j = 0; j < n; ++j) {
      cnt[j] -= f[ind][j] == '1';
    }
  }
  return 0;
}