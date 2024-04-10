#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, a[200200], s;
  cin >> n >> s;
  for (int i = 0; i < n; i++)
    cin >> a[i];

  sort(a, a + n);
  long long ans = abs(a[n / 2] - s);
  for (int i = 0; i < n / 2; i++)
    ans += max(0, a[i] - s);
  for (int i = n / 2 + 1; i < n; i++)
    ans += max(0, s - a[i]);
  cout << ans << endl;
}