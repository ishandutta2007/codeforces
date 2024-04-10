#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#endif
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;

  vector<int> a(n);
  cout << 1 << ' ';
  for (int i = 0, zero = n - 1; i < n; i++)
  {
    int x;
    cin >> x;
    a[--x] = 1;
    while (zero >= 0 && a[zero])
      zero--;

    if (zero < 0) cout << 1 << ' ';
    else cout << i + 1 - (n - 1 - zero) + 1 << ' ';
  }
}