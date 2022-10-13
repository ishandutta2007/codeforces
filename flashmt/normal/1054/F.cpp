#include <bits/stdc++.h>
using namespace std;

struct HopcroftKarp
{
  vector<int> leftMatch, rightMatch, dist, cur;
  vector<vector<int>> a;
  int m, n;

  HopcroftKarp(int m, int n): m(m), n(n)
  {
    a = vector<vector<int>>(m);
    leftMatch = vector<int>(n, -1);
    rightMatch = dist = cur = vector<int>(m, -1);
  }

  void addEdge(int x, int y)
  {
    a[x].push_back(y);
  }

  int bfs()
  {
    int found = 0;
    queue<int> q;
    for (int i = 0; i < m; i++)
      if (rightMatch[i] < 0)
      {
        dist[i] = 0;
        q.push(i);
      }
      else dist[i] = -1;

    while (!q.empty())
    {
      int x = q.front();
      q.pop();
      for (int y : a[x])
        if (leftMatch[y] < 0) found = 1;
        else if (dist[leftMatch[y]] < 0)
        {
          dist[leftMatch[y]] = dist[x] + 1;
          q.push(leftMatch[y]);
        }
    }

    return found;
  }

  int dfs(int x)
  {
    for (; cur[x] < a[x].size(); cur[x]++)
    {
      int y = a[x][cur[x]];
      if (leftMatch[y] < 0 || (dist[leftMatch[y]] == dist[x] + 1 && dfs(leftMatch[y])))
      {
        leftMatch[y] = x;
        rightMatch[x] = y;
        return 1;
      }
    }
    return 0;
  }

  int maxMatch()
  {
    int match = 0;
    while (bfs())
    {
      cur.assign(m, 0);
      for (int i = 0; i < m; i++)
        if (rightMatch[i] < 0)
          match += dfs(i);
    }
    return match;
  }

  pair<vector<int>, vector<int>> maxIndependentSet()
  {
    maxMatch();
    vector<int> flag(n, 0), l, r;
    for (int i = 0; i < m; i++)
      if (dist[i] >= 0)
      {
        l.push_back(i);
        if (rightMatch[i] >= 0)
          flag[rightMatch[i]] = 1;
      }
    for (int i = 0; i < n; i++)
      if (!flag[i])
        r.push_back(i);
    return {l, r};
  }
};

void traceHor(vector<int> id, vector<pair<int, int>> a, vector<tuple<int, int, int>> segments)
{
  vector<tuple<int, int, int>> res;
  set<pair<int, int>> flag;
  for (int i = 0; i < id.size();)
  {
    auto [y, x0, x1] = segments[id[i]];
    i++;
    flag.insert({y, x0});
    flag.insert({y, x1});
    while (i < id.size())
    {
      auto [yy, xx0, xx1] = segments[id[i]];
      if (yy == y && xx0 == x1) x1 = xx1;
      else break;
      flag.insert({y, x1});
      i++;
    }
    res.push_back({y, x0, x1});
  }
  for (auto [y, x] : a)
    if (!flag.count({y, x}))
      res.push_back({y, x, x});

  cout << res.size() << '\n';
  for (auto [y, x0, x1] : res)
    cout << x0 << ' ' << y << ' ' << x1 << ' ' << y << '\n';
}

void traceVer(vector<int> id, vector<pair<int, int>> a, vector<tuple<int, int, int>> segments)
{
  vector<tuple<int, int, int>> res;
  set<pair<int, int>> flag;
  for (int i = 0; i < id.size();)
  {
    auto [x, y0, y1] = segments[id[i]];
    i++;
    flag.insert({x, y0});
    flag.insert({x, y1});
    while (i < id.size())
    {
      auto [xx, yy0, yy1] = segments[id[i]];
      if (xx == x && yy0 == y1) y1 = yy1;
      else break;
      flag.insert({x, y1});
      i++;
    }
    res.push_back({x, y0, y1});
  }
  for (auto [x, y] : a)
    if (!flag.count({x, y}))
      res.push_back({x, y, y});

  cout << res.size() << '\n';
  for (auto [x, y0, y1] : res)
    cout << x << ' ' << y0 << ' ' << x << ' ' << y1 << '\n';
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int k;
  vector<pair<int, int>> a, b;
  set<int> allX, allY;
  cin >> k;
  for (int i = 0; i < k; i++)
  {
    int x, y;
    cin >> x >> y;
    allX.insert(x);
    allY.insert(y);
    a.push_back({x, y});
    b.push_back({y, x});
  }

  vector<tuple<int, int, int>> hor, ver;
  sort(a.begin(), a.end());
  for (int i = 0; i + 1 < k; i++)
    if (a[i].first == a[i + 1].first)
      ver.push_back({a[i].first, a[i].second, a[i + 1].second});

  sort(b.begin(), b.end());
  for (int i = 0; i + 1 < k; i++)
    if (b[i].first == b[i + 1].first)
      hor.push_back({b[i].first, b[i].second, b[i + 1].second});

  int m = ver.size(), n = hor.size();
  HopcroftKarp hk(m, n);
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
    {
      auto [x, y0, y1] = ver[i];
      auto [y, x0, x1] = hor[j];
      if (x0 < x && x < x1 && y0 < y && y < y1)
        hk.addEdge(i, j);
    }

  auto [l, r] = hk.maxIndependentSet();
  traceHor(r, b, hor);
  traceVer(l, a, ver);
}