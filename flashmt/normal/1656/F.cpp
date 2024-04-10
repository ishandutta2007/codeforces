#include <bits/stdc++.h>
using namespace std;
const long long oo = 1LL << 60;

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
    vector<int> a(n);
    for (int &x : a)
      cin >> x;

    sort(begin(a), end(a));
    vector<long long> sum(n + 1);
    for (int i = 0; i < n; i++)
      sum[i + 1] = sum[i] + a[i];

    long long sumMin = sum[n] + a[0] * (n - 2LL);
    long long sumMax = sum[n] + a[n - 1] * (n - 2LL);
    if (sumMin > 0 || sumMax < 0) cout << "INF\n";
    else
    {
      long long ans = -oo;
      for (int i = 0; i < n; i++)
      {
        long long t = -a[i];
        long long cost = (sum[i] + t * i) * (a[n - 1] + t);
        cost += (sum[n] - sum[i] + t * (n - i)) * (a[0] + t);
        cost -= (a[n - 1] + t) * (a[0] + t);
        cost -= (n - 1) * t * t;
        ans = max(ans, cost);
      }
      cout << ans << endl;
    }
  }
}