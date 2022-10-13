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
    int n, k, x[111], y[111];
    cin >> n >> k;
    for (int i = 0; i < n; i++)
      cin >> x[i] >> y[i];

    int ans = -1;
    for (int i = 0; i < n; i++)
    {
      int isGood = 1;
      for (int j = 0; j < n; j++)
        if (abs(x[i] - x[j]) + abs(y[i] - y[j]) > k)
          isGood = 0;
      if (isGood)
        ans = 1;
    }

    cout << ans << endl;
  }
}