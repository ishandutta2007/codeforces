#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

typedef pair<pair<int, int>, int> item;

vector<item> v;

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    v.push_back({{x, y}, i + 1});
  }
  sort(v.begin(), v.end());

  int p = 0, it = 0;
  for (int mx = 1000; mx <= 1000000; mx += 1000, it ^= 1) {
    vector<item> cur;
    while (p < v.size() && v[p].first.first <= mx) {
      cur.push_back(v[p]);
      swap(cur.back().first.first, cur.back().first.second);
      ++p;
    }
    if (it & 1)
      sort(cur.begin(), cur.end());
    else
      sort(cur.rbegin(), cur.rend());
    for (auto x : cur)
      printf("%d ", x.second);
  }
  printf("\n");
  return 0;
}