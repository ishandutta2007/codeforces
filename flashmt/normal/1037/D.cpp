#include <bits/stdc++.h>
using namespace std;

int n, order[200200];
vector<int> a[200200];

void dfs(int x, int par)
{
  vector<int> children;
  for (int y : a[x])
    if (y != par)
    {
      dfs(y, x);
      children.push_back(y);
    }

  sort(children.begin(), children.end(), [](int u, int v) { return order[u] < order[v]; });
  a[x] = children;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 1; i < n; i++)
  {
    int x, y;
    cin >> x >> y;
    a[x].push_back(y);
    a[y].push_back(x);
  }

  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    order[x] = i;
  }

  dfs(1, 0);

  queue<int> q;
  q.push(1);
  for (int i = 0; i < n; i++)
  {
    int x = q.front();
    q.pop();
    if (order[x] != i)
    {
      cout << "No" << endl;
      return 0;
    }

    for (int y : a[x])
      q.push(y);
  }

  cout << "Yes" << endl;
}