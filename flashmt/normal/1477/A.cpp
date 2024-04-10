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
    long long k;
    cin >> n >> k;
    vector<long long> a(n);
    string ans = "NO";
    for (int i = 0; i < n; i++)
      cin >> a[i];
    sort(a.begin(), a.end());

    long long g = 0;
    for (int i = 1; i < n; i++)
      g = __gcd(g, a[i] - a[i - 1]);

    for (int i = 0; i < n; i++)
      if (llabs(k - a[i]) % g == 0)
        ans = "YES";
    cout << ans << '\n';
  }
}