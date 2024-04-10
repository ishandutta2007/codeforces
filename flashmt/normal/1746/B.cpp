#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#else
#define debug(...) 42
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
    auto b = a;
    sort(begin(b), end(b));
    int ans = 0;
    for (int i = 0; i < n; i++)
      ans += a[i] != b[i];
    assert(ans % 2 == 0);
    cout << ans / 2 << '\n';
  }
}