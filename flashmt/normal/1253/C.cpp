#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m, a[200200];
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  sort(a, a + n);

  long long ans = 0;
  vector<long long> sum(n, 0);
  for (int i = 0; i < n; i++)
  {
    sum[i] = a[i];
    ans += a[i];
    if (i >= m)
    {
      sum[i] += sum[i - m];
      ans += sum[i - m];
    }
    cout << ans << " \n"[i == n - 1];
  }
}