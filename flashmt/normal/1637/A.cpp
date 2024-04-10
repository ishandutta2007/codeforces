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

    int ans = 1;
    for (int i = 0; i < n - 1; i++)
      if (a[i] > a[i + 1])
        ans = 0;

    cout << (ans ? "NO" : "YES") << endl;
  }
}