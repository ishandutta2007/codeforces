#include <bits/stdc++.h>
using namespace std;
const int BIT = 20;

int head[2][1 << BIT], tail[2][1 << BIT];
vector<int> id[2][1 << BIT];

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> sumXor(n + 1), a(n + 1);
  for (int i = 1; i <= n; i++)
  {
    cin >> a[i];
    sumXor[i] = sumXor[i - 1] ^ a[i];
  }

  int ans = 0, prefixMask = (1 << BIT) - 1;
  for (int bit = 0; bit < BIT; bit++)
  {
    int lastZero = -1;
    prefixMask ^= 1 << bit;
    for (int i = 0; i < 2; i++)
      for (int j = 0; j < 1 << BIT; j++)
      {
        head[i][j] = tail[i][j] = 0;
        id[i][j].clear();
      }

    for (int i = 0; i <= n; i++)
    {
      int curBit = a[i] >> bit & 1, prefix = sumXor[i] & prefixMask;
      if (!curBit) lastZero = i;
      else
      {
        while (head[i & 1][prefix] < tail[i & 1][prefix] && id[i & 1][prefix][head[i & 1][prefix]] < lastZero)
          head[i & 1][prefix]++;
        if (head[i & 1][prefix] < tail[i & 1][prefix])
          ans = max(ans, i - id[i & 1][prefix][head[i & 1][prefix]]);
      }

      id[i & 1][prefix].push_back(i);
      tail[i & 1][prefix]++;
    }
  }

  cout << ans << endl;
}