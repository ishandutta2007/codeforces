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
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> cntL(n), cntR(n);
    for (int i = 0; i < l; i++)
    {
      int x;
      cin >> x;
      cntL[x - 1]++;
    }
    for (int i = 0; i < r; i++)
    {
      int x;
      cin >> x;
      cntR[x - 1]++;
    }

    l = r = 0;
    int sameL = 0, sameR = 0;
    for (int i = 0; i < n; i++)
    {
      int pairs = min(cntL[i], cntR[i]);

      cntL[i] -= pairs;
      l += cntL[i];
      sameL += cntL[i] / 2;

      cntR[i] -= pairs;
      r += cntR[i];
      sameR += cntR[i] / 2;
    }

    int numSwitch = abs(l - r) / 2;
    int ans = numSwitch + (l + r) / 2;
    if (l > r) ans -= min(numSwitch, sameL);
    else if (r > l) ans -= min(numSwitch, sameR);

    cout << ans << endl;
  }
}