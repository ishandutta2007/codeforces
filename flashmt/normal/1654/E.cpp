#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#endif
using namespace std;
const int A = 100010;
const int THRESHOLD = 225;
const int STEP = A / THRESHOLD + 1;
const int MAX = A * (THRESHOLD + 1);

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &x : a)
    cin >> x;

  if (n <= 2)
  {
    cout << 0 << endl;
    return 0;
  }

  int ans = 2;

  // |d| <= THRESHOLD
  vector<int> cntX(MAX * 2 + 1), flagX(MAX * 2 + 1, -THRESHOLD - 1);
  for (int d = -THRESHOLD; d <= THRESHOLD; d++)
    for (int i = 0; i < n; i++)
    {
      int x = d * i - a[i] + MAX;
      if (flagX[x] == d) ans = max(ans, ++cntX[x]);
      else
      {
        flagX[x] = d;
        cntX[x] = 1;
      }
    }

  // |d| > THRESHOLD, at most 1e5 / d steps
  vector<int> cntD(A * 2 + 1, 1), flagD(A * 2 + 1, -1);
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j <= min(i + STEP, n - 1); j++)
      if ((a[j] - a[i]) % (j - i) == 0)
      {
        int d = (a[j] - a[i]) / (j - i) + A;
        if (flagD[d] == i) ans = max(ans, ++cntD[d]);
        else
        {
          flagD[d] = i;
          cntD[d] = 2;
        }
      }

  cout << n - ans << endl;
}