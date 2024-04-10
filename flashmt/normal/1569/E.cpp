#include <bits/stdc++.h>
using namespace std;
const int BASE = 998244353;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int k, A, h;
  cin >> k >> A >> h;
  long long p[33] = {1};
  for (int i = 1; i <= 1 << k; i++)
    p[i] = p[i - 1] * A % BASE;

  if (k == 1)
  {
    if ((p[1] + p[2] * 2) % BASE == h) cout << 1 << ' ' << 2 << endl;
    else if ((p[1] * 2 + p[2]) % BASE == h) cout << 2 << ' ' << 1 << endl;
    else cout << -1 << endl;
    return 0;
  }

  int m = (1 << k - 1) - 1;
  map<int, vector<int>> upperBracket[2];
  for (int turn = 0; turn < 2; turn++)
  {
    vector<int> a((1 << k) - 1), rank((1 << k) + 1);
    for (int i = 0; i <= m; i++)
      a[m + i] = i + 1 + (turn << k - 1);
    for (int mask = 0; mask < 1 << m; mask++)
    {
      for (int i = 0; i <= m; i++)
        rank[a[m + i]] = m + 2;
      for (int i = m - 1; i >= 0; i--)
      {
        a[i] = a[i * 2 + 1 + (mask >> i & 1)];
        rank[a[i]] = rank[a[i]] / 2 + 1;
      }

      long long loseH = 0;
      vector<int> curRank;
      for (int i = 1; i <= 1 << k - 1; i++)
      {
        int id = i + (turn << k - 1);
        curRank.push_back(rank[id]);
        loseH = (loseH + id * p[rank[id]]) % BASE;
      }

      long long winH = (loseH + a[0] * (p[1] - p[2] + BASE)) % BASE;

      if (!turn)
      {
        upperBracket[0][loseH] = curRank;
        curRank[(a[0] - 1)] = 1;
        upperBracket[1][winH] = curRank;
      }
      else
      {
        vector<int> upperRank;
        int targetH = (h + BASE - loseH) % BASE;
        if (upperBracket[1].count(targetH))
        {
          for (int x : upperBracket[1][targetH])
            cout << x << ' ';
          for (int x : curRank)
            cout << x << ' ';
          return 0;
        }

        targetH = (h + BASE - winH) % BASE;
        if (upperBracket[0].count(targetH))
        {
          for (int x : upperBracket[0][targetH])
            cout << x << ' ';
          curRank[a[0] - 1 - (1 << k - 1)] = 1;
          for (int x : curRank)
            cout << x << ' ';
          return 0;
        }
      }
    }
  }

  cout << -1 << endl;
}