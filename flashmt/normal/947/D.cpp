#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  string s, t;
  cin >> s >> t;

  int lenS = size(s), lenT = size(t);
  s = " " + s, t = " " + t;
  vector<int> cntBCS(lenS + 1), lastBCS(lenS + 1);
  vector<int> cntBCT(lenT + 1), lastBCT(lenT + 1);
  for (int i = 1, cur = 0; i <= lenS; i++)
  {
    cntBCS[i] = cntBCS[i - 1];
    if (s[i] != 'A')
    {
      cur = i;
      cntBCS[i]++;
    }
    lastBCS[i] = cur;
  }
  for (int i = 1, cur = 0; i <= lenT; i++)
  {
    cntBCT[i] = cntBCT[i - 1];
    if (t[i] != 'A')
    {
      cur = i;
      cntBCT[i]++;
    }
    lastBCT[i] = cur;
  }

  int q;
  cin >> q;
  while (q--)
  {
    int x, y, u, v;
    cin >> x >> y >> u >> v;

    int bcs = cntBCS[y] - cntBCS[x - 1];
    int bct = cntBCT[v] - cntBCT[u - 1];
    int suffixAS = y - max(x - 1, lastBCS[y]);
    int suffixAT = v - max(u - 1, lastBCT[v]);
    if (suffixAS < suffixAT) cout << 0;
    else
    {
      suffixAS -= suffixAT;
      if (bct == bcs) cout << (suffixAS % 3 == 0);
      else
      {
        if (suffixAS)
          bcs += 2;
        cout << (bcs && bcs <= bct && bcs % 2 == bct % 2);
      }
    }
  }
}