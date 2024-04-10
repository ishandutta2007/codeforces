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
    string a, b;
    cin >> n >> a >> b;
    int ans = 0, pending = -1;
    for (int i = 0; i < n; i++)
      if (a[i] == '0' && b[i] == '0')
      {
        if (pending < 0) pending = 0;
        else if (!pending) ans++;
        else
        {
          ans += 2;
          pending = -1;
        }
      }
      else if (a[i] == '1' && b[i] == '1')
      {
        if (pending < 0) pending = 1;
        else if (!pending)
        {
          ans += 2;
          pending = -1;
        }
      }
      else
      {
        if (!pending)
          ans++;
        pending = -1;
        ans += 2;
      }

    if (!pending)
      ans++;

    cout << ans << endl;
  }
}