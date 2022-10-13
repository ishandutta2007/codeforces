#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#endif
using namespace std;

template<typename T, class F = function<T(const T&, const T&)>>
struct SparseTable
{
  int n;
  vector<vector<T>> mat;
  F func;

  SparseTable(const vector<T>& a, const F& f) : func(f)
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

  T get(int from, int to)
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
  int n, s0, s1;
  cin >> n >> s0 >> s1;
  vector<int> a = {s0, s1};
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    a.push_back(x);
  }

  SparseTable<int> minTable(a, [](int u, int v) { return min(u, v); });
  SparseTable<int> maxTable(a, [](int u, int v) { return max(u, v); });

  auto isGood = [&](int dist)
  {
    vector<vector<int>> f(n + 5, vector<int>(2));
    f[0][0] = f[1][1] = 1;
    f[1][0] = f[2][1] = -1;
    for (int i = 0; i < n + 2; i++)
    {
      int low = max(2, i + 1), high = n + 1, res = -1;
      while (low <= high)
      {
        int mid = (low + high) / 2;
        if (abs(minTable.get(i + 1, mid) - a[i]) <= dist && abs(maxTable.get(i + 1, mid) - a[i]) <= dist)
        {
          res = mid;
          low = mid + 1;
        }
        else high = mid - 1;
      }

      for (int j : {0, 1})
      {
        if (i)
          f[i][j] += f[i - 1][j];
        if (res >= 0 && f[i][j])
        {
          f[max(2, i + 1)][j ^ 1]++;
          f[res + 1][j ^ 1]--;
        }
      }
    }

    return f[n + 1][0] || f[n + 1][1];
  };

  int low = abs(s1 - s0), high = 1e9, ans = high;
  while (low <= high)
  {
    int mid = (low + high) / 2;
    if (isGood(mid))
    {
      ans = mid;
      high = mid - 1;
    }
    else low = mid + 1;
  }

  cout << ans << endl;
}