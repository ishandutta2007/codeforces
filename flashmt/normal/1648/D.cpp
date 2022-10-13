#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#endif
using namespace std;
const long long oo = 1LL << 60;

struct SegmentTree
{
  int low, mid, high;
  long long val, cost;
  long long saveAdd, saveBound;
  SegmentTree *l, *r;

  SegmentTree(int low, int high): low(low), high(high)
  {
    mid = (low + high) / 2;
    val = cost = saveBound = -oo;
    saveAdd = 0;
    if (low == high) l = r = NULL;
    else
    {
      l = new SegmentTree(low, mid);
      r = new SegmentTree(mid + 1, high);
    }
  }

  void updateNode(long long add, long long bound)
  {
    val = max(val + add, bound + cost);
    saveAdd += add;
    saveBound = max(saveBound + add, bound);
  }

  void pushDown()
  {
    l->updateNode(saveAdd, saveBound);
    r->updateNode(saveAdd, saveBound);
    saveAdd = 0;
    saveBound = -oo;
  }

  void set(int x, long long v, long long c)
  {
    if (low == high)
    {
      val = v;
      cost = c;
      return;
    }
    pushDown();
    if (x <= mid) l->set(x, v, c);
    else r->set(x, v, c);
    val = max(l->val, r->val);
    cost = max(l->cost, r->cost);
  }
};

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, q;
  cin >> n >> q;

  // 1-indexed
  vector<vector<int>> a(4, vector<int>(n + 1));
  vector<vector<long long>> sum(4, vector<long long>(n + 1));
  for (int i = 1; i <= 3; i++)
    for (int j = 1; j <= n; j++)
    {
      cin >> a[i][j];
      sum[i][j] = sum[i][j - 1] + a[i][j];
    }

  vector<vector<pair<int, long long>>> segsAt(n + 1);
  for (int i = 1; i <= q; i++)
  {
    int l, r, w;
    cin >> l >> r >> w;
    segsAt[l].push_back({i, w});
    if (r < n)
      segsAt[r + 1].push_back({i, oo});
  }

  long long ans = -oo;
  vector<long long> f(n + 1, -oo); // max cost to reach (2, i)
  SegmentTree tree(1, q);
  for (int i = 1; i <= n; i++)
  {
    for (auto [id, w] : segsAt[i])
      tree.set(id, max(sum[1][i], f[i - 1]) - w, -w);
    tree.updateNode(a[2][i], sum[1][i] + a[2][i]);
    f[i] = tree.val;
    ans = max(ans, f[i] + sum[3][n] - sum[3][i - 1]);
  }
  cout << ans << endl;
}