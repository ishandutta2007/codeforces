#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#endif
using namespace std;
const int oo = 2000111222;
const int THRESHOLD = 700;
const int N = 100100;

map<int, int> allVal;

int getVal(int x)
{
  if (!allVal.count(x))
    allVal[x] = size(allVal);
  return allVal[x];
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m + 1));
  for (int i = 0; i < n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      int x;
      cin >> x;
      a[i][j] = getVal(x);
    }
    cin >> a[i][0];
  }

  sort(begin(a), end(a));

  vector<vector<int>> rows(n * m);
  for (int i = 0; i < n; i++)
    for (int j = 1; j <= m; j++)
      rows[a[i][j]].push_back(i);

  vector<int> bigColId(m * n, -1);
  vector<bitset<N>> bigCols;
  for (int i = 0; i < size(allVal); i++)
    if (size(rows[i]) > THRESHOLD)
    {
      bigColId[i] = size(bigCols);
      bitset<N> b;
      b.set();
      for (int j : rows[i])
        b[j] = 0;
      bigCols.push_back(b);
    }

  int ans = oo;
  for (int i = 0; i < n; i++)
  {
    bitset<N> flag;
    flag.set();
    for (int j = 1; j <= m; j++)
    {
      int x = a[i][j];
      if (bigColId[x] >= 0) flag &= bigCols[bigColId[x]];
      else
        for (int k : rows[x])
          flag[k] = 0;
    }
    int ii = flag._Find_first();
    if (ii < n)
      ans = min(ans, a[i][0] + a[ii][0]);
  }

  cout << (ans == oo ? -1 : ans) << endl;
}