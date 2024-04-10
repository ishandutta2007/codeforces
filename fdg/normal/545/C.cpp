#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int x[100005], h[100005];

set<int> f;
vector<int> all;
vector<pair<int, int>> var;

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &x[i], &h[i]);
    f.insert(x[i]);
    f.insert(x[i] + h[i]);
    all.push_back(x[i]);
    var.push_back({x[i], x[i] - h[i]});
    var.push_back({x[i] + h[i], x[i]});
  }
  sort(var.begin(), var.end());
  vector<pair<int, int>> v(1, make_pair(-2000000000, 0));
  int ans = 0;
  for (int i = 0; i < var.size();) {
    int j = i;
    int pos = lower_bound(v.begin(), v.end(), make_pair(var[j].first, 0)) - v.begin() - 1;
    int val = pos >= 0 ? v[pos].second : 0;
    // cout << var[j].first << " " << val << endl;
    while (i < var.size() && var[i].first == var[j].first) {
      auto p = var[i];
      // if (p.first < p.second) {
      //   swap(p.first, p.second);
      // }
      bool can = lower_bound(all.begin(), all.end(), p.second) + 1 == upper_bound(all.begin(), all.end(), p.first);
      if (can) {
        // cout << "can\n";
        int pos1 = lower_bound(v.begin(), v.end(), make_pair(p.second, 0)) - v.begin() - 1;
        int add = pos1 >= 0 ? v[pos1].second : 0;
        val = max(val, 1 + add);
      }
      ++i;
    }
    v.push_back({var[j].first, val});
    ans = max(ans, val);
  }
  printf("%d\n", ans);
  return 0;
}