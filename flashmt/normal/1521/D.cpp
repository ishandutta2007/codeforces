#include <bits/stdc++.h>
using namespace std;

vector<int> a[100100];
vector<pair<int, int>> paths, removedEdges;
int lowest[100100];

void visit(int x, int par)
{
  lowest[x] = x;
  for (int y : a[x])
    if (y != par)
    {
      visit(y, x);
      if (!lowest[y]) removedEdges.push_back({x, y});
      else if (lowest[x] == x) lowest[x] = lowest[y];
      else if (lowest[x])
      {
        paths.push_back({lowest[x], lowest[y]});
        lowest[x] = 0;
      }
      else
      {
        removedEdges.push_back({x, y});
        paths.push_back({y, lowest[y]});
      }
    }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test, n;
  cin >> test;
  while (test--)
  {
    cin >> n;
    for (int i = 1; i <= n; i++)
      a[i].clear();
    for (int i = 1; i < n; i++)
    {
      int x, y;
      cin >> x >> y;
      a[x].push_back(y);
      a[y].push_back(x);
    }

    paths.clear();
    removedEdges.clear();
    visit(1, 0);
    if (lowest[1])
      paths.push_back({1, lowest[1]});
    assert(removedEdges.size() + 1 == paths.size());
    cout << removedEdges.size() << '\n';
    for (int i = 0; i < removedEdges.size(); i++)
    {
      cout << removedEdges[i].first << ' ' << removedEdges[i].second << ' ';
      cout << paths[i].second << ' ' << paths[i + 1].first << '\n';
    }
  }
}