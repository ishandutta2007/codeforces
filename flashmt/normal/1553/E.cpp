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
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
      a[i]--;
    }

    vector<int> cnt(n);
    for (int i = 0; i < n; i++)
      cnt[(i + n - a[i]) % n]++;

    vector<int> ans;
    for (int shift = 0; shift < n; shift++)
      if (cnt[shift] >= n / 3)
      {
        vector<int> b, id(n);
        for (int i = n - shift; i < n; i++)
          b.push_back(i);
        for (int i = 0; i < n - shift; i++)
          b.push_back(i);
        for (int i = 0; i < n; i++)
          id[b[i]] = i;

        vector<int> flag(n);
        int swap = 0;
        for (int i = 0; i < n; i++)
          if (!flag[i])
          {
            int x = i, cnt = 0;
            while (!flag[x])
            {
              flag[x] = 1;
              x = id[a[x]];
              cnt++;
            }
            swap += cnt - 1;
          }

        if (swap <= m)
          ans.push_back(shift);
      }

    cout << size(ans);
    for (int x : ans)
      cout << ' ' << x;
    cout << '\n';
  }
}