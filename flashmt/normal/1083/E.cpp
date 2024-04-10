#include <bits/stdc++.h>
using namespace std;

struct Rect
{
  int x, y;
  long long v;

  bool operator <(Rect u)
  {
    return x < u.x;
  }
};

long long a[1000100], b[1000100];
double x[1000100];
int head = 1, tail = 0;

void add(long long aNew, long long bNew)
{
  double xNew = 1e18;
  while (head <= tail)
  {
    xNew = 1. * (b[tail] - bNew) / (aNew - a[tail]);
    if (head == tail || xNew <= x[tail])
      break;
    tail--;
  }
  a[++tail] = aNew;
  b[tail] = bNew;
  x[tail] = xNew;
}

long long get(long long curX)
{
  while (head < tail && curX <= x[head + 1])
    head++;
  return a[head] * curX + b[head];
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  vector<Rect> a;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    int x, y;
    long long v;
    cin >> x >> y >> v;
    a.push_back({x, y, v});
  }

  sort(a.begin(), a.end());
  long long ans = 0;
  for (int i = 0; i < n; i++)
  {
    long long f = 0;
    if (i)
      f = max(0LL, get(a[i].y));
    f += 1LL * a[i].x * a[i].y - a[i].v;
    ans = max(ans, f);
    add(-a[i].x, f);
  }
  cout << ans << endl;
}