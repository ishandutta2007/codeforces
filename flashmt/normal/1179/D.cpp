#include <bits/stdc++.h>
using namespace std;
const int N = 500500;
const long long oo = 1LL << 50;

struct Hull {
  long long a[N], b[N];
  double x[N];
  int head, tail;

  Hull(): head(1), tail(0) {}

  long long get(long long xQuery) {
    if (head > tail) return oo;
    int low = head, high = tail;
    long long ans = oo;
    while (low <= high)
    {
      int mid = (low + high) / 2;
      if (x[mid] <= xQuery)
      {
        ans = min(ans, a[mid] * xQuery + b[mid]);
        low = mid + 1;
      }
      else high = mid - 1;
    }
    return ans;
  }

  void add(long long aNew, long long bNew) {
    double xNew = -1e18;
    while (head <= tail) {
      if (aNew == a[tail]) return;
      xNew = 1.0 * (b[tail] - bNew) / (aNew - a[tail]);
      if (head == tail || xNew >= x[tail]) break;
      tail--;
    }
    a[++tail] = aNew;
    b[tail] = bNew;
    x[tail] = xNew;
  }
};

int n, sz[N];
vector <int> a[N];
long long f[N], ans;
Hull hull;

void visit(int x, int par)
{
  sz[x] = 1;
  vector < pair<int, long long> > children;
  for (int y : a[x])
    if (y != par)
    {
      visit(y, x);
      sz[x] += sz[y];
      children.push_back({sz[y], 1LL * sz[y] * (n * 2 - sz[y]) - f[y]});
    }

  if (children.empty())
  {
    f[x] = 1;
    return;
  }

  sort(children.begin(), children.end(), greater < pair<int,long long> >());
  hull.head = 1;
  hull.tail = 0;
  for (auto c : children)
  {
    ans = min(ans, hull.get(c.first * 2) + 1LL * n * n - c.second);
    hull.add(c.first, -c.second);
  }

  f[x] = 1LL * sz[x] * sz[x];
  for (int y : a[x])
    if (y != par)
      f[x] = min(f[x], f[y] + 1LL * (sz[x] - sz[y]) * (sz[x] - sz[y]));
}

int main()
{
  int x, y;
  scanf("%d", &n);
  for (int i = 1; i < n; i++)
  {
    scanf("%d%d", &x, &y);
    a[x].push_back(y);
    a[y].push_back(x);
  }

  if (n == 2)
  {
    cout << 2 << endl;
    return 0;
  }

  int root = 0;
  for (int i = 1; i <= n; i++)
    if (a[i].size() > 1)
    {
      root = i;
      break;
    }

  ans = oo;
  visit(root, 0);
  cout << 1LL * n * n - (ans + n) / 2 << endl;
}