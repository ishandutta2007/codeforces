#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#endif
using namespace std;
const int N = 200200;

vector<int> adj[N];
int flag[N], hasCycle;

void dfs(int x)
{
  flag[x] = 1;
  for (int y : adj[x])
    if (!flag[y]) dfs(y);
    else if (flag[y] > 0) hasCycle = 1;
  flag[x] = -1;
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
    vector<int> a(n), cnt(n + 1);
    vector<vector<int>> id(n + 1);
    for (int &x : a)
    {
      cin >> x;
      cnt[x]++;
    }
    vector<int> b(n);
    for (int &x : b)
      cin >> x;

    int maxCnt = *max_element(begin(cnt), end(cnt));

    int numCycle = 0;
    for (int i = 0; i < n; i++)
      if (a[i] == b[i]) numCycle++;
      else id[a[i]].push_back(i);

    int maxA = 0;
    for (int i = 1; i <= n; i++)
      if (size(id[i]) > size(id[maxA]))
        maxA = i;

    numCycle += size(id[maxA]);
    if (numCycle > maxCnt)
    {
      cout << "WA\n";
      continue;
    }

    for (int i = 1; i <= n; i++)
    {
      adj[i].clear();
      flag[i] = 0;
    }
    hasCycle = 0;
    for (int i = 0; i < n; i++)
      if (a[i] != b[i] && a[i] != maxA && b[i] != maxA)
        adj[a[i]].push_back(b[i]);
    for (int i = 1; i <= n; i++)
      if (!flag[i])
        dfs(i);

    cout << (!hasCycle ? "AC" : "WA") << '\n';
  }
}