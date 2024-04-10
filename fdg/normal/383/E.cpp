#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

char str[10005][5];
int cnt[1<<24];

int main() {
  int n;
  scanf("%d\n", &n);
  for (int i = 0; i < n; ++i) {
    gets(str[i]);
    int mask = 0;
    for (int j = 0; j < 3; ++j) {
      mask |= 1 << (str[i][j] - 'a'); 
    }
    cnt[mask]++;
  }
  for (int j = 0; j < 24; ++j) {
    for (int i = 0; i < (1<<24); ++i) {
      if (i & (1<<j))
        cnt[i] += cnt[i - (1<<j)];
    }
  }
  int ans = 0;
  for (int i = 0; i < (1<<24); ++i) {
    ans ^= (n - cnt[i]) * (n - cnt[i]);
  }
  printf("%d\n", ans);
  return 0;
}