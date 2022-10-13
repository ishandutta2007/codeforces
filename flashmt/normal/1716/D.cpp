#include <bits/stdc++.h>
using namespace std;
const int BASE = 998244353;

int main()
{
  int n, k;
  cin >> n >> k;
  vector<int> f(n + 1), ans(n + 1);
  f[0] = 1;
  for (int i = k, curSum = 0; curSum + i <= n; i++)
  {
    vector<int> sum(i);
    for (int j = 0; j <= n; j++)
    {
      int oldF = f[j];

      f[j] = sum[j % i];
      ans[j] += f[j];
      if (ans[j] >= BASE)
        ans[j] -= BASE;

      sum[j % i] += oldF;
      if (sum[j % i] >= BASE)
        sum[j % i] -= BASE;
    }
    curSum += i;
  }
  for (int i = 1; i <= n; i++)
    cout << ans[i] << ' ';
}