// Heavy-light decomposition and only update heavy subtree

#include <bits/stdc++.h>
using namespace std;
const int BASE = 998244353;
const int N = 150150;

struct HeavyLightDecomposition
{
  int n, numChain;
  vector<int> a[N], chains[N], par, subtree, chainId, nodeId;
  int preDfs[N], postDfs[N], dfsCount;

  HeavyLightDecomposition(int n): n(n), numChain(0)
  {
    par = subtree = chainId = nodeId = vector<int>(n + 1, 0);
    dfsCount = 0;
  }

  void addEdge(int x, int y)
  {
    a[x].push_back(y);
    a[y].push_back(x);
  }

  void dfs(int x)
  {
    preDfs[x] = ++dfsCount;
    subtree[x] = 1;
    for (int y : a[x])
      if (y != par[x])
      {
        par[y] = x;
        dfs(y);
        subtree[x] += subtree[y];
      }
    postDfs[x] = dfsCount;
  }

  void calcChain(int x, int isHeavy)
  {
    if (!isHeavy) chainId[x] = ++numChain;
    else chainId[x] = chainId[par[x]];
    nodeId[x] = chains[chainId[x]].size();
    chains[chainId[x]].push_back(x);
    for (int y : a[x])
      if (y != par[x])
        calcChain(y, subtree[y] * 2 > subtree[x]);
  }

  void decompose(int root = 1)
  {
    dfs(root);
    calcChain(root, 0);
  }
};

int n, tree[N], nodeValues[N];

long long power(long long x, long long y)
{
  if (!y)
    return 1;
  long long res = power(x, y >> 1);
  res = res * res % BASE;
  if (y & 1)
    res = res * x % BASE;
  return res;
}

void add(int x, int v)
{
  for (int i = x; i <= n; i += i & -i)
  {
    tree[i] += v;
    if (tree[i] >= BASE)
      tree[i] -= BASE;
  }
}

int get(int x)
{
  int res = 0;
  for (int i = x; i; i -= i & -i)
  {
    res += tree[i];
    if (res >= BASE)
      res -= BASE;
  }
  return res;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int q;
  cin >> n >> q;
  HeavyLightDecomposition hld(n);
  for (int i = 1; i < n; i++)
  {
    int x, y;
    cin >> x >> y;
    hld.addEdge(x, y);
  }

  hld.decompose();
  int sumD = 0;
  long long invN = power(n, BASE - 2);
  while (q--)
  {
    int op, x, d;
    cin >> op >> x;
    if (op == 1)
    {
      cin >> d;
      if (!d) // what's the point???
        continue;

      sumD = (sumD + d) % BASE;
      // node value
      nodeValues[x] = (nodeValues[x] + d) % BASE;
      // par
      if (hld.par[x])
      {
        int sz = n - hld.subtree[x];
        long long value = sz * invN % BASE * d % BASE;
        if (hld.preDfs[x] > 1)
        {
          add(1, value);
          add(hld.preDfs[x], BASE - value);
        }
        if (hld.postDfs[x] < n)
          add(hld.postDfs[x] + 1, value);
      }
      // heavy child
      if (hld.nodeId[x] + 1 < hld.chains[hld.chainId[x]].size())
      {
        int y = hld.chains[hld.chainId[x]][hld.nodeId[x] + 1];
        long long value = hld.subtree[y] * invN % BASE * d % BASE;
        add(hld.preDfs[y], value);
        if (hld.postDfs[y] < n)
          add(hld.postDfs[y] + 1, BASE - value);
      }
    }
    else
    {
      int ans = get(hld.preDfs[x]);
      // go up through light edges
      while (x)
      {
        x = hld.chains[hld.chainId[x]][0];
        if (hld.par[x])
        {
          long long value = hld.subtree[x] * invN % BASE * nodeValues[hld.par[x]] % BASE;
          ans += value;
          if (ans >= BASE)
            ans -= BASE;
        }
        x = hld.par[x];
      }
      ans = (sumD - ans + BASE) % BASE;
      cout << ans << '\n';
    }
  }
}