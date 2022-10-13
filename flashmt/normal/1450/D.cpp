#include <bits/stdc++.h>
using namespace std;

int n, a[300300], good[300300], cnt[300300];

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int test;
  cin >> test;
  while (test--)
  {
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
      cin >> a[i];
      cnt[a[i]]++;
      good[i] = 0;
    }

    int from = 1, to = n;
    for (int i = 1; i <= n; i++)
    {
      if (!cnt[i])
        break;
      good[n - i + 1] = 1;
      if (cnt[i] > 1)
        break;
      if (a[from] == i) from++;
      else if (a[to] == i) to--;
      else break;
    }

    good[1] = 1;
    for (int i = 1; i <= n; i++)
      if (!cnt[i])
        good[1] = 0;

    for (int i = 1; i <= n; i++)
      cout << good[i];
    cout << '\n';

    for (int i = 1; i <= n; i++)
      cnt[i] = 0;
  }
}