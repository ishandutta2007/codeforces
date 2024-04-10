#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#endif
using namespace std;
const int oo = 1 << 30;

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
    vector<int> l(n), r(n), c(n);
    for (int i = 0; i < n; i++)
      cin >> l[i] >> r[i] >> c[i];

    int minId = 0, maxId = 0, longest = 0;
    for (int i = 0; i < n; i++)
    {
      if (l[i] < l[minId] || (l[i] == l[minId] && c[i] < c[minId]))
        minId = i;
      if (r[i] > r[maxId] || (r[i] == r[maxId] && c[i] < c[maxId]))
        maxId = i;
      if (r[i] - l[i] > r[longest] - l[longest] || (r[i] - l[i] == r[longest] - l[longest] && c[i] < c[longest]))
        longest = i;

      int ans = c[minId] + c[maxId];
      if (r[longest] == r[maxId] && l[longest] == l[minId])
        ans = min(ans, c[longest]);
      cout << ans << '\n';
    }
  }
}