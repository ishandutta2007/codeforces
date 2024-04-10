#include <bits/stdc++.h>
using namespace std;
const int N = 200200;

int n, mask[N];
vector<int> a[N];

void reset()
{
  for (int i = 0; i < n; i++)
  {
    a[i].clear();
    mask[i] = 0;
  }
}

void dfs(int x, int par, int blocked, int curMask)
{
  mask[x] |= curMask;
  for (int y : a[x])
    if (y != par && y != blocked && !(mask[y] & curMask))
      dfs(y, x, blocked, curMask);
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int test;
  cin >> test;
  while (test--)
  {
    int m, s, t;
    cin >> n >> m >> s >> t;
    s--;
    t--;
    reset();
    while (m--)
    {
      int x, y;
      cin >> x >> y;
      a[--x].push_back(--y);
      a[y].push_back(x);
    }

    dfs(s, -1, t, 1);
    dfs(t, -1, s, 2);
    int passS = 0, passT = 0;
    for (int i = 0; i < n; i++)
      if (i != s && i != t)
      {
        if (mask[i] == 1) passS++;
        else if (mask[i] == 2) passT++;
      }

    cout << 1LL * passS * passT << '\n';
  }
}