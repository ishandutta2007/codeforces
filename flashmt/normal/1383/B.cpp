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
    int n, cnt[30][2] = {0};
    cin >> n;
    for (int i = 0; i < n; i++)
    {
      int x;
      cin >> x;
      for (int j = 0; j < 30; j++)
        cnt[j][x >> j & 1]++;
    }

    int oddBit = -1;
    for (int i = 29; i >= 0; i--)
      if (cnt[i][1] % 2)
      {
        oddBit = i;
        break;
      }

    if (oddBit < 0) cout << "DRAW\n";
    else if ((cnt[oddBit][1] / 2 + 1) % 2) cout << "WIN\n";
    else cout << (cnt[oddBit][0] % 2 ? "WIN\n" : "LOSE\n");
  }
}