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
    map<int, int> m;
    m[0] = 0;
    cin >> n;
    for (int i = 1, dif = 0; i <= n; i++)
    {
      int x;
      cin >> x;
      if (x == 1) dif++;
      else dif--;
      m[dif] = i;
    }

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
      cin >> a[i];

    int ans = n * 2 - m[0];
    for (int i = n, dif = 0; i; i--)
    {
      if (a[i] == 1) dif++;
      else dif--;
      if (m.count(-dif))
        ans = min(ans, n + i - 1 - m[-dif]);
    }

    cout << ans << endl;
  }
}