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
  int n, k;
  cin >> n >> k;
  vector<pair<int, int>> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i].first;
    v[i].second = i;
  }
  sort(v.begin(), v.end());
  vector<int> ans[101];
  bool ok = true;
  int col = 1;
  for (int i = 0; i < v[0].first; ++i) {
    ans[v[0].second].push_back(col);
    col = min(col + 1, k);
  }
  for (int i = 1; i < n; ++i) {
    if (v[0].first + k < v[i].first) ok = false;
    ans[v[i].second] = ans[v[0].second];
    for (int j = 1; j <= v[i].first - v[0].first; ++j) {
      ans[v[i].second].push_back(j);
    }
  }

  if (ok) {
    puts("YES");
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < ans[i].size(); ++j) {
        if (j) printf(" ");
        printf("%d", ans[i][j]);
      }
      printf("\n");
    }
  } else {
    puts("NO");
  }
  return 0;
}