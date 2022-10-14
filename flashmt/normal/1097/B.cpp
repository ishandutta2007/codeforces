#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, a[15];
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int mask = 0; mask < 1 << n; mask++)
  {
    int s = 0;
    for (int i = 0; i < n; i++)
      if (mask >> i & 1) s = (s + a[i]) % 360;
      else s = (s - a[i] + 360) % 360;
    if (!s)
    {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
}