#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#else
#define debug(...) 42
#endif
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, x;
  while (cin >> n >> x)
  {
    vector<int> cnt(x + 1);
    for (int i = 0; i < n; i++)
    {
      int y;
      cin >> y;
      if (y < x)
        cnt[y]++;
    }

    int ans = 1;
    for (int i = 1; i < x; i++)
      if (cnt[i] % (i + 1))
      {
        ans = 0;
        break;
      }
      else cnt[i + 1] += cnt[i] / (i + 1);

    cout << (ans ? "Yes" : "No") << endl;
  }
}