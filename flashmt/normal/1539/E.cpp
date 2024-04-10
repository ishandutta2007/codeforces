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
  int n, m;
  cin >> n >> m;
  vector<int> cards(n + 1);
  vector<vector<int>> a(4, vector<int>(n + 1));
  for (int i = 1; i <= n; i++)
  {
    cin >> cards[i];
    for (int j = 0; j < 4; j++)
      cin >> a[j][i];
  }

  vector<SparseTable<int>> tables;
  for (int i = 0; i < 4; i++)
    if (i % 2) tables.push_back(SparseTable<int>(a[i], [&](int u, int v) { return min(u, v); }));
    else tables.push_back(SparseTable<int>(a[i], [&](int u, int v) { return max(u, v); }));

  vector<vector<int>> cntGood(2, vector<int>(n + 1));
  for (int i = 1; i <= n; i++)
    for (int j : {0, 1})
      cntGood[j][i] = cntGood[j][i - 1] + (a[j * 2][i] <= cards[i] && cards[i] <= a[j * 2 + 1][i]);

  vector<vector<int>> f(2, vector<int>(n + 1, -1));
  f[0][0] = f[1][0] = 0;
  vector<int> bound = {1, 1};
  for (int i = 0; i < n; i++)
    for (int j : {0, 1})
      if (f[j][i] >= 0)
      {
        int low = i + 1, high = n, res = i;
        while (low <= high)
        {
          int mid = (low + high) / 2;
          int maxL = tables[j * 2].get(i + 1, mid);
          int minR = tables[j * 2 + 1].get(i + 1, mid);
          int cntGoodOther = cntGood[j ^ 1][mid] - cntGood[j ^ 1][i];
          if (maxL <= cards[i] && cards[i] <= minR && cntGoodOther == mid - i)
          {
            res = mid;
            low = mid + 1;
          }
          else high = mid - 1;
        }

        bound[j ^ 1] = max(bound[j ^ 1], i + 1);
        while (bound[j ^ 1] <= res)
          f[j ^ 1][bound[j ^ 1]++] = i;
      }

  if (f[0][n] < 0 && f[1][n] < 0) cout << "No" << endl;
  else
  {
    cout << "Yes" << endl;
    int i = n, j = f[0][n] >= 0 ? 0 : 1;
    vector<int> ans;
    while (i)
    {
      for (int k = 0; k < i - f[j][i]; k++)
        ans.push_back(j);
      i = f[j][i];
      j ^= 1;
    }
    reverse(begin(ans), end(ans));
    for (int x : ans)
      cout << x << ' ';
  }
}