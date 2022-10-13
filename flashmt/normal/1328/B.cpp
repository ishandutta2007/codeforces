#include <bits/stdc++.h>
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
    for (int i = 1; i < n; i++)
      if (k > i) k -= i;
      else
      {
        string ans(n, 'a');
        ans[n - 1 - i] = ans[n - k] = 'b';
        cout << ans << '\n';
        break;
      }
  }
}