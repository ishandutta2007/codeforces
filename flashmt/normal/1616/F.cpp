#include <bits/stdc++.h>
using namespace std;
const int MOD = 3;

int cache[3][3][3]; // i - j * k

int inv(int x)
{
  return x;
}

int gauss(vector<vector<int>> a, vector<int> b, vector<int> &x)
{
  int n = size(a), m = size(x), rank = 0;
  vector<int> col(m);
  iota(begin(col), end(col), 0);
  for (int i = 0; i < n; i++)
  {
    int pr = -1, pc = -1, pv = 0;
    for (int j = i; j < n; j++)
      for (int k = i; k < m; k++)
        if (a[j][k] != 0)
        {
          pr = j;
          pc = k;
          pv = a[j][k];
        }

    if (pv == 0)
    {
      for (int j = i; j < n; j++)
        if (b[j] != 0)
          return -1;
      break;
    }

    swap(a[i], a[pr]);
    swap(b[i], b[pr]);
    swap(col[i], col[pc]);
    for (int j = 0; j < n; j++)
      swap(a[j][i], a[j][pc]);
    pv = inv(a[i][i]);
    for (int j = i + 1; j < n; j++)
    {
      int coef = a[j][i] * pv % MOD;
      b[j] = cache[b[j]][coef][b[i]]; // b[j] -= coef * b[i]
      for (int k = i + 1; k < m; k++)
        a[j][k] = cache[a[j][k]][coef][a[i][k]]; // a[j][k] -= coef * a[i][k]
    }
    rank++;
  }

  x.assign(m, 0);
  for (int i = rank - 1; i >= 0; i--)
  {
    b[i] = b[i] * inv(a[i][i]) % MOD;
    x[col[i]] = b[i];
    for (int j = 0; j < i; j++)
      b[j] = cache[b[j]][a[j][i]][b[i]]; // b[j] -= a[j][i] * b[i]
  }
  return rank;
}

int main()
{
  for (int i = 0; i < MOD; i++)
    for (int j = 0; j < MOD; j++)
      for (int k = 0; k < MOD; k++)
        cache[i][j][k] = (i - j * k % MOD + MOD) % MOD;

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--)
  {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edgeId(n, vector<int>(n, -1));
    vector<vector<int>> a;
    vector<int> b;
    for (int i = 0; i < m; i++)
    {
      int x, y, c;
      cin >> x >> y >> c;
      x--; y--;
      if (c > 0)
      {
        vector<int> coef(m);
        coef[i] = 1;
        a.push_back(coef);
        b.push_back(--c);
      }
      edgeId[x][y] = edgeId[y][x] = i;
    }

    for (int i = 0; i < n; i++)
      for (int j = i + 1; j < n; j++)
        for (int k = j + 1; k < n; k++)
          if (edgeId[i][j] >= 0 && edgeId[j][k] >= 0 && edgeId[k][i] >= 0)
          {
            vector<int> coef(m);
            coef[edgeId[i][j]] = coef[edgeId[j][k]] = coef[edgeId[k][i]] = 1;
            a.push_back(coef);
            b.push_back(0);
          }

    vector<int> var(m);
    if (gauss(a, b, var) < 0)
    {
      cout << -1 << '\n';
      continue;
    }

    for (int x : var)
      cout << max(x, 0) + 1 << ' ';
    cout << '\n';
  }
}