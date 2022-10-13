#include <bits/stdc++.h>
using namespace std;

int n, a[100100], sum[100100], cntBig[100100];
string ops;
vector<char> ans;
int p[22][22], f[22][22], tr[22][22], flag[22];

void setAns(int l, int r, char c)
{
  for (int i = l; i < r; i++)
    ans[i] = c;
}

void trace(int l, int r)
{
  if (l == r || tr[l][r] < 0)
    return;
  int x = tr[l][r];
  flag[x] = 1;
  trace(l, x);
  trace(x + 1, r);
}

void dp(vector<int> big, vector<int> cost)
{
  int m = big.size();
  for (int i = 0; i < m; i++)
    f[i][i] = p[i][i] = big[i];
  for (int len = 2; len <= m; len++)
    for (int i = 0; i + len <= m; i++)
    {
      int j = i + len - 1;
      p[i][j] = p[i][j - 1] * big[j];
      f[i][j] = p[i][j];
      tr[i][j] = -1;
      for (int k = i; k < j; k++)
        if (f[i][k] + f[k + 1][j] + cost[k] > f[i][j])
        {
          f[i][j] = f[i][k] + f[k + 1][j] + cost[k];
          tr[i][j] = k;
        }
    }

  for (int i = 0; i < m; i++)
    flag[i] = 0;
  trace(0, m - 1);
}

void solvePlusMultiply(int l, int r)
{
  while (l <= r && a[l] == 1)
    l++;
  while (r >= l && a[r] == 1)
    r--;
  if (l >= r)
    return;

  setAns(l, r, '*');
  // check if the product is big enough to ignore plus operator
  int product = 1;
  for (int i = l; i <= r; i++)
  {
    product *= a[i];
    if (product > n * 2)
      return;
  }

  assert(cntBig[r] - cntBig[l - 1] <= 17);

  // compress original [l, r] into new form
  vector<pair<int, int>> ones;
  vector<int> big, cost;
  for (int i = l; i <= r;)
  {
    int j = i, product = 1;
    while (j <= r && (a[i] > 1) == (a[j] > 1))
      product *= a[j++];

    if (a[i] > 1) big.push_back(product);
    else
    {
      ones.push_back({i, j - 1});
      cost.push_back(j - i);
    }
    i = j;
  }

  dp(big, cost);
  for (int i = 0; i < cost.size(); i++)
    if (flag[i])
      setAns(ones[i].first - 1, ones[i].second + 1, '+');
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    cin >> a[i];
    sum[i] = sum[i - 1] + a[i];
    cntBig[i] = cntBig[i - 1] + (a[i] > 1);
  }
  cin >> ops;
  sort(ops.begin(), ops.end());

  if (ops.size() == 1 || ops == "+-") ans = vector<char>(n, ops[0]);
  else if (ops == "*-")
  {
    ans = vector<char>(n, '*');
    for (int i = 1; i <= n; i++)
      if (!a[i])
      {
        ans[i - 1] = '-';
        break;
      }
  }
  else
  {
    ans = vector<char>(n, '+');
    for (int i = 1; i <= n;)
      if (!a[i]) i++;
      else
      {
        int j = i + 1;
        while (j <= n && a[j])
          j++;
        solvePlusMultiply(i, j - 1);
        i = j;
      }
  }

  for (int i = 1; i <= n; i++)
  {
    cout << a[i];
    if (i < n)
      cout << ans[i];
  }
}