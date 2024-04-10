#include <bits/stdc++.h>
using namespace std;
const int N = 3e5;

int n, ds[N], par[N], depth[N];
vector<int> a[N];

int get(int x)
{
  return x == ds[x] ? x : ds[x] = get(ds[x]);
}

void dfs(int x)
{
  for (int y : a[x])
    if (y != par[x])
    {
      depth[y] = depth[x] + 1;
      par[y] = x;
      dfs(y);
    }
}

pair<int, int> findCycle(int x, int y)
{
  int minNode = min(x, y), maxNode = max(x, y);
  while (x != y)
  {
    int dx = depth[x], dy = depth[y];
    if (dx >= dy)
      x = par[x];
    if (dy >= dx)
      y = par[y];
    minNode = min({minNode, x, y});
    maxNode = max({maxNode, x, y});
  }
  return {minNode, maxNode};
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int m;
  cin >> n >> m;
  iota(ds, ds + n, 0);
  vector<pair<int, int>> nonTreeEdges;
  while (m--)
  {
    int x, y;
    cin >> x >> y;
    int dx = get(--x), dy = get(--y);
    if (dx == dy) nonTreeEdges.push_back({x, y});
    else
    {
      a[x].push_back(y);
      a[y].push_back(x);
      ds[dy] = dx;
    }
  }

  fill(par, par + n, -1);
  for (int i = 0; i < n; i++)
    if (par[i] < 0)
      dfs(i);

  vector<pair<int, int>> cycles;
  for (auto [x, y] : nonTreeEdges)
    cycles.push_back(findCycle(x, y));

  vector<int> maxR(n, n - 1);
  for (auto [l, r] : cycles)
    maxR[l] = min(maxR[l], r - 1);
  for (int i = n - 2; i >= 0; i--)
    maxR[i] = min(maxR[i], maxR[i + 1]);

  vector<long long> sum(n + 1);
  for (int i = 0; i < n; i++)
    sum[i + 1] = sum[i] + maxR[i];

  int q;
  cin >> q;
  while (q--)
  {
    int l, r;
    cin >> l >> r;
    l--; r--;
    int bound = upper_bound(begin(maxR), end(maxR), r) - begin(maxR);
    long long ans;
    if (bound <= l) ans = (r - l + 1LL) * r;
    else if (bound <= r) ans = sum[bound] - sum[l] + (r - bound + 1LL) * r;
    else ans = sum[r + 1] - sum[l];
    ans -= (r + l - 2LL) * (r - l + 1) / 2;
    cout << ans << '\n';
  }
}