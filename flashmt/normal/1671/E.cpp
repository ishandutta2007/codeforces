#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#else
#define debug(...) 42
#endif
using namespace std;
const int BASE = 998244353;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  string s;
  cin >> n >> s;

  long long ans = 1;
  vector<int> rank(1 << n);
  for (int i = n - 1; i >= 0; i--)
  {
    vector<pair<long long, int>> at[2];
    for (int j = 0; j < 1 << i; j++)
    {
      int id = j + (1 << i) - 1;
      long long children = 0;
      if (i < n - 1)
      {
        int lId = id * 2 + 1, rId = lId + 1;
        if (rank[lId] > rank[rId])
          swap(rank[lId], rank[rId]);
        if (rank[lId] != rank[rId])
          ans = ans * 2 % BASE;
        children = rank[lId] << n | rank[rId];
      }
      at[s[id] - 'A'].push_back({children, id});
    }

    int curRank = 0;
    for (int v : {0, 1})
    {
      sort(begin(at[v]), end(at[v]));
      long long last = -1;
      for (auto [cur, id] : at[v])
      {
        if (cur > last)
        {
          curRank++;
          last = cur;
        }
        rank[id] = curRank - 1;
      }
    }
  }

  cout << ans << endl;
}