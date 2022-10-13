#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, k, a[300300];
  cin >> n >> k;
  for (int i = 0; i < n; i++)
    cin >> a[i];

  for (int i = 0; i < n - 1; i++)
    a[i] = a[i + 1] - a[i];

  sort(a, a + n - 1);
  long long ans = 0;
  for (int i = 0; i < n - k; i++)
    ans += a[i];

  cout << ans << endl;
}