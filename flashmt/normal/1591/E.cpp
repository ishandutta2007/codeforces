#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#endif
using namespace std;
const int N = 1e6 + 5;


vector<int> a[N], cnt, sortedV, pos, bound, ans;
int n, v[N], par[N];
vector<tuple<int, int, int>> queries[N];

void swapId(int x, int y)
{
  swap(sortedV[x], sortedV[y]);
  pos[sortedV[x]] = x;
  pos[sortedV[y]] = y;
}

void dfs(int x)
{
  int curId = pos[v[x]];
  cnt[v[x]]++;
  int lastId = bound[cnt[v[x]]] - 1;
  swapId(curId, lastId);
  int oldBound = bound[cnt[v[x]]];
  bound[cnt[v[x]]] = lastId;

  for (auto [l, k, id] : queries[x])
    if (bound[l] + k < n)
      ans[id] = sortedV[bound[l] + k];

  for (int y : a[x])
    dfs(y);

  bound[cnt[v[x]]] = oldBound;
  cnt[v[x]]--;
  swapId(curId, lastId);
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--)
  {
    int q;
    cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
      a[i].clear();
      queries[i].clear();
      cin >> v[i];
      v[i]--;
    }
    for (int i = 1; i < n; i++)
    {
      cin >> par[i];
      a[--par[i]].push_back(i);
    }

    ans.assign(q, -2);
    for (int i = 0; i < q; i++)
    {
      int x, l, k;
      cin >> x >> l >> k;
      queries[--x].push_back({l, --k, i});
    }

    cnt.assign(n, 0);
    pos.resize(n);
    iota(begin(pos), end(pos), 0);
    sortedV = pos;
    bound.assign(n + 2, n);
    bound[0] = 0;
    dfs(0);

    for (int x : ans)
      cout << x + 1 << ' ';
    cout << '\n';
  }
}