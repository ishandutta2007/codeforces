#include <bits/stdc++.h>
using namespace std;

int n, k, p[300300], after[300300], before[300300], chainId[300300], seen[300300];
vector<int> chains[300300], preReqOf[300300];
set<int> chainPrereq[300300];

void noAnswer()
{
  cout << 0 << endl;
  exit(0);
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;
  for (int i = 1; i <= n; i++)
    cin >> p[i];

  for (int i = 0; i < k; i++)
  {
    int x, y;
    cin >> x >> y;
    if (before[y] || after[x])
      noAnswer();
    before[y] = x;
    after[x] = y;
  }

  for (int i = 1; i <= n; i++)
    if (!before[i])
    {
      int x = i;
      while (x)
      {
        chainId[x] = i;
        chains[i].push_back(x);
        x = after[x];
      }
      for (int x : chains[i])
        if (p[x] && chainId[p[x]] != i)
        {
          chainPrereq[i].insert(p[x]);
          preReqOf[p[x]].push_back(i);
        }
    }

  queue<int> q;
  for (int i = 1; i <= n; i++)
    if (!before[i] && chainPrereq[i].empty())
      q.push(i);

  vector<int> ans;
  while (!q.empty())
  {
    int i = q.front();
    q.pop();
    for (int x : chains[i])
    {
      if (p[x] && !seen[p[x]])
        noAnswer();
      ans.push_back(x);
      seen[x] = 1;
      for (int y : preReqOf[x])
        if (!chainPrereq[chainId[y]].empty())
        {
          chainPrereq[chainId[y]].erase(x);
          if (chainPrereq[chainId[y]].empty())
            q.push(chainId[y]);
        }
    }
  }

  if (ans.size() < n) noAnswer();
  else
    for (int x : ans)
      cout << x << ' ';
}