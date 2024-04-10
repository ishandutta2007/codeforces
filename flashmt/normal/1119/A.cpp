#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  int n, a[300300], ans = 0;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    if (a[i] != a[0])
      ans = i;
  }
  for (int i = 0; i < n; i++)
    if (a[i] != a[n - 1] && n - 1 - i > ans)
      ans = n - 1 - i;
  cout << ans << endl;
}