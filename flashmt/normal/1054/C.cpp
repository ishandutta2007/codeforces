#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, l[1010], r[1010], done[1010] = {0};
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> l[i];
  for (int i = 0; i < n; i++)
    cin >> r[i];

  int ans[1010], candy = n;
  while (1)
  {
    vector<int> cur;
    for (int i = 0; i < n; i++)
      if (!done[i] && !l[i] && !r[i])
      {
        done[i] = 1;
        ans[i] = candy;
        cur.push_back(i);
      }

    if (cur.empty())
      break;

    candy--;
    for (int i : cur)
      for (int j = 0; j < n; j++)
        if (!done[j])
        {
          if (j < i) r[j]--;
          else l[j]--;
          if (l[j] < 0 || r[j] < 0)
          {
            cout << "NO" << endl;
            return 0;
          }
        }
  }

  for (int i = 0; i < n; i++)
    if (!done[i])
    {
      cout << "NO" << endl;
      return 0;
    }

  cout << "YES" << endl;
  for (int i = 0; i < n; i++)
    cout << ans[i] << " \n"[i == n - 1];
}