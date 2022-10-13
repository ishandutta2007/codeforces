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
    int ans = 0, lastZero = 0;
    while (m >> lastZero & 1)
      lastZero++;
    for (int i = 29; i >= 0; i--)
      if (m >> i & 1)
      {
        if (n >> i & 1 ^ 1)
          ans ^= 1 << i;
      }
      else
      {
        if (n >> i & 1)
          break;
        if (i == lastZero)
        {
          ans ^= 1 << i;
          break;
        }
      }
      
    cout << ans << endl;
  }
}