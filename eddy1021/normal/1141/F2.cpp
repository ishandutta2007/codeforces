#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1515;
unordered_map<int, vector<pair<int, int>>> c;
int n, a[N];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = i, s = 0; j >= 1; --j) {
      s += a[j];
      c[s].push_back({j, i});
    }
  }
  int bst = 0, who = 0;
  for (auto v: c) {
    int val = 0, lst = 0;
    for (auto p: v.second) {
      if (p.first > lst) {
        ++ val;
        lst = p.second;
      }
    }
    if (val > bst) {
      bst = val;
      who = v.first;
    }
  }
  vector<pair<int,int>> ans;
  int lst = 0;
  for (auto p: c[who]) {
    if (p.first > lst) {
      ans.push_back(p);
      lst = p.second;
    }
  }
  printf("%d\n", (int)ans.size());
  for (auto p: ans) {
    printf("%d %d\n", p.first, p.second);
  }
}