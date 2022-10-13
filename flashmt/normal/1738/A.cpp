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
    vector<vector<int>> b(2);
    long long sum = 0;
    int minB = 1 << 30;
    for (int i = 0; i < n; i++)
    {
      int x;
      cin >> x;
      minB = min(minB, x);
      sum += x;
      b[a[i]].push_back(x);
    }

    for (int i : {0, 1})
      sort(rbegin(b[i]), rend(b[i]));

    if (size(b[0]) == size(b[1])) cout << sum * 2 - minB << '\n';
    else
    {
      int k = min(size(b[0]), size(b[1]));
      long long ans = sum;
      for (int i = 0; i < k; i++)
        ans += b[0][i] + b[1][i];
      cout << ans << '\n';
    }
  }
}