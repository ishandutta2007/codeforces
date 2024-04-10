#include <bits/stdc++.h>
using namespace std;
const int N = 2000;

int m, n;
pair<int, int> cols[N][N];
bitset<N> rows[N], ones[N];
set<pair<int, int>> s, valid;

int isGood(int x, int y)
{
  auto u = rows[x] | rows[y];
  if (u == rows[x] || u == rows[y])
    return 0;
  int colX = (u ^ rows[y])._Find_first();
  int colY = (u ^ rows[x])._Find_first();
  cols[x][y] = cols[y][x] = {min(colX, colY), max(colX, colY)};
  return 1;
}

void remove(int x)
{
  auto u = s.find({rows[x].count(), x}), r = next(u);
  if (r != s.end())
    valid.erase({x, r->second});
  if (u != s.begin())
  {
    auto l = prev(u);
    valid.erase({l->second, x});
    if (r != s.end() && isGood(l->second, r->second))
      valid.insert({l->second, r->second});
  }
  s.erase(u);
}

void insert(int x)
{
  pair<int, int> p(rows[x].count(), x);
  s.insert(p);
  auto u = s.find(p), r = next(u);
  if (r != s.end() && isGood(x, r->second))
    valid.insert({x, r->second});
  if (u != s.begin())
  {
    auto l = prev(u);
    if (isGood(l->second, x))
      valid.insert({l->second, x});
    if (r != s.end())
      valid.erase({l->second, r->second});
  }
}

void query(int x, int y, int yy)
{
  remove(x);
  rows[x] ^= ones[yy];
  if (y)
    rows[x] ^= ones[y - 1];
  insert(x);
  if (valid.empty()) cout << "-1\n";
  else
  {
    int u = valid.begin()->first, v = valid.begin()->second;
    if (u > v)
      swap(u, v);
    cout << u + 1 << ' ' << cols[u][v].first + 1 << ' ' << v + 1 << ' ' << cols[u][v].second + 1 << '\n';
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  for (int i = 0; i < N; i++)
    for (int j = 0; j <= i; j++)
      ones[i][j] = 1;

  int q, x, y, yy;
  cin >> m >> n >> q;
  for (int i = 0; i < m; i++)
    s.insert({0, i});

  while (q--)
  {
    cin >> x >> y >> yy;
    query(--x, --y, --yy);
  }
}