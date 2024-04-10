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
    int hasOne = 0;
    for (int &x : a)
    {
      cin >> x;
      if (x == 1)
        hasOne = 1;
    }
    sort(begin(a), end(a));

    if (!hasOne)
    {
      cout << "YES\n";
      continue;
    }

    int ans = 1;
    for (int i = 0; i < n - 1; i++)
      if (a[i] + 1 == a[i + 1])
        ans = 0;
    cout << (ans ? "YES" : "NO") << '\n';
  }
}