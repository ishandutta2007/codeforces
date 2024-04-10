#include <bits/stdc++.h>
using namespace std;

vector<int> a[1010];
int from[1010];

void dfs(int x, int par, int root)
{
  from[x] = root;
  for (int y : a[x])
    if (y != par)
      dfs(y, x, root);
}

int ask(char c, int x)
{
  cout << c << ' ' << x << endl;
  cout.flush();
  int y;
  cin >> y;
  return y;
}

void answer(int ans)
{
  cout << "C " << ans << endl;
  cout.flush();
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int test;
  cin >> test;
  while (test--)
  {
    int n, k, isMine[1010] = {0}, isYours[1010] = {0};
    cin >> n;
    if (n < 0)
      break;

    for (int i = 1; i <= n; i++)
      a[i].clear();
    for (int i = 1; i < n; i++)
    {
      int x, y;
      cin >> x >> y;
      a[x].push_back(y);
      a[y].push_back(x);
    }
    cin >> k;
    while (k--)
    {
      int x;
      cin >> x;
      isMine[x] = 1;

    }
    cin >> k;
    int y;
    while (k--)
    {
      cin >> y;
      isYours[y] = 1;
    }

    for (int i = 1; i <= n; i++)
      if (isMine[i])
        for (int j : a[i])
          if (!isMine[j])
            dfs(j, i, i);

    int x = ask('B', y);
    if (isMine[x]) answer(x);
    else
    {
      int y = ask('A', from[x]);
      answer(isYours[y] ? from[x] : -1);
    }
  }
}