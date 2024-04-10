#include <bits/stdc++.h>
using namespace std;

long long getCost(int x, int y)
{
  int q = x / y, r = x % y;
  return 1LL * q * q * (y - r) + (q + 1LL) * (q + 1) * r;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, k, a[100100], sz[100100];
  long long cost[100100], gain[100100], ans = 0;
  cin >> n >> k;
  priority_queue<pair<long long, int>> q;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    sz[i] = 1;
    cost[i] = 1LL * a[i] * a[i];
    ans += cost[i];
    if (a[i] > 1)
    {
      gain[i] = cost[i] - getCost(a[i], 2);
      q.push({gain[i], i});
    }
  }

  k -= n;
  while (k--)
  {
    assert(!q.empty());
    int i = q.top().second;
    q.pop();
    ans -= gain[i];
    cost[i] -= gain[i];
    sz[i]++;
    if (sz[i] < a[i])
    {
      gain[i] = cost[i] - getCost(a[i], sz[i] + 1);
      q.push({gain[i], i});
    }
  }

  cout << ans << endl;
}