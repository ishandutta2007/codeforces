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
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
      int zero = 0;
      for (int j = i; j < n; j++)
      {
        zero += !a[j];
        ans += j - i + 1 + zero;
      }
    }

    cout << ans << endl;
  }
}