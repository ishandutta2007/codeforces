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
    int l, r;
    cin >> l >> r;
    vector<int> a(r - l + 1);
    for (int &x : a)
      cin >> x;

    int ans = 0;
    for (int bit = 16; bit >= 0; bit--)
    {
      sort(begin(a), end(a), [&](int u, int v) { return (u >> bit + 1) < (v >> bit + 1); });
      for (int i = 0; i <= r - l;)
      {
        int j = i;
        vector<int> cntA(2), cntLR(2);
        while (j <= r - l && (a[j] >> bit + 1) == (a[i] >> bit + 1))
        {
          cntA[a[j] >> bit & 1]++;
          cntLR[j + l >> bit & 1]++;
          j++;
        }

        if (cntA[0] != cntA[1])
        {
          if (cntA[0] != cntLR[0])
          {
            ans |= 1 << bit;
            for (int k = i; k < j; k++)
              a[k] ^= 1 << bit;
          }
          break;
        }

        i = j;
      }
    }
    cout << ans << endl;
    // cout << ans << '\n';
  }
}