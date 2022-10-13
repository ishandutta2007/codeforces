#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int test;
  cin >> test;
  while (test--)
  {
    int n, p, k, a[200200];
    cin >> n >> p >> k;
    for (int i = 0; i < n; i++)
      cin >> a[i];
    sort(a, a + n);

    vector<int> cost(n + 1, 0);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
      cost[i] = (i < k ? cost[i - 1] : cost[i - k]) + a[i - 1];
      if (cost[i] <= p)
        ans = i;
    }

    cout << ans << '\n';
  }
}