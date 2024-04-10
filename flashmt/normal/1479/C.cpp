#include <bits/stdc++.h>
using namespace std;

int main()
{
  int l, r;
  cin >> l >> r;
  cout << "YES" << endl;

  if (l == r)
  {
    cout << 2 << ' ' << 1 << endl;
    cout << 1 << ' ' << 2 << ' ' << l << endl;
    return 0;
  }

  vector<tuple<int, int, int>> ans;
  r -= l - 1;
  int bit = 1;
  while (1 << bit + 1 <= r)
    bit++;

  for (int i = 1; i <= bit + 1; i++)
  {
    ans.push_back({0, i, 1});
    for (int j = 1; j < i; j++)
      ans.push_back({j, i, 1 << j - 1});
  }

  int goal = bit + 1;
  if (1 << bit < r)
  {
    ans.push_back({0, ++goal, 1});
    r--;
    for (int i = bit, from = 2; i >= 0; i--)
      if (r >> i & 1)
      {
        ans.push_back({i + 1, goal, from - 1});
        from += 1 << i;
      }
  }

  if (l > 1)
  {
    goal++;
    ans.push_back({goal - 1, goal, l - 1});
  }

  cout << goal + 1 << ' ' << ans.size() << endl;
  for (auto [x, y, z] : ans)
    cout << x + 1 << ' ' << y + 1 << ' ' << z << endl;
}