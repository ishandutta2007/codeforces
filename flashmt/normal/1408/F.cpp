#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  if (n == 1)
  {
    cout << "0\n";
    return 0;
  }

  vector<pair<int, int>> ans;

  function<void(int, int)> go = [&](int l, int r)
  {
    if (l == r)
      return;
    int m = (l + r) / 2;
    go(l, m);
    go(m + 1, r);
    for (int i = l, j = m + 1; i <= m; i++, j++)
      ans.push_back({i, j});
  };

  vector<vector<int>> blocks;
  for (int i = 13, cur = 0; i >= 0; i--)
    if (n >> i & 1)
    {
      go(cur + 1, cur + (1 << i));
      vector<int> newBlock;
      for (int j = 1; j <= 1 << i; j++)
        newBlock.push_back(cur + j);
      blocks.push_back(newBlock);
      cur += 1 << i;
    }

  while (size(blocks) > 2)
  {
    int u = size(blocks) - 1, v = u - 1;
    while (size(blocks[u]) < size(blocks[v]))
    {
      for (int i = size(blocks[u]) - 1; i >= 0; i--)
      {
        int x = blocks[0].back();
        blocks[0].pop_back();
        ans.push_back({blocks[u][i], x});
        blocks[u].push_back(x);
      }
    }

    for (int i = 0; i < size(blocks[u]); i++)
    {
      ans.push_back({blocks[u][i], blocks[v][i]});
      blocks[v].push_back(blocks[u][i]);
    }
    blocks.pop_back();
  }

  cout << size(ans) << '\n';
  for (auto [x, y] : ans)
    cout << x << ' ' << y << '\n';
}