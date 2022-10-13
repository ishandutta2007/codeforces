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
    for (int i = 0; i < n; i++)
      cin >> a[i];
    a = vector<int>(begin(a) + 1, end(a) - 1);

    if (n == 3 && a[0] % 2) cout << -1 << '\n';
    else if (all_of(begin(a), end(a), [](int x) { return x == 1; })) cout << -1 << '\n';
    else cout << accumulate(begin(a), end(a), 0LL, [](auto x, auto y) { return x + (y + 1) / 2; }) << '\n';
  }
}