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
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    sort(a.begin(), a.end());

    long long ans = 0;
    for (int i = 1; i < n; i++)
    {
      if (i >= 2)
        ans += a[i - 2] - a[i] * (i - 1);
      a[i] += a[i - 1];
    }

    cout << ans << '\n';
  }
}