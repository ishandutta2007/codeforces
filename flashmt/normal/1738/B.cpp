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
    int n, k;
    cin >> n >> k;
    vector<int> s(k);
    for (int &x : s)
      cin >> x;
    vector<int> a;
    for (int i = 0; i < k - 1; i++)
      a.push_back(s[i + 1] - s[i]);

    int ans = 1;
    for (int i = 0; i + 1 < size(a); i++)
      if (a[i] > a[i + 1])
        ans = 0;

    int maxA = 1 << 30;
    if (!empty(a))
      maxA = a[0];

    n -= k - 1;
    if (1LL * n * maxA < s[0])
      ans = 0;
    cout << (ans ? "Yes" : "No") << '\n';
  }
}