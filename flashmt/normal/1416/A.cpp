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
    int n;
    cin >> n;
    vector<int> last(n, -1), minLen(n);
    for (int i = 0; i < n; i++)
    {
      int x;
      cin >> x;
      --x;
      minLen[x] = max(minLen[x], i - last[x]);
      last[x] = i;
    }
    for (int x = 0; x < n; x++)
      if (last[x] >= 0)
        minLen[x] = max(minLen[x], n - last[x]);

    vector<int> ans(n + 1, -2);
    for (int x = 0; x < n; x++)
      if (minLen[x])
        for (int i = minLen[x]; i <= n && ans[i] < 0; i++)
          ans[i] = x;

    for (int i = 1; i <= n; i++)
      cout << ans[i] + 1 << " \n"[i == n];
  }
}