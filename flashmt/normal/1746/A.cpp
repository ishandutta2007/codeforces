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
    vector<int> a(n);
    int ans = 0;
    for (int &x : a)
    {
      cin >> x;
      ans |= x;
    }
    cout << (ans ? "YES" : "NO") << endl;
  }
}