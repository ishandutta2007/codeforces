#include <bits/stdc++.h>
using namespace std;
const int N = 200200, K = 160;

struct Hull
{
  long long a[K * 2], b[K * 2], curX;
  double x[K * 2];
  int head, tail;

  Hull(): head(0), tail(-1), curX(0) {}

  void add(long long aNew, long long bNew)
  {
    double xNew = -1e18;
    while (head <= tail)
    {
      if (aNew == a[tail])
      {
        if (bNew <= b[tail])
          return;
        tail--;
        continue;
      }
      xNew = 1.0 * (b[tail] - bNew) / (aNew - a[tail]);
      if (head == tail || xNew >= x[tail])
        break;
      tail--;
    }
    a[++tail] = aNew;
    b[tail] = bNew;
    x[tail] = xNew;
  }

  long long get(int addX)
  {
    curX += addX;
    while (head < tail && x[head + 1] < curX)
      head++;
    return a[head] * curX + b[head];
  }
};

int n;
vector<int> adj[N], order;
vector<pair<int, int>> sortedBlocks[N];
int dfsTime, timeIn[N], timeOut[N];
vector<Hull> hulls;
long long a[N], b[N];

void visit(int x, int par)
{
  order.push_back(x);
  timeIn[x] = dfsTime++;
  for (int y : adj[x])
    if (y != par)
    {
      a[y] += a[x];
      b[y] += b[x];
      visit(y, x);
    }
  swap(a[x], b[x]);
  b[x] *= a[x];
  timeOut[x] = dfsTime;
}

bool compare(pair<int, int> u, pair<int, int> v)
{
  return a[u.first] * u.second < a[v.first] * v.second;
}

void initBlock(int id)
{
  int from = id * K, to = min(n, (id + 1) * K);
  for (int i = from; i < to; i++)
    for (int j = -1; j <= 1; j += 2)
      sortedBlocks[id].push_back({order[i], j});
  sort(sortedBlocks[id].begin(), sortedBlocks[id].end(), compare);
}

Hull buildHull(int id)
{
  Hull hull;
  for (auto u : sortedBlocks[id])
    hull.add(a[u.first] * u.second, b[u.first] * u.second);
  return hull;
}

void update(int v, int x)
{
  int from = timeIn[v], firstBlock = from / K;
  int to = timeOut[v], lastBlock = (to - 1) / K;

  for (int i = lastBlock * K; i < min(n, (lastBlock + 1) * K); i++)
  {
    if (from <= i && i < to)
      b[order[i]] += a[order[i]] * x;
    b[order[i]] += a[order[i]] * hulls[lastBlock].curX;
  }
  hulls[lastBlock] = buildHull(lastBlock);

  if (firstBlock != lastBlock)
  {
    for (int i = firstBlock * K; i < (firstBlock + 1) * K; i++)
    {
      if (from <= i && i < to)
        b[order[i]] += a[order[i]] * x;
      b[order[i]] += a[order[i]] * hulls[firstBlock].curX;
    }
    hulls[firstBlock] = buildHull(firstBlock);
  }

  for (int i = firstBlock + 1; i < lastBlock; i++)
    hulls[i].get(x);
}

long long get(int v)
{
  long long res = 0;
  int from = timeIn[v], firstBlock = from / K;
  int to = timeOut[v], lastBlock = (to - 1) / K;
  for (int i = from; i < min(to, min(n, (firstBlock + 1) * K)); i++)
    res = max(res, llabs(a[order[i]] * hulls[firstBlock].curX + b[order[i]]));
  for (int i = max(from, lastBlock * K); i < to; i++)
    res = max(res, llabs(a[order[i]] * hulls[lastBlock].curX + b[order[i]]));
  for (int i = firstBlock + 1; i < lastBlock; i++)
    res = max(res, hulls[i].get(0));
  return res;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int q, x, query, v;
  cin >> n >> q;
  for (int i = 1; i < n; i++)
  {
    cin >> x;
    adj[i].push_back(--x);
    adj[x].push_back(i);
  }

  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < n; i++)
    cin >> b[i];

  dfsTime = 0;
  visit(0, -1);

  int numBlock = (n + K - 1) / K;
  for (int i = 0; i < numBlock; i++)
  {
    initBlock(i);
    hulls.push_back(buildHull(i));
  }

  while (q--)
  {
    cin >> query >> v;
    if (query == 1)
    {
      cin >> x;
      update(--v, x);
    }
    else cout << get(--v) << '\n';
  }
}