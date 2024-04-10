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
    int n, a[200200];
    cin >> n;
    for (int i = 0; i < n; i++)
      cin >> a[i];
    long long sumDiff = 0;
    for (int i = n - 2; i >= 0; i--)
      sumDiff += abs(a[i] - a[i + 1]);

    long long ans = 1LL << 60;
    for (int i = 0; i < n; i++)
      if (!i) ans = min(ans, sumDiff - abs(a[i] - a[i + 1]));
      else if (i == n - 1) ans = min(ans, sumDiff - abs(a[i] - a[i - 1]));
      else ans = min(ans, sumDiff - abs(a[i] - a[i - 1]) - abs(a[i] - a[i + 1]) + abs(a[i - 1] - a[i + 1]));

    cout << ans << endl;
  }
}