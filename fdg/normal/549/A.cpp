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
  int n, m;
  scanf("%d%d\n", &n, &m);
  char f[55][55] = {0};
  for (int i = 0; i < n; ++i) {
    gets(f[i]);
  }
  int ans = 0;
  vector<int> v(26, 0);
  v['f' - 'a']++;
  v['a' - 'a']++;
  v['c' - 'a']++;
  v['e' - 'a']++;
  for (int i = 0; i + 1 < n; ++i) {
    for (int j = 0; j + 1 < m; ++j) {
      vector<int> cur(26, 0);
      for (int dx = 0; dx < 2; ++dx)
        for (int dy = 0; dy < 2; ++dy) 
          cur[f[i + dx][j + dy] - 'a'] ++;
      ans += cur == v;
    }
  }
  printf("%d\n", ans);
  return 0;
}