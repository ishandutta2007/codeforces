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
    int n, k, a[200200];
    cin >> n >> k;
    for (int i = 0; i < n * k; i++)
      cin >> a[i];
    long long ans = 0;
    for (int i = 1; i <= k; i++)
      ans += a[n * k - i * (n / 2 + 1)];
    cout << ans << endl;
  }
}