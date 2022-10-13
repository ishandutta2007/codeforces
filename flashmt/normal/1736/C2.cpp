#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#else
#define debug(...) 42
#endif
using namespace std;
const int oo = 27081993;

template<typename T>
struct SparseTable
{
  int n;
  vector<vector<T>> mat;

  SparseTable(const vector<T>& a)
  {
    n = int(a.size());
    int maxLog = 32 - __builtin_clz(n);
    mat.resize(maxLog);
    mat[0] = a;
    for (int j = 1; j < maxLog; j++)
    {
      mat[j].resize(n - (1 << j) + 1);
      for (int i = 0; i <= n - (1 << j); i++)
        mat[j][i] = max(mat[j - 1][i], mat[j - 1][i + (1 << (j - 1))]);
    }
  }

  T get(int from, int to)
  {
    assert(0 <= from && from <= to && to <= n - 1);
    int lg = 31 - __builtin_clz(to - from + 1);
    return max(mat[lg][from], mat[lg][to - (1 << lg) + 1]);
  }
};

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    a[i] = max(0, i - a[i] + 1);
  }
  a[n] = oo;
  SparseTable<int> table(a);
  // transform to computing sum of max prefix of a

  vector<int> st = {n}, removed(n);
  vector<long long> f(n + 1); // sum of stairs constructed by suffix from i
  for (int i = n - 1; i >= 0; i--)
  {
    while (a[i] >= a[st.back()])
    {
      removed[st.back()] = 1;
      st.pop_back();
    }
    int j = st.back();
    f[i] = f[j] + 1LL * a[i] * (j - i);
    st.push_back(i);
  }
  reverse(begin(st), end(st));

  int q;
  cin >> q;
  while (q--)
  {
    int i, x;
    cin >> i >> x;
    i--; x--;
    x = max(0, i - x);

    long long ans = f[0];
    if (removed[i])
    {
      int pos = lower_bound(begin(st), end(st), i) - begin(st);
      int j = st[--pos];
      if (a[j] < x)
      {
        int low = i + 1, high = n - 1, r = n;
        while (low <= high)
        {
          int mid = (low + high) / 2;
          if (table.get(i + 1, mid) > x)
          {
            r = mid;
            high = mid - 1;
          }
          else low = mid + 1;
        }
        ans += 1LL * a[j] * (i - j) + 1LL * x * (r - i) + f[r] - f[j];
      }
    }
    else if (x >= a[i])
    {
      int low = 0, high = size(st) - 1, pos = -1;
      while (low <= high)
      {
        int mid = (low + high) / 2;
        if (x < a[st[mid]])
        {
          pos = mid;
          high = mid - 1;
        }
        else low = mid + 1;
      }

      ans += f[st[pos]] + 1LL * x * (st[pos] - i) - f[i];
    }
    else
    {
      int pos = lower_bound(begin(st), end(st), i) - begin(st);
      int j = i;
      // shift to st[pos - 1] if i is covered by st[pos - 1]
      if (pos && a[st[pos - 1]] >= x)
        j = st[pos - 1];

      int oldA = a[i];
      a[i] = x;
      // find nearest r such that a[r] > a[i]
      int low = i + 1, high = n - 1, r = n;
      while (low <= high)
      {
        int mid = (low + high) / 2;
        if (table.get(i + 1, mid) > a[j])
        {
          r = mid;
          high = mid - 1;
        }
        else low = mid + 1;
      }

      ans += f[r] + 1LL * a[j] * (r - j) - f[j];
      a[i] = oldA;
    }

    ans = n * (n + 1LL) / 2 - ans;
    cout << ans << '\n';
  }
}