#include <bits/stdc++.h>
using namespace std;

struct Point
{
  int x, y, z, id;

  bool operator <(const Point &u)
  {
    if (x != u.x)
      return x < u.x;
    if (y != u.y)
      return y < u.y;
    return z < u.z;
  }
};

bool compYZ(Point u, Point v)
{
  if (u.y != v.y)
    return u.y < v.y;
  if (u.z != v.z)
    return u.z < v.z;
  return u.x < v.x;
}

bool compZX(Point u, Point v)
{
  if (u.z != v.z)
    return u.z < v.z;
  if (u.x != v.x)
    return u.x < v.x;
  return u.y < v.y;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  vector<Point> a;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    int x, y, z;
    cin >> x >> y >> z;
    a.push_back({x, y, z, i});
  }

  vector<Point> b;
  sort(a.begin(), a.end(), compZX);
  for (int i = 0; i < a.size(); i++)
    if (!b.empty() && a[i].x == b.back().x && a[i].z == b.back().z)
    {
      cout << a[i].id + 1 << ' ' << b.back().id + 1 << '\n';
      b.pop_back();
    }
    else b.push_back(a[i]);

  vector<Point> c;
  sort(b.begin(), b.end(), compYZ);
  for (int i = 0; i < b.size(); i++)
    if (!c.empty() && b[i].y == c.back().y && b[i].z == c.back().z)
    {
      cout << b[i].id + 1 << ' ' << c.back().id + 1 << '\n';
      c.pop_back();
    }
    else c.push_back(b[i]);

  vector<Point> d;
  sort(c.begin(), c.end());
  for (int i = 0; i < c.size(); i++)
    if (!d.empty() && c[i].x == d.back().x && c[i].y == d.back().y)
    {
      cout << c[i].id + 1 << ' ' << d.back().id + 1 << '\n';
      d.pop_back();
    }
    else d.push_back(c[i]);

  vector<Point> e;
  for (int i = 0; i < d.size(); i++)
    if (!e.empty() && d[i].x == e.back().x)
    {
      cout << d[i].id + 1 << ' ' << e.back().id + 1 << '\n';
      e.pop_back();
    }
    else e.push_back(d[i]);

  vector<Point> f;
  sort(e.begin(), e.end(), compYZ);
  for (int i = 0; i < e.size(); i++)
    if (!f.empty() && e[i].y == f.back().y)
    {
      cout << e[i].id + 1 << ' ' << f.back().id + 1 << '\n';
      f.pop_back();
    }
    else f.push_back(e[i]);

  vector<Point> g;
  sort(f.begin(), f.end(), compZX);
  for (int i = 0; i < f.size(); i++)
    if (!g.empty() && f[i].z == g.back().z)
    {
      cout << f[i].id + 1 << ' ' << g.back().id + 1 << '\n';
      g.pop_back();
    }
    else g.push_back(f[i]);

  for (int i = 0; i < g.size(); i += 2)
    cout << g[i].id + 1 << ' ' << g[i + 1].id + 1 << '\n';
}