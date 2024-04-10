#include <bits/stdc++.h>
using namespace std;
const int BASE = 998244353;

struct FenwickTree
{
  int n;
  vector<int> a;

  FenwickTree(int n): n(n)
  {
    a = vector<int>(n + 1, 0);
  }

  void add(int x, int v)
  {
    for (int i = x + 1; i <= n; i += i & -i)
      a[i] += v;
  }

  int get(int x)
  {
    int res = 0;
    for (int i = x + 1; i; i -= i & -i)
      res += a[i];
    return res;
  }
};

int n, a[2020][2020], tree[2020];
long long fact[2020], f[2020][2020];

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
    {
      cin >> a[i][j];
      a[i][j]--;
    }

  f[0][0] = fact[0] = 1;
  for (int i = 1; i <= n; i++)
  {
    f[i][0] = fact[i] = fact[i - 1] * i % BASE;
    for (int j = 1; j <= i; j++)
      f[i][j] = (f[i][j - 1] - f[i - 1][j - 1] + BASE) % BASE;
  }

  long long ans = 0;
  FenwickTree prevRow(n), curRow(n);
  for (int j = 0; j < n; j++)
  {
    int rank = a[0][j] - curRow.get(a[0][j]);
    ans = (ans + fact[n - 1 - j] * rank) % BASE;
    curRow.add(a[0][j], 1);
  }

  for (int i = 1; i < n; i++)
  {
    ans = ans * f[n][n] % BASE;
    swap(curRow, prevRow);
    curRow.a.assign(n + 1, 0);

    vector<int> seen(n, 0);
    for (int j = 0; j < n; j++)
    {
      int rank = a[i][j] - curRow.get(a[i][j]);
      int unseen = prevRow.get(n - 1);
      int unseenSmaller = prevRow.get(a[i][j] - 1);
      int seenSmaller = rank - unseenSmaller;

      // ensure that we don't put a[i - 1][j] here
      if (!seen[a[i - 1][j]])
      {
        unseen--;
        if (a[i - 1][j] < a[i][j])
          unseenSmaller--;
      }

      // put some seen here
      ans = (ans + f[n - 1 - j][unseen] * seenSmaller) % BASE;
      // put some unseen here
      if (unseen)
        ans = (ans + f[n - 1 - j][unseen - 1] * unseenSmaller) % BASE;

      // mark both a[i - 1][j] and a[i][j] as seen
      if (!seen[a[i - 1][j]])
      {
        seen[a[i - 1][j]] = 1;
        prevRow.add(a[i - 1][j], -1);
      }
      if (!seen[a[i][j]])
      {
        seen[a[i][j]] = 1;
        prevRow.add(a[i][j], -1);
      }

      curRow.add(a[i][j], 1);
    }
  }

  cout << ans % BASE << endl;
}