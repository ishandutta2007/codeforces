#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#endif
using namespace std;

vector<int> a[100100];
int counter, numScc;
vector<int> low, num, sccId, st;

void dfs(int x)
{
  low[x] = num[x] = counter++;
  st.push_back(x);
  for (int y : a[x])
    if (sccId[y] < 0)
    {
      if (num[y] >= 0) low[x] = min(low[x], num[y]);
      else
      {
        dfs(y);
        low[x] = min(low[x], low[y]);
      }
    }

  if (low[x] != num[x])
    return;

  while (1)
  {
    int y = st.back();
    st.pop_back();
    sccId[y] = numScc;
    if (y == x)
      break;
  }
  numScc++;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--)
  {
    int n;
    cin >> n;
    vector<int> strA(n), strB(n);
    for (int i = 0; i < n; i++)
      cin >> strA[i];
    for (int i = 0; i < n; i++)
      cin >> strB[i];

    for (int i = 0; i < n; i++)
      a[i].clear();
    vector<int> id(n);
    iota(begin(id), end(id), 0);
    sort(begin(id), end(id), [&](int u, int v) { return strA[u] < strA[v]; });
    for (int i = 0; i + 1 < n; i++)
      a[id[i + 1]].push_back(id[i]);
    sort(begin(id), end(id), [&](int u, int v) { return strB[u] < strB[v]; });
    for (int i = 0; i + 1 < n; i++)
      a[id[i + 1]].push_back(id[i]);

    low = num = sccId = vector<int>(n, -1);
    st.clear();
    counter = numScc = 0;
    for (int i = 0; i < n; i++)
      if (sccId[i] < 0)
        dfs(i);

    vector<int> isGood(numScc, 1);
    for (int x = 0; x < n; x++)
      for (int y : a[x])
        if (sccId[x] != sccId[y])
          isGood[sccId[y]] = 0;

    for (int i = 0; i < n; i++)
      cout << isGood[sccId[i]];
    cout << '\n';
  }
}