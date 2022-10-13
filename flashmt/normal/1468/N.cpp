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
    int c[3], a[5];
    for (int i = 0; i < 3; i++)
      cin >> c[i];
    for (int i = 0; i < 5; i++)
      cin >> a[i];

    if (c[0] > a[0])
      a[3] -= min(c[0] - a[0], a[3]);
    if (c[1] > a[1])
      a[4] -= min(c[1] - a[1], a[4]);
    a[2] += a[3] + a[4];

    if (c[0] < a[0] || c[1] < a[1] || c[2] < a[2]) cout << "No\n";
    else cout << "Yes\n";
  }
}