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
    vector<long long> a(n);
    for (auto &x : a)
      cin >> x;

    int ans = 1;
    for (int i = 0; i < n - 1; i++)
      if (a[i] < 0)
      {
        ans = 0;
        break;
      }
      else if (!a[i]) break;
      else
      {
        a[i + 1] += a[i];
        a[i] = 0;
      }

    for (auto x : a)
      if (x)
        ans = 0;

    cout << (ans ? "Yes" : "No") << '\n';
  }
}