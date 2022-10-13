#include <bits/stdc++.h>
using namespace std;

vector<int> adj[666], cycle;

int ask(vector<int> s)
{
  if (s.size() < 2)
    return 0;
  cout << "? " << s.size() << endl;
  for (int x : s)
    cout << x << ' ';
  cout.flush();
  int m;
  cin >> m;
  return m;
}

int askEdgeBetween(vector<int> a, vector<int> b)
{
  vector<int> ab(a);
  for (int x : b)
    ab.push_back(x);
  return ask(ab) - ask(a) - ask(b);
}

pair<int, int> findEdge(vector<int> a, vector<int> b)
{
  int low = 0, high = a.size() - 1;
  while (low < high)
  {
    int mid = (low + high) / 2;
    vector<int> curA(a.begin() + low, a.begin() + mid + 1);
    if (askEdgeBetween(curA, b)) high = mid;
    else low = mid + 1;
  }
  int x = a[low];

  low = 0;
  high = b.size() - 1;
  while (low < high)
  {
    int mid = (low + high) / 2;
    vector<int> curB(b.begin() + low, b.begin() + mid + 1);
    if (askEdgeBetween({x}, curB)) high = mid;
    else low = mid + 1;
  }
  int y = b[low];

  return {x, y};
}

pair<int, int> findEdge(vector<int> a)
{
  int low = 0, high = a.size() - 1;
  while (low < high)
  {
    int mid = (low + high) / 2;
    vector<int> lower(a.begin(), a.begin() + mid + 1);
    vector<int> upper(a.begin() + mid + 1, a.end());
    if (ask(lower)) high = mid;
    else if (ask(upper)) low = mid + 1;
    else return findEdge(lower, upper);
  }
  return {-1, -1};
}

void dfs(int x, int target, int par)
{
  cycle.push_back(x);
  if (x == target)
  {
    cout << "N " << cycle.size() << endl;
    for (int x : cycle)
      cout << x << ' ';
    cout << endl;
    exit(0);
  }
  for (int y : adj[x])
    if (y != par)
      dfs(y, target, x);
  cycle.pop_back();
}

int main()
{
  int n;
  vector<int> side[2];
  cin >> n;
  vector<int> color(n + 1, -1);
  queue<int> q;
  q.push(1);
  color[1] = 0;
  side[0].push_back(1);
  // bfs to all nodes
  while (!q.empty())
  {
    int x = q.front();
    q.pop();
    vector<int> unvisited;
    for (int i = 1; i <= n; i++)
      if (color[i] < 0)
        unvisited.push_back(i);

    if (unvisited.empty())
      break;

    int edges = askEdgeBetween({x}, unvisited);
    for (int i = 0; i < edges; i++)
    {
      auto [_, y] = findEdge({x}, unvisited);
      adj[x].push_back(y);
      adj[y].push_back(x);
      color[y] = color[x] ^ 1;
      side[color[y]].push_back(y);
      q.push(y);

      for (int j = 0; j < unvisited.size(); j++)
        if (unvisited[j] == y)
        {
          unvisited.erase(unvisited.begin() + j);
          break;
        }
    }
  }

  // check if there is an odd cycle
  for (int i = 0; i < 2; i++)
    if (ask(side[i]))
    {
      auto [x, y] = findEdge(side[i]);
      dfs(x, y, 0);
    }

  // is bipartite
  cout << "Y " << side[0].size() << endl;
  for (int x : side[0])
    cout << x << ' ';
  cout << endl;
}