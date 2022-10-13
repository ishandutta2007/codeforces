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
    int n, a[111] = {0}, b[111] = {0};
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
      int x;
      cin >> x;
      a[x]++;
    }
    for (int i = 1; i <= n; i++)
    {
      int x;
      cin >> x;
      b[x]++;
    }

    for (int ans = 0;; ans++)
    {
      int round = n + ans, used = round - round / 4;
      int scoreDiff = 0, cntA = used, cntB = used;
      for (int i = 100; i >= 0; i--)
      {
        int pickA = min(cntA, a[i]);
        int pickB = min(cntB, b[i]);
        scoreDiff += i * (pickA - pickB);
        cntA -= pickA;
        cntB -= pickB;
      }
      if (scoreDiff >= 0)
      {
        cout << ans << endl;
        break;
      }
      a[100]++;
      b[0]++;
    }
  }
}