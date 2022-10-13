#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#endif
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--)
  {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a)
      cin >> x;

    int l = 0;
    while (l < n - 1 && a[l] != a[l + 1])
      l++;

    int r = n - 1;
    while (r && a[r] != a[r - 1])
      r--;

    if (l + 1 >= r) cout << "0\n";
    else cout << max(r - l - 2, 1) << '\n';
  }
}