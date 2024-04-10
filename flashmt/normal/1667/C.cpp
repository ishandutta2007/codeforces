#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#endif
using namespace std;
const vector<vector<pair<int, int>>> ANS = {
  {{0, 0}},
  {{0, 0}},
  {{0, 0}, {0, 1}},
  {{0, 0}, {1, 2}, {2, 1}}
};

int main()
{
  int n;
  cin >> n;
  vector<pair<int, int>> ans;
  if (n <= size(ANS)) ans = ANS[n - 1];
  else
  {
    ans.push_back({0, 0});
    int k = (n - 1) / 3;
    for (int i = 1; i <= k; i++)
      ans.push_back({i, i * 2});
    for (int i = 1; i <= k; i++)
      ans.push_back({k + i, i * 2 - 1});
    if (n % 3 == 0)
      ans.push_back({n - 1, n - 1});
  }

  cout << size(ans) << '\n';
  for (auto [x, y] : ans)
    cout << x + 1 << ' ' << y + 1 << '\n';
}