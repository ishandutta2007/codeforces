#include <bits/stdc++.h>
using namespace std;
const int N = 1000100;

int n, num[N], low[N], flag[N], counter, sccId[N], numScc, isLeaf[N];
vector<int> a[N], st;

inline void dfs(int x)
{
  low[x] = num[x] = counter++;
  st.push_back(x);
  flag[x] = 1;
  for (int y : a[x])
  {
    if (num[y] < 0)
      dfs(y);
    if (flag[y])
      low[x] = min(low[x], low[y]);
  }

  if (low[x] != num[x])
    return;

  while (1)
  {
    int y = st.back();
    st.pop_back();
    flag[y] = 0;
    sccId[y] = numScc;
    if (y == x)
      break;
  }
  isLeaf[numScc] = 1;
  numScc++;
}

void init()
{
  for (int i = 1; i <= n; i++)
  {
    a[i].clear();
    num[i] = low[i] = sccId[i] = -1;
    flag[i] = 0;
  }
  counter = numScc = 0;
  st.clear();
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--)
  {
    int m;
    cin >> n >> m;
    init();
    while (m--)
    {
      int x, y;
      cin >> x >> y;
      if (x != y)
        a[x].push_back(y);
    }

    for (int i = 1; i <= n; i++)
      if (num[i] < 0)
        dfs(i);

    if (numScc == 1) cout << "No\n";
    else
    {
      for (int x = 1; x <= n; x++)
        for (int y : a[x])
          if (sccId[y] != sccId[x])
            isLeaf[sccId[x]] = 0;
      int leafId = -1;
      for (int i = 0; i < numScc; i++)
        if (isLeaf[i])
          leafId = i;
      assert(leafId >= 0);

      cout << "Yes\n";
      int cnt = 0;
      for (int i = 1; i <= n; i++)
        cnt += sccId[i] == leafId;
      cout << cnt << ' ' << n - cnt << '\n';
      for (int i = 1; i <= n; i++)
        if (sccId[i] == leafId)
          cout << i << ' ';
      cout << '\n';
      for (int i = 1; i <= n; i++)
        if (sccId[i] != leafId)
          cout << i << ' ';
      cout << '\n';
    }
  }
}