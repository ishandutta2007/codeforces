#include <bits/stdc++.h>
using namespace std;

int n, v[200200], dfsTime, timeIn[200200], timeOut[200200], tree[200200], p[200200][20], depth[200200];
vector<int> a[200200];

void add(int x, int v)
{
  for (int i = x; i <= n; i += i & -i)
    tree[i] += v;
}

int get(int x)
{
  int res = 0;
  for (int i = x; i; i -= i & -i)
    res += tree[i];
  return res;
}

void visit(int x)
{
  timeIn[x] = ++dfsTime;
  for (int y : a[x])
    if (y != p[x][0])
    {
      p[y][0] = x;
      depth[y] = depth[x] + 1;
      visit(y);
    }
  timeOut[x] = dfsTime;
}

int isAncestor(int x, int y)
{
  return timeIn[x] <= timeIn[y] && timeOut[y] <= timeOut[x];
}

int getKthAncestor(int x, int k)
{
  for (int i = 0; i < 18; i++)
    if (k >> i & 1)
      x = p[x][i];
  return x;
}

void noAnswer()
{
  cout << 0 << endl;
  exit(0);
}

void check(int x, int y)
{
  add(timeIn[y], 1);
  add(timeOut[y] + 1, -1);
  if (isAncestor(x, y))
  {
    int dist = depth[y] - depth[x];
    if (dist == 1) noAnswer();
    else
    {
      int u = getKthAncestor(y, dist - 1);
      add(1, 1);
      add(timeIn[u], -1);
      add(timeOut[u] + 1, 1);
    }
  }
  else
  {
    add(timeIn[x], 1);
    add(timeOut[x] + 1, -1);
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> v[i];
  for (int i = 1; i < n; i++)
  {
    int x, y;
    cin >> x >> y;
    a[x].push_back(y);
    a[y].push_back(x);
  }

  visit(1);
  for (int i = 0; i < 18; i++)
    for (int x = 1; x <= n; x++)
      p[x][i + 1] = p[p[x][i]][i];

  vector<int> order;
  for (int i = 1; i <= n; i++)
    order.push_back(i);
  sort(order.begin(), order.end(), [](int x, int y) { return make_pair(v[x], timeIn[x]) < make_pair(v[y], timeIn[y]); });

  for (int i = 0; i < n;)
  {
    int j = i;
    vector<int> nodes;
    while (j < n && v[order[j]] == v[order[i]])
      nodes.push_back(order[j++]);
    i = j;

    if (nodes.size() == 1)
      continue;

    int x = nodes[0], y = nodes[1];
    check(x, y);

    for (int j = 2; j < nodes.size(); j++)
    {
      int z = nodes[j], prev = nodes[j - 1];
      if (isAncestor(prev, z))
        noAnswer();
      if (isAncestor(x, y) && !isAncestor(x, z))
        noAnswer();
      check(x, z);
    }
  }

  int ans = 0;
  for (int i = 1; i <= n; i++)
    ans += !get(i);
  cout << ans << endl;
}