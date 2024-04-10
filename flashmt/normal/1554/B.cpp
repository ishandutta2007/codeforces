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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];

    long long ans = - 1LL << 60;
    for (int i = max(0, n - k - 128); i < n; i++)
      for (int j = i + 1; j < n; j++)
        ans = max(ans, (i + 1LL) * (j + 1LL) - k * (a[i] | a[j]));

    cout << ans << endl;
  }
}