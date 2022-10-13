#include <bits/stdc++.h>
using namespace std;

int n, timeIn[100100], timeOut[100100], dfsTime, depth[100100], isImportant[100100];
int num, q[100100], p[100100][20];
vector <int> a[100100], nodes;

void visit(int x)
{
  timeIn[x] = ++dfsTime;
  for (int y : a[x])
    if (y != p[x][0])
    {
      depth[y] = depth[x] + 1;
      p[y][0] = x;
      visit(y);
    }
  timeOut[x] = dfsTime;
}

bool compare(int u, int v)
{
  return timeIn[u] < timeIn[v];
}

int lca(int x, int y)
{
  if (depth[x] < depth[y])
    swap(x, y);
  for (int i = 16; i >= 0; i--)
    if (depth[x] - (1 << i) >= depth[y])
      x = p[x][i];

  if (x == y)
    return x;

  for (int i = 16; i >= 0; i--)
    if (p[x][i] != p[y][i])
    {
      x = p[x][i];
      y = p[y][i];
    }

  return p[x][0];
}

pair <int,int> dp()
{
  int x = nodes.back(), importantChild = 0, res = 0;
  nodes.pop_back();

  while (!nodes.empty())
  {
    int y = nodes.back();
    if (timeIn[y] > timeOut[x])
      break;
    auto u = dp();
    if (isImportant[x] && u.second) res++;
    else importantChild += u.second;
    res += u.first;
  }

  if (!isImportant[x])
  {
    if (importantChild >= 2)
      return {res + 1, 0};
    return {res, importantChild};
  }

  return {res, 1};
}

int query()
{
  int res = 0;

  for (int i = 0; i < num; ++i)
    if (isImportant[p[q[i]][0]])
      return -1;

  sort(q, q + num, compare);
  nodes = vector<int>(q, q + num);
  for (int i = 1; i < num; i++)
  {
    int x = q[i - 1], y = q[i], z = lca(x, y);
    if (x != z) 
      nodes.push_back(z);
  }
  sort(nodes.begin(), nodes.end(), compare);
  nodes.resize(unique(nodes.begin(), nodes.end()) - nodes.begin());
  reverse(nodes.begin(), nodes.end());
  return dp().first;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int Q, x, y;
  cin >> n;
  for (int i = 1; i < n; i++)
  {
    cin >> x >> y;
    a[x].push_back(y);
    a[y].push_back(x);
  }

  visit(1);
  for (int j = 0; j < 17; j++)
    for (int i = 1; i <= n; i++)
      p[i][j + 1] = p[p[i][j]][j];

  cin >> Q;
  while (Q--)
  {
    cin >> num;
    for (int i = 0; i < num; i++)
    {
      cin >> q[i];
      isImportant[q[i]] = 1;
    }
    cout << query() << endl;
    for (int i = 0; i < num; i++)
      isImportant[q[i]] = 0;
  }
}