#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

vector<pair<int, int>> v;

int main() {
  int n, k, a;
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a);
    v.push_back({a, i + 1});
  }
  sort(v.begin(), v.end());
  int cnt = 0;
  for (int i = 0; i < n; ++i)
    if (v[i].first <= k) {
      ++cnt;
      k -= v[i].first;
    }
  printf("%d\n", cnt);
  for (int i = 0; i < cnt; ++i) {
    if (i) printf(" ");
    printf("%d", v[i].second);
  }
  printf("\n");
  return 0;
}