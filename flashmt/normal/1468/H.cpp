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
    int n, k, m;
    cin >> n >> k >> m;
    vector<int> picked(n + 1, 1);
    picked[0] = 0;
    for (int i = 0; i < m; i++)
    {
      int x;
      cin >> x;
      picked[x] = 0;
    }

    if ((n - m) % (k - 1)) cout << "NO\n";
    else
    {
      string ans = "NO";
      for (int i = 1; i <= n; i++)
      {
        picked[i] += picked[i - 1];
        if (picked[i] == picked[i - 1] && picked[i] >= k / 2 && n - m - picked[i] >= k / 2)
          ans = "YES";
      }
      cout << ans << '\n';
    }
  }
}