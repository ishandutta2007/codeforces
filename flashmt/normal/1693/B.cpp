#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#endif
using namespace std;
const int N = 200200;

int par[N], f[N];
vector<int> a[N];
long long l[N], r[N];

void dfs(int x)
{
  f[x] = 0;
  long long sumR = 0;
  for (int y : a[x])
  {
    dfs(y);
    f[x] += f[y];
    sumR += r[y];
  }

  if (sumR < l[x]) f[x]++;
  else r[x] = min(r[x], sumR);
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--)
  {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
      a[i].clear();

    for (int i = 1; i < n; i++)
    {
      cin >> par[i];
      a[--par[i]].push_back(i);
    }

    for (int i = 0; i < n; i++)
      cin >> l[i] >> r[i];

    dfs(0);
    cout << f[0] << '\n';
  }
}