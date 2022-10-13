#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#endif
using namespace std;
const int oo = 27081993;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--)
  {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), sortedA(n);
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
      sortedA[i] = a[i];
    }
    sort(begin(sortedA), end(sortedA));

    int need = (n + k + 1) / 2;
    int best = oo, minA = -1, maxA = -1;
    for (int i = 0; i + need <= n; i++)
      if (sortedA[i + need - 1] - sortedA[i] < best)
      {
        best = sortedA[i + need - 1] - sortedA[i];
        minA = sortedA[i];
        maxA = sortedA[i + need - 1];
      }

    cout << minA << ' ' << maxA << '\n';
    for (int i = 0, group = 0; i < n;)
    {
      int cur = 0, j = i;
      while (cur <= 0)
      {
        if (a[j] < minA || a[j] > maxA) cur--;
        else cur++;
        j++;
      }

      if (++group == k)
        j = n;

      cout << i + 1 << ' ' << j << '\n';
      i = j;
    }
  }
}