#include <bits/stdc++.h>
using namespace std;
const int N = 300300;
const int LOG = 20;

struct SegmentTree
{
  int low, mid, high;
  long long value;
  SegmentTree *l, *r;

  SegmentTree(int low, int high): low(low), high(high)
  {
    mid = (low + high) / 2;
    value = 0;
    if (low != high)
    {
      l = new SegmentTree(low, mid);
      r = new SegmentTree(mid + 1, high);
    }
  }

  SegmentTree(SegmentTree *u)
  {
    *this = *u;
  }

  SegmentTree* add(int x, long long v)
  {
    SegmentTree *newNode = new SegmentTree(*this);
    newNode->value ^= v;
    if (low != high)
    {
      if (x <= mid) newNode->l = l->add(x, v);
      else newNode->r = r->add(x, v);
    }
    return newNode;
  }

  long long get(int x, int y)
  {
    if (low == x && high == y)
      return value;
    if (y <= mid) return l->get(x, y);
    else if (mid < x) return r->get(x, y);
    else return l->get(x, mid) ^ r->get(mid + 1, y);
  }
};

vector<int> a[N];
int n, values[N], depth[N], p[N][LOG];
long long randomValues[N];
SegmentTree *tree[N];

void dfs(int x)
{
  for (int i = 0; i + 1 < LOG; i++)
    if (p[x][i] >= 0)
      p[x][i + 1] = p[p[x][i]][i];

  for (int y : a[x])
    if (y != p[x][0])
    {
      p[y][0] = x;
      depth[y] = depth[x] + 1;
      tree[y] = tree[x]->add(values[y], randomValues[values[y]]);
      dfs(y);
    }
}

int lca(int x, int y)
{
  if (depth[x] > depth[y])
    swap(x, y);
  for (int i = LOG - 1; i >= 0; i--)
    if (depth[y] - (1 << i) >= depth[x])
      y = p[y][i];
  if (x == y)
    return x;
  for (int i = LOG - 1; i >= 0; i--)
    if (p[x][i] != p[y][i])
    {
      x = p[x][i];
      y = p[y][i];
    }
  return p[x][0];
}

int findValue(SegmentTree *u, SegmentTree *v, int low, int high)
{
  if (u->low == low && u->high == high && u->value == v->value)
    return -1;
  if (u->low == u->high)
    return u->low;

  if (high <= u->mid) return findValue(u->l, v->l, low, high);
  else if (low > u->mid) return findValue(u->r, v->r, low, high);

  int res = findValue(u->l, v->l, low, u->mid);
  return res >= 0 ? res : findValue(u->r, v->r, u->mid + 1, high);
}

int query(int u, int v, int low, int high)
{
  if (depth[u] > depth[v])
    swap(u, v);

  int w = lca(u, v);
  if (low <= values[w] && values[w] <= high)
  {
    long long valueU = tree[u]->get(values[w], values[w]);
    long long valueV = tree[v]->get(values[w], values[w]);
    if (valueU == valueV)
      return values[w];

    if (low < values[w])
    {
      int res = findValue(tree[u], tree[v], low, values[w] - 1);
      if (res >= 0)
        return res;
    }
    return values[w] < high ? findValue(tree[u], tree[v], values[w] + 1, high) : -1;
  }

  return findValue(tree[u], tree[v], low, high);
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int q;
  cin >> n >> q;
  for (int i = 0; i < n; i++)
  {
    cin >> values[i];
    values[i]--;
  }
  for (int i = 1; i < n; i++)
  {
    int x, y;
    cin >> x >> y;
    a[--x].push_back(--y);
    a[y].push_back(x);
  }

  mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
  for (int i = 0; i < n; i++)
    randomValues[i] = uniform_int_distribution<long long>(1, (1LL << 60) - 1)(rng);

  memset(p, -1, sizeof p);
  tree[0] = new SegmentTree(0, n - 1);
  tree[0] = tree[0]->add(values[0], randomValues[values[0]]);
  dfs(0);

  while (q--)
  {
    int u, v, l, r;
    cin >> u >> v >> l >> r;
    int ans = query(--u, --v, --l, --r);
    cout << (ans < 0 ? -1 : ans + 1) << '\n';
  }
}