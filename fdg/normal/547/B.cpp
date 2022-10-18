#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int ans[200005];

multiset<int> lens;
set<pair<int, int>> f;

int main() {
  int n;
  scanf("%d", &n);
  vector<pair<int, int>> v;
  for (int i = 0; i < n; ++i) {
    int a;
    scanf("%d", &a);
    v.push_back({a, i});
  }
  sort(v.begin(), v.end());

  lens.insert(n);
  f.insert({0, n});

  int last = n + 1;
  for (int i = 0; i < v.size(); ) {
    int j = i;
    while (i < v.size() && v[i].first == v[j].first) {
      auto it = f.upper_bound({v[i].second, n + 2}); --it;
      int l = it->first, r = it->first + it->second - 1, len = it->second;
      if (l < v[i].second) {
        f.insert({l, v[i].second - l});
        lens.insert(v[i].second - l);
      }
      if (v[i].second < r) {
        f.insert({v[i].second + 1, r - v[i].second});
        lens.insert(r - v[i].second);
      }
      lens.erase(lens.find(len));
      f.erase(it);
      ++i;
    }
    if (lens.size() > 0) {
      auto it = lens.end();
      --it;
      int what = v[j].first, mx = *it;
      for (int i = mx + 1; i < last; ++i) {
        ans[i] = what;
      }
      last = mx + 1;
    } else {
      while(--last) ans[last] = v[j].first;
    }

  }

  for (int i = 1; i <= n; ++i) {
    printf("%d ", ans[i]);
  }
  printf("\n");
  return 0;
}