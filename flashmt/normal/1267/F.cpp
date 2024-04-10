#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m, ka, kb, a[200200], b[200200];
  cin >> n >> m >> ka >> kb;
  vector<int> lastId(m + n + 1, -1);
  for (int i = 0; i < ka; i++)
  {
    cin >> a[i];
    lastId[a[i]] = i;
  }
  for (int i = 0; i < kb; i++)
  {
    cin >> b[i];
    lastId[b[i]] = i;
  }

  set<int> leaves;
  for (int i = 1; i <= n + m; i++)
    if (lastId[i] < 0)
      leaves.insert(i);

  vector<pair<int, int>> edges;
  for (int i = 0, j = 0; i < ka || j < kb;)
  {
    if (leaves.empty())
    {
      cout << "No" << endl;
      return 0;
    }

    int leave = *leaves.begin();
    leaves.erase(leave);

    if (leave <= n)
    {
      if (j == kb) edges.push_back({b[kb - 1], leave});
      else
      {
        edges.push_back({b[j], leave});
        if (lastId[b[j]] == j && j < kb - 1)
          leaves.insert(b[j]);
        j++;
      }
    }
    else
    {
      if (i == ka) edges.push_back({a[ka - 1], leave});
      else
      {
        edges.push_back({a[i], leave});
        if (lastId[a[i]] == i && i < ka - 1)
          leaves.insert(a[i]);
        i++;
      }
    }
  }

  for (auto leave : leaves)
    edges.push_back({leave <= n ? b[kb - 1] : a[ka - 1], leave});

  edges.push_back({a[ka - 1], b[kb - 1]});

  cout << "Yes\n";
  for (auto [x, y] : edges)
    cout << x << ' ' << y << '\n';
}