#include <bits/stdc++.h>
using namespace std;
const int oo = 1 << 30;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int test, n, p, k, x, y;
  string a;
  cin >> test;
  while (test--)
  {
    cin >> n >> p >> k >> a >> x >> y;
    vector<int> cost(n, 0);
    for (int i = n - 1; i >= 0; i--)
    {
      if (i + k < n)
        cost[i] = cost[i + k];
      if (a[i] == '0')
        cost[i] += x;
    }

    int ans = oo;
    for (int i = 0; i + p <= n; i++)
      ans = min(ans, cost[i + p - 1] + i * y);
    cout << ans << endl;
  }
}