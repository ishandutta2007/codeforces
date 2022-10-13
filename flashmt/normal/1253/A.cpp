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
    int n, a[100100];
    cin >> n;
    for (int i = 0; i < n; i++)
      cin >> a[i];

    int ans = 1, state = 0, value = 0;
    for (int i = 0; i < n; i++)
    {
      int x;
      cin >> x;
      a[i] = x - a[i];
      if (a[i] < 0)
        ans = 0;
      if (!state)
      {
        if (a[i])
        {
          value = a[i];
          state = 1;
        }
      }
      else if (state == 1)
      {
        if (!a[i]) state = 2;
        else if (a[i] != value) ans = 0;
      }
      else if (a[i]) ans = 0;
    }

    cout << (ans ? "YES" : "NO") << endl;
  }
}