#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  int n, k, a[2020], ans = 0;
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n, greater <int>());
  for (int i = 0; i < n; i += k) ans += (a[i] - 1) * 2;
  cout << ans << endl;
}