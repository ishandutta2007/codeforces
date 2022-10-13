#include <bits/stdc++.h>
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
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  vector<long long> s(n);
  for (int i = 0; i < n; i++)
  {
    int b;
    cin >> b;
    a[i] = b - a[i];
    s[i] = a[i];
    if (i)
      s[i] += s[i - 1];
  }

  SparseTable<long long> minTable(s, [&](long long i, long long j) { return min(i, j); });
  SparseTable<long long> maxTable(s, [&](long long i, long long j) { return max(i, j); });
  while (q--)
  {
    int l, r;
    cin >> l >> r;
    l--;
    r--;
    long long sl = l ? s[l - 1] : 0;
    long long minVal = minTable.get(l, r - 1);
    if (sl != s[r] || minVal < s[r]) cout << "-1\n";
    else
    {
      long long maxVal = maxTable.get(l, r - 1);
      cout << maxVal - s[r] << '\n';
    }
  }
}