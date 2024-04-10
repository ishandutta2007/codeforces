#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#endif
using namespace std;
const int A = 100100;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> x[A], y[A];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
    {
      int c;
      cin >> c;
      x[c].push_back(i);
      y[c].push_back(j);
    }

  auto calc = [&](vector<int> &a)
  {
    sort(begin(a), end(a));
    int n = size(a);
    if (!n)
      return 0LL;
    long long res = 0;
    vector<long long> sum(n + 1);
    for (int i = 0; i < n; i++)
      sum[i + 1] = sum[i] + a[i];
    for (int i = 1; i <= n; i++)
    {
      res += (i - 1LL) * a[i - 1] - sum[i - 1];
      res += sum[n] - sum[i] - 1LL * (n - i) * a[i - 1];
    }
    return res;
  };

  long long ans = 0;
  for (int c = 1; c < A; c++)
    ans += calc(x[c]) + calc(y[c]);
  cout << ans / 2 << endl;
}