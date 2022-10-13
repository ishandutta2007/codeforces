#include <bits/stdc++.h>
using namespace std;

int n, q, p[200200], tree[200200];
map < pair<int, int>, int > rect;

struct Event
{
  int type, x, y;

  bool operator <(Event u)
  {
    if (x != u.x) return x < u.x;
    if (y != u.y) return y < u.y;
    return type < u.type;
  }
};

struct Query
{
  int x, y, xx, yy;
} queries[200200];

void add(int x)
{
  for (int i = x; i <= n; i += i & -i)
    tree[i]++;
}

int get(int x)
{
  int res = 0;
  for (int i = x; i; i -= i & -i)
    res += tree[i];
  return res;
}

long long c2(int x)
{
  return (x - 1LL) * x / 2;
}

int calcRect(int x, int y)
{
  if (!x || !y)
    return 0;
  if (x == n || y == n)
    return x + y - n;
  return rect[{x, y}];
}

long long calcSubRect(int x, int y, int xx, int yy)
{
  return c2(calcRect(xx, yy) + calcRect(x, y) - calcRect(x, yy) - calcRect(xx, y));
}

long long calcOutside(int x, int y, int xx, int yy)
{
  long long res = c2(x) + c2(y) + c2(n - xx) + c2(n - yy);
  long long duplicated = calcSubRect(0, 0, x, y)
    + calcSubRect(0, yy, x, n)
    + calcSubRect(xx, 0, n, y)
    + calcSubRect(xx, yy, n, n);
  res -= duplicated;
  return res;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  int x, y, xx, yy;
  cin >> n >> q;

  vector <Event> events;
  for (int i = 1; i <= n; i++)
  {
    cin >> p[i];
    events.push_back({0, p[i], i});
  }

  for (int i = 1; i <= q; i++)
  {
    cin >> y >> x >> yy >> xx;
    queries[i] = {--x, --y, xx, yy};
    if (xx < n && yy < n) events.push_back({1, xx, yy});
    if (x && yy < n) events.push_back({1, x, yy});
    if (xx < n && y) events.push_back({1, xx, y});
    if (x && y) events.push_back({1, x, y});
  }

  sort(events.begin(), events.end());
  for (auto e : events)
    if (e.type) rect[{e.x, e.y}] = get(e.y);
    else add(e.y);

  for (int i = 1; i <= q; i++)
    cout << c2(n) - calcOutside(queries[i].x, queries[i].y, queries[i].xx, queries[i].yy) << '\n';
}