#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  string a, b;
  cin >> n >> a >> b;

  int ans = 0;
  for (int i = 0; i + 1 < n; i++)
    if (a[i] != b[i] && a[i + 1] != b[i + 1] && a[i] != a[i + 1])
    {
      ans++;
      swap(a[i], a[i + 1]);
    }
  for (int i = 0; i < n; i++)
    ans += a[i] != b[i];

  cout << ans << endl;
}