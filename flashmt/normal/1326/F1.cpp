#include <bits/stdc++.h>
using namespace std;

int n, a[14][14], cnt[1 << 14][14][1 << 6], cntR[1 << 14][14][1 << 7];
vector<int> bits[1 << 14];

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    string s;
    cin >> s;
    for (int j = 0; j < n; j++)
      a[i][j] = s[j] - '0';
  }

  vector<int> goodMasks;
  int leftBit = n / 2, rightBit = n - leftBit;
  for (int mask = 0; mask < 1 << n; mask++)
    {
      for (int i = 0; i < n; i++)
        if (mask >> i & 1)
          bits[mask].push_back(i);

      if (bits[mask].size() == leftBit) goodMasks.push_back(mask);
      else if (bits[mask].size() != rightBit) continue;

      auto cur = bits[mask];
      do
      {
        int neighborMask = 0;
        for (int i = 0; i + 1 < cur.size(); i++)
          neighborMask = (neighborMask << 1) | a[cur[i]][cur[i + 1]];
        cnt[mask][cur.back()][neighborMask]++;
      } while (next_permutation(begin(cur), end(cur)));
    }

  vector<int> rev(1 << rightBit - 1);
  for (int mask = 0; mask < 1 << rightBit - 1; mask++)
    for (int i = 0; i < rightBit - 1; i++)
      if (mask >> i & 1)
        rev[mask] |= 1 << rightBit - 2 - i;

  for (int leftMask : goodMasks)
  {
    int rightMask = ((1 << n) - 1) ^ leftMask;
    for (int i : bits[leftMask])
      for (int j : bits[rightMask])
        for (int k = 0; k < 1 << rightBit - 1; k++)
        {
          int kk = a[i][j] << rightBit - 1 | rev[k];
          cntR[leftMask][i][kk] += cnt[rightMask][j][k];
        }
  }

  vector<long long> ans(1 << n - 1);
  for (int leftMask : goodMasks)
    for (int i : bits[leftMask])
      for (int leftNeighborMask = 0; leftNeighborMask < 1 << leftBit - 1; leftNeighborMask++)
        if (cnt[leftMask][i][leftNeighborMask])
          for (int rightNeighborMask = 0; rightNeighborMask < 1 << rightBit; rightNeighborMask++)
          {
            int neighborMask = leftNeighborMask << rightBit | rightNeighborMask;
            ans[neighborMask] += 1LL * cnt[leftMask][i][leftNeighborMask] * cntR[leftMask][i][rightNeighborMask];
          }

  for (auto x : ans)
    cout << x << ' ';
}