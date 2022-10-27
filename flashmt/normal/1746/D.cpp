#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#else
#define debug(...) 42
#endif
using namespace std;
const int N = 2e5 + 5;

vector<int> a[N];
int p[N], s[N];
map<int, long long> f[N];

long long dfs(int x, int k)
{
  if (!k)
    return 0;
  if (f[x].count(k))
    return f[x][k];

  long long res = 1LL * s[x] * k;
  int sz = size(a[x]);
  vector<long long> diff;
  for (int y : a[x])
  {
    long long v0 = dfs(y, k / sz);
    res += v0;
    if (k % sz)
    {
      long long v1 = dfs(y, k / sz + 1);
      diff.push_back(v1 - v0);
    }
  }

  if (sz)
  {
    sort(rbegin(diff), rend(diff));
    for (int i = 0; i < k % sz; i++)
      res += diff[i];
  }

  return f[x][k] = res;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--)
  {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
      a[i].clear();
      f[i].clear();
    }
    for (int i = 1; i < n; i++)
    {
      cin >> p[i];
      a[--p[i]].push_back(i);
    }
    for (int i = 0; i < n; i++)
      cin >> s[i];

    cout << dfs(0, k) << '\n';
  }
}