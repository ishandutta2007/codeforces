#include <bits/stdc++.h>
using namespace std;
const int BASE = 998244353;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<long long> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  vector<long long> basis;
  for (auto x : a)
  {
    for (auto y : basis)
      x = min(x, x ^ y);
    if (x)
    {
      int id = 0;
      while (id < size(basis) && basis[id] > x)
        id++;
      basis.insert(begin(basis) + id, x);
    }
  }

  vector<int> ans(m + 1);
  if (size(basis) <= 20)
  {
    for (int mask = 0; mask < 1 << size(basis); mask++)
    {
      long long v = 0;
      for (int i = 0; i < size(basis); i++)
        if (mask >> i & 1)
          v ^= basis[i];
      ans[__builtin_popcountll(v)]++;
    }
  }
  else
  {
    vector<int> isPivot(m);
    for (int i = 0; i < size(basis); i++)
    {
      for (int j = 0; j < i; j++)
        basis[j] = min(basis[j], basis[j] ^ basis[i]);
      for (int j = m - 1; j >= 0; j--)
        if (basis[i] >> j & 1)
        {
          isPivot[j] = 1;
          break;
        }
    }

    vector<int> nonpivot;
    for (int i = 0; i < m; i++)
      if (!isPivot[i])
        nonpivot.push_back(i);

    int p = size(nonpivot);
    vector<vector<int>> f(size(basis) + 1, vector<int>(1 << p));
    f[0][0] = 1;
    for (auto x : basis)
      for (int i = size(basis); i; i--)
        for (int j = 0; j < 1 << p; j++)
        {
          int jj = j;
          for (int k = 0; k < p; k++)
            if (x >> nonpivot[k] & 1)
              jj ^= 1 << k;
          f[i][j] = (f[i][j] + f[i - 1][jj]) % BASE;
        }

    for (int i = 0; i <= size(basis); i++)
      for (int j = 0; j < 1 << p; j++)
        ans[i + __builtin_popcount(j)] = (ans[i + __builtin_popcount(j)] + f[i][j]) % BASE;
  }

  long long p2 = 1;
  for (int i = 0; i < n - size(basis); i++)
    p2 = p2 * 2 % BASE;

  for (auto x : ans)
    cout << x * p2 % BASE << ' ';
}