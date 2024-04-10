#include <bits/stdc++.h>
using namespace std;

int n, k, dist[200200], par[200200], color[200200], longest[200200];
vector<int> a[200200];

void noAnswer()
{
  cout << "No\n";
  exit(0);
}

void dfs(int x)
{
  for (int y : a[x])
    if (dist[y] < 0)
    {
      dist[y] = dist[x] + 1;
      par[y] = x;
      dfs(y);
    }
}

vector<int> findFurthest(int x)
{
  memset(dist, -1, sizeof dist);
  dist[x] = 0;
  dfs(x);
  int y = x;
  for (int i = 1; i <= n; i++)
    if (dist[i] > dist[y])
      y = i;
  vector<int> path(1, y);
  while (y != x)
  {
    y = par[y];
    path.push_back(y);
  }
  return path;
}

void dfsColor(int x, int colorShift)
{
  int secondLongest = 0;
  for (int y : a[x])
    if (color[y] < 0)
    {
      color[y] = (color[x] + colorShift) % k;
      dfsColor(y, colorShift);
      if (longest[y] + 1 > longest[x])
      {
        secondLongest = longest[x];
        longest[x] = longest[y] + 1;
      }
      else secondLongest = max(secondLongest, longest[y] + 1);
    }

  if (secondLongest && longest[x] + secondLongest >= k - 1 && k >= 3)
    noAnswer();
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int x, y;
  cin >> n >> k;
  for (int i = 1; i < n; i++)
  {
    cin >> x >> y;
    a[x].push_back(y);
    a[y].push_back(x);
  }

  int u = findFurthest(1)[0];
  vector<int> diameter = findFurthest(u);
  memset(color, -1, sizeof color);
  int diameterSz = diameter.size();
  for (int i = 0; i < diameterSz; i++)
    color[diameter[i]] = i % k;

  if (diameterSz < k)
  {
    cout << "Yes\n";
    for (int i = 0; i < n; i++)
      cout << 1 << " \n"[i == n - 1];
    return 0;
  }

  for (int i = 0; i < diameterSz; i++)
  {
    int x = diameter[i];
    int colorShift = i < diameterSz / 2 ? k - 1 : 1;
    dfsColor(x, colorShift);
    if (longest[x] && longest[x] + min(i, diameterSz - 1 - i) >= k - 1 && k >= 3)
      noAnswer();
  }

  cout << "Yes\n";
  for (int i = 1; i <= n; i++)
    cout << color[i] + 1 << " \n"[i == n];
}