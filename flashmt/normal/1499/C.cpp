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
    int n;
    cin >> n;
    vector<int> c(n), minC(n);
    vector<long long> sumC(n);
    for (int i = 0; i < n; i++)
    {
      cin >> c[i];
      sumC[i] = c[i];
      if (i < 2) minC[i] = c[i];
      else
      {
        minC[i] = min(minC[i - 2], c[i]);
        sumC[i] += sumC[i - 2];
      }
    }

    long long ans = 1LL << 60;
    for (int length = 2; length <= n; length++)
    {
      int even = (length + 1) / 2, odd = length - even;
      long long cost = sumC[length - 1] + sumC[length - 2];
      cost += 1LL * (n - even) * minC[even * 2 - 2];
      cost += 1LL * (n - odd) * minC[odd * 2 - 1];
      ans = min(ans, cost);
    }

    cout << ans << endl;
  }
}