#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#ifdef LOCAL
#include "Debug.h"
#else
#define debug(...) 42
#endif
using namespace __gnu_pbds;
using namespace std;
const int X = 1e6;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> OrderedSet;

template<class F = function<int(int, int)>>
struct SparseTable
{
  int n;
  vector<vector<int>> mat;
  F func;

  SparseTable(const vector<int>& a, const F& f) : func(f)
  {
    n = int(a.size());
    int maxLog = 32 - __builtin_clz(n);
    mat.resize(maxLog);
    mat[0] = a;
    for (int j = 1; j < maxLog; j++)
    {
      mat[j].resize(n - (1 << j) + 1);
      for (int i = 0; i <= n - (1 << j); i++)
        mat[j][i] = func(mat[j - 1][i], mat[j - 1][i + (1 << (j - 1))]);
    }
  }

  int get(int from, int to)
  {
    assert(0 <= from && from <= to && to <= n - 1);
    int lg = 31 - __builtin_clz(to - from + 1);
    return func(mat[lg][from], mat[lg][to - (1 << lg) + 1]);
  }
};

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<tuple<int, int, int>> hor;
  for (int i = 0; i < n; i++)
  {
    int y, x, xx;
    cin >> y >> x >> xx;
    hor.push_back({y, x, xx});
  }

  vector<int> minY(X + 1, X), maxY(X + 1);
  minY[0] = minY[X] = 0;
  maxY[0] = maxY[X] = X;
  map<int, int> allX;
  allX[0] = allX[X] = 3;
  for (int i = 0; i < m; i++)
  {
    int x, y, yy, t = 0;
    cin >> x >> y >> yy;
    if (!y)
    {
      maxY[x] = yy;
      t |= 1;
    }
    if (yy == X)
    {
      minY[x] = y;
      t |= 2;
    }
    allX[x] = t;
  }

  // find the first/last horizontal segment that intersects with each vertical segment
  SparseTable tableMinY(minY, [](int u, int v) { return min(u, v); });
  SparseTable tableMaxY(maxY, [](int u, int v) { return max(u, v); });
  vector<pair<int, int>> horEvents[X + 1];
  for (auto [y, x, xx] : hor)
  {
    if (!x)
    {
      int low = 1, high = xx, res = 0;
      while (low <= high)
      {
        int mid = (low + high) / 2;
        if (tableMaxY.get(mid, xx) >= y || tableMinY.get(mid, xx) <= y)
        {
          res = mid;
          low = mid + 1;
        }
        else high = mid - 1;
      }
      xx = res;
    }
    else
    {
      int low = x, high = X - 1, res = X;
      while (low <= high)
      {
        int mid = (low + high) / 2;
        if (tableMaxY.get(x, mid) >= y || tableMinY.get(x, mid) <= y)
        {
          res = mid;
          high = mid - 1;
        }
        else low = mid + 1;
      }
      x = res;
    }

    if (x < xx)
    {
      horEvents[x].push_back({y, 1});
      horEvents[xx].push_back({y, 0});
    }
  }

  long long ans = 0;
  OrderedSet horSegs;
  for (auto [x, t] : allX)
  {
    if (x)
    {
      if (t == 3) ans += size(horSegs) + 1;
      else if (t == 1) ans += horSegs.order_of_key(maxY[x] + 1);
      else ans += size(horSegs) - horSegs.order_of_key(minY[x]);
    }

    for (auto [y, isOpen] : horEvents[x])
      if (isOpen) horSegs.insert(y);
      else horSegs.erase(y);
  }

  cout << ans << endl;
}