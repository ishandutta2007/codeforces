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
  int n, k, p;
  scanf("%d%d%d", &n, &k, &p);
  vector<int> v[2];
  for (int i = 0; i < n; ++i) {
    int a;
    scanf("%d", &a);
    v[a & 1].push_back(a);
  }
  if (v[1].size() >= k - p && (v[1].size() - (k - p)) % 2 == 0 && v[0].size() + ((v[1].size() - (k - p)) / 2) >= p) {
    puts("YES");
    int it = 0, t = 0;
    for (int i = 0; i < p - 1; ++i) {
      if (it < v[0].size())
        printf("1 %d\n", v[0][it++]);
      else {
        printf("2 %d %d\n", v[1][t++], v[1][t++]);
      }
    }
    int add = p == k ? (v[1].size() - t) : 0;
    if (p && it < v[0].size()) {
      printf("%d", v[0].size() - it + add);
      while (it < v[0].size()) {
        printf(" %d", v[0][it++]);
      }
    } else if (p > 0) {
      int sz = min(2 + add, (int) v[1].size() - t);
      printf("%d %d %d", sz, v[1][t++], v[1][t++]);
    }
    while (add && t < v[1].size()) {
      printf(" %d", v[1][t++]);
      --add;
    }
    if (p > 0) printf("\n");
    int IT = it;
    it = t;
    for (int i = p; i < k - 1; ++i) {
      printf("1 %d\n", v[1][it++]);
    }
    if (it < v[1].size()) {
      printf("%d", v[1].size() - it + v[0].size() - IT);
      while (it < v[1].size()) {
        printf(" %d", v[1][it++]);
      }
      while (IT < v[0].size()) {
        printf(" %d", v[0][IT++]);
      }
      printf("\n");
    }
  } else {
    puts("NO");
  }
  return 0;
}