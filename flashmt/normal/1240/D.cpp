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
    int n, a[300300], l[300300], f[300300];
    map<int, int> *lMap[300300];
    cin >> n;
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
      f[i] = 0;
      l[i] = -1;
      lMap[i] = new map<int, int>();
      if (!i)
        continue;

      if (a[i] == a[i - 1]) l[i] = i - 1;
      else if (l[i - 1] >= 0 && lMap[i - 1]->count(a[i])) l[i] = (*lMap[i - 1])[a[i]];

      if (l[i] >= 0)
      {
        f[i] = 1;
        if (l[i])
        {
          lMap[i] = lMap[l[i] - 1];
          (*lMap[i])[a[l[i] - 1]] = l[i] - 1;
          f[i] += f[l[i] - 1];
        }
        ans += f[i];
      }
    }

    cout << ans << '\n';
  }
}