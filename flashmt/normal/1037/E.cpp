#include <bits/stdc++.h>
using namespace std;

int n, k, groupSize, friends[200200], removed[200200];
set<int> a[200200];
queue<int> q;

void update(int x)
{
  if (!removed[x])
    if (--friends[x] < k)
    {
      removed[x] = 1;
      groupSize--;
      q.push(x);
    }
}

void processQueue()
{
  while (!q.empty())
  {
    int x = q.front();
    q.pop();
    for (int y : a[x])
      update(y);
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int m;
  vector<pair<int, int>> edges;
  cin >> n >> m >> k;
  for (int i = 0; i < m; i++)
  {
    int x, y;
    cin >> x >> y;
    edges.push_back({--x, --y});
    a[x].insert(y);
    a[y].insert(x);
    friends[x]++;
    friends[y]++;
  }

  groupSize = n;
  for (int i = 0; i < n; i++)
    if (friends[i] < k)
    {
      removed[i] = 1;
      groupSize--;
      q.push(i);
    }

  processQueue();
  vector<int> ans = {groupSize};
  for (int i = m - 1; i; i--)
  {
    auto [x, y] = edges[i];
    a[x].erase(y);
    a[y].erase(x);
    if (!removed[x] && !removed[y])
    {
      update(x);
      update(y);
      processQueue();
    }
    ans.push_back(groupSize);
  }

  reverse(ans.begin(), ans.end());
  for (int x : ans)
    cout << x << '\n';
}