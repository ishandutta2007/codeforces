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
    int n, x[100100];
    cin >> n;
    for (int i = 0; i < n; i++)
      cin >> x[i];

    int ans = 1, last = x[0];
    for (int i = 1; i < n; i++)
      if (x[i] >= last)
      {
        ans++;
        if (x[i] == last)
          x[i]++;
        last = x[i];
      }

    cout << ans << '\n';
  }
}