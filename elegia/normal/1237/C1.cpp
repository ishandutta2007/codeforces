#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cstring>

#include <algorithm>
#include <numeric>
#include <functional>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
#endif

  int n;
  scanf("%d", &n);
  vector<pair<vector<int>, int>> p(n, make_pair(vector<int>(3), 0));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 3; ++j)
      scanf("%d", &p[i].first[j]);
    p[i].second = i + 1;
  }
  function<vector<pair<vector<int>, int>>(vector<pair<vector<int>, int>>)> solve = [&](vector<pair<vector<int>, int>> p) {
    sort(p.begin(), p.end());
    vector<pair<vector<int>, int>> res, stk;
    stk.push_back(p[0]);
    p.push_back(make_pair(vector<int>(1, -1), -1));
    for (int i = 1; i < p.size(); ++i) {
      if (stk[0].first[0] != p[i].first[0]) {
        if (stk.size() > 1) {
          vector<pair<vector<int>, int>> tr;
          for (const auto& pr : stk)
            tr.push_back(make_pair(vector<int>(pr.first.begin() + 1, pr.first.end()), pr.second));
          tr = solve(tr);
          if (tr.empty())
            stk.clear();
          else {
            tr[0].first.insert(tr[0].first.begin(), stk[0].first[0]);
            stk = tr;
          }
        }
        for (const auto& pr : stk)
          res.push_back(pr);
        stk.clear();
      }
      stk.push_back(p[i]);
    }
    while (res.size() >= 2) {
      printf("%d %d\n", res.back().second, res[res.size() - 2].second);
      res.pop_back();
      res.pop_back();
    }
    return res;
  };
  solve(p);

  return 0;
}