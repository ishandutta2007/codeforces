#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--)
  {
    int n, a[200200];
    cin >> n;
    for (int i = 0; i < n; i++)
      cin >> a[i];
    int found = 0;
    for (int i = 1; i < n; i++)
      if (abs(a[i - 1] - a[i]) >= 2)
      {
        cout << "YES\n" << i << ' ' << i + 1 << '\n';
        found = 1;
        break;
      }
    if (!found)
      cout << "NO\n";
  }
}