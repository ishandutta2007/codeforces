#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int p[100005], used[100005], was[100005];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &p[i]);
    --p[i];
  }
  vector<pair<int, int>> e;
  vector<int> ones;
  vector<vector<int>> other;
  bool hasOdd = false;
  for (int i = 0; i < n; ++i) {
    if (!used[i]) {
      vector<int> c;
      int cur = i;
      while (!used[cur]) {
        c.push_back(cur);
        used[cur] = true;
        cur = p[cur];
      }
      if (c.size() > 2) {
        other.push_back(c);
        if (c.size() & 1)
          hasOdd = true;
      } else if (c.size() == 1) {
        ones.push_back(c[0]);
        was[c[0]] = true;
      } else {
        e.push_back({c[0], c[1]});
      }
    }
  }
  if (ones.size() == 0 && other.size() == 0) {
    puts("YES");
    printf("%d %d\n", e[0].first + 1, e[0].second + 1);
    for (int i = 1; i < e.size(); ++i) {
      printf("%d %d\n", e[i - 1].first + 1, e[i].first + 1);
      printf("%d %d\n", e[i - 1].second + 1, e[i].second + 1);
    }
    return 0;
  }
  if (ones.size()) {
    puts("YES");
    for (int i = 1; i < ones.size(); ++i) {
      printf("%d %d\n", ones[i - 1] + 1, ones[i] + 1);
    }
    for (int i = 0; i < n; ++i) {
      if (!was[i])
        printf("%d %d\n", ones[0] + 1, i + 1);
    }
    return 0;
  }
  if (e.size() && !hasOdd) {
    puts("YES");
    printf("%d %d\n", e[0].first + 1, e[0].second + 1);
    for (int i = 1; i < e.size(); ++i) {
      printf("%d %d\n", e[i - 1].first + 1, e[i].first + 1);
      printf("%d %d\n", e[i - 1].second + 1, e[i].second + 1);
    }
    for (int t = 0; t < other.size(); ++t) {
      int it = 0;
      for (int x : other[t]) {
        printf("%d %d\n", x + 1, (it ? e[0].first : e[0].second) + 1);
        it ^= 1;
      }
    }
    return 0;
  }
  puts("NO");
  return 0;
}