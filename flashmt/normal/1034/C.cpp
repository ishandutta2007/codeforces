#include <bits/stdc++.h>
using namespace std;
const int BASE = 1e9 + 7;

int n, v[1000100], cnt[1000100], ways[1000100];
vector<int> a[1000100];
long long sum[1000100];

void dfs(int x, int par)
{
  sum[x] = v[x];
  for (int y : a[x])
    if (y != par)
    {
      dfs(y, x);
      sum[x] += sum[y];
    }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> v[i];
  for (int i = 1; i < n; i++)
  {
    int x;
    cin >> x;
    x--;
    a[i].push_back(x);
    a[x].push_back(i);
  }

  dfs(0, -1);
  long long sumAll = sum[0];
  for (int i = 0; i < n; i++)
  {
    long long k = sumAll / gcd(sum[i], sumAll);
    if (k <= n)
      cnt[k]++;
  }

  for (int i = n; i; i--)
    for (int j = 2; i * j <= n; j++)
      cnt[i * j] += cnt[i];

  for (int i = n; i; i--)
    if (cnt[i] >= i)
    {
      ways[i] = 1;
      for (int j = 2; i * j <= n; j++)
      {
        ways[i] += ways[i * j];
        if (ways[i] >= BASE)
          ways[i] -= BASE;
      }
    }

  cout << ways[1] << endl;
}