#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#endif
using namespace std;
const int N = 300300;

int n, c[N], isGood[N], isGoodDown[N], blackCnt[N], blackChild[N];
vector<int> a[N];

void dfs(int x, int par = -1)
{
  blackCnt[x] = c[x];
  for (int y : a[x])
    if (y != par)
    {
      dfs(y, x);
      isGood[x] |= isGood[y];
      blackChild[x] += c[y];
      blackCnt[x] += blackCnt[y];
    }

  isGood[x] |= blackCnt[x] >= 2 && (c[x] || blackChild[x]);
}

void dfsDown(int x, int par = -1)
{
  int goodChildCnt = 0;
  for (int y : a[x])
    if (y != par)
      goodChildCnt += isGood[y];

  for (int y : a[x])
    if (y != par)
    {
      int curBlackChild = blackChild[x] - c[y] + (par >= 0 ? c[par] : 0);
      int curBlackCnt = blackCnt[0] - blackCnt[y];
      isGoodDown[y] = isGoodDown[x];
      isGoodDown[y] |= curBlackCnt >= 2 && (c[x] || curBlackChild);
      isGoodDown[y] |= goodChildCnt >= 2 || (goodChildCnt == 1 && !isGood[y]);
      dfsDown(y, x);
    }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> c[i];
  for (int i = 0; i < n - 1; i++)
  {
    int x, y;
    cin >> x >> y;
    a[--x].push_back(--y);
    a[y].push_back(x);
  }

  dfs(0);
  dfsDown(0);
  for (int x = 0; x < n; x++)
    for (int y : a[x])
      isGood[y] |= c[x];

  for (int i = 0; i < n; i++)
    cout << (isGood[i] || isGoodDown[i] || c[i]) << " \n"[i == n - 1];
}