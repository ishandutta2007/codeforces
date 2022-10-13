#include <bits/stdc++.h>
using namespace std;

int n, sz[200200], minIdChild[200200], preDfs[200200], postDfs[200200], dfsTime, onBranch[200200];
vector<int> a[200200], b[200200];
long long ans[200200];

void visit(int x, int par)
{
  preDfs[x] = ++dfsTime;
  sz[x] = 1;
  minIdChild[x] = x;
  int u = -1, v = -1;
  for (int y : a[x])
    if (y != par)
    {
      visit(y, x);
      if (u < 0 || minIdChild[y] < minIdChild[u])
      {
        v = u;
        u = y;
      }
      else if (v < 0 || minIdChild[y] < minIdChild[v])
      {
        v = y;
      }
      minIdChild[x] = min(minIdChild[x], minIdChild[y]);
      sz[x] += sz[y];
    }

  if (u >= 0)
    b[x].push_back(u);
  if (v >= 0 && !x)
    b[x].push_back(v);
  postDfs[x] = dfsTime;
}

void calc(int x, int branch)
{
  if (x == minIdChild[x])
    onBranch[x] = branch;
  for (int y : b[x])
    calc(y, branch);
}

int isAncestor(int x, int y)
{
  return preDfs[x] <= preDfs[y] && postDfs[y] <= postDfs[x];
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--)
  {
    cin >> n;
    for (int i = 0; i <= n; i++)
    {
      a[i].clear();
      b[i].clear();
      ans[i] = 0;
      onBranch[i] = -1;
    }
    for (int i = 1; i < n; i++)
    {
      int x, y;
      cin >> x >> y;
      a[x].push_back(y);
      a[y].push_back(x);
    }

    dfsTime = 0;
    visit(0, -1);
    for (int x : a[0])
      ans[0] += sz[x] * (sz[x] - 1LL) / 2;

    for (int i = 0; i < b[0].size(); i++)
      calc(b[0][i], i);

    long long rem = n * (n - 1LL) / 2 - ans[0];
    int cnt[2] = {0, n - sz[b[0][0]]}, last[2] = {-1, -1};
    for (int x = 1; x <= n; x++)
      if (onBranch[x] < 0)
      {
        int isGood = 0;
        for (int i = 0; i < 2; i++)
          if (last[i] >= 0 && isAncestor(x, last[i]))
            isGood = 1;
        if (!isGood)
        {
          ans[x] = rem;
          break;
        }
      }
      else
      {
        cnt[onBranch[x]] = sz[x];
        last[onBranch[x]] = x;
        ans[x] = rem - 1LL * cnt[0] * cnt[1];
        rem -= ans[x];
      }

    for (int i = 0; i <= n; i++)
      cout << ans[i] << " \n"[i == n];
  }
}