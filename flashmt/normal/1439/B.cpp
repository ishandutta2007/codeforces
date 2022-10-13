#include <bits/stdc++.h>
using namespace std;

int n, k, deg[100100], flagged[100100];
unordered_set<int> a[100100];

vector<int> checkClique(int x)
{
  vector<int> clique(1, x);
  for (int y : a[x])
    if (!flagged[y])
      clique.push_back(y);
  assert(clique.size() == k);

  for (int i = 1; i < k; i++)
    for (int j = i + 1; j < k; j++)
      if (!a[clique[i]].count(clique[j]))
        return {};

  return clique;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int test;
  cin >> test;
  while (test--)
  {
    int m;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
    {
      a[i].clear();
      deg[i] = flagged[i] = 0;
    }

    while (m--)
    {
      int x, y;
      cin >> x >> y;
      a[--x].insert(--y);
      a[y].insert(x);
      deg[x]++;
      deg[y]++;
    }

    set<pair<int, int>> s;
    for (int i = 0; i < n; i++)
      s.insert({deg[i], i});

    int foundAns = 0;
    while (!s.empty())
    {
      int x = s.begin()->second;
      if (deg[x] == k)
      {
        cout << 1 << ' ' << s.size() << '\n';
        for (auto [_, y] : s)
          cout << y + 1 << ' ';
        cout << '\n';
        foundAns = 1;
        break;
      }

      if (deg[x] == k - 1)
      {
        auto clique = checkClique(x);
        if (!clique.empty())
        {
          cout << "2\n";
          for (int y : clique)
            cout << y + 1 << ' ';
          cout << '\n';
          foundAns = 1;
          break;
        }
      }

      flagged[x] = 1;
      s.erase(s.begin());
      for (int y : a[x])
        if (!flagged[y])
        {
          s.erase({deg[y], y});
          s.insert({--deg[y], y});
        }
    }

    if (!foundAns)
      cout << "-1\n";
  }
}