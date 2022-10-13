#include <bits/stdc++.h>
using namespace std;

int n, p, t[100100], tree[100100];
queue<int> q;
set<int> waiting;
long long curT, ans[100100];

int get(int x)
{
  for (int i = x; i; i -= i & -i)
    if (tree[i])
      return 1;
  return 0;
}

void add(int x, int v)
{
  for (int i = x; i <= 100000; i += i & -i)
    tree[i] += v;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  vector<pair<int, int>> a;
  cin >> n >> p;
  for (int i = 0; i < n; i++)
  {
    cin >> t[i];
    a.push_back({t[i], i});
  }

  sort(a.begin(), a.end());

  int i = 0;
  while (1)
    if (!q.empty()) // queue is non-empty
    {
      int x = q.front();
      q.pop();
      curT += p;
      ans[x] = curT;

      while (i < n && a[i].first < curT) // before x is popped
      {
        int y = a[i++].second;
        if (get(y)) waiting.insert(y);
        else
        {
          q.push(y);
          add(y + 1, 1);
        }
      }

      add(x + 1, -1);
      while (i < n && a[i].first == curT) // at the exact time x is popped
        waiting.insert(a[i++].second);

      if (waiting.empty())
        continue;

      // check if we can push a waiting one to queue
      int y = *waiting.begin();
      if (get(y))
      {
        auto it = waiting.lower_bound(x);
        if (it == waiting.end())
          continue;
        y = *it;
        if (get(y))
          continue;
      }
      q.push(y);
      add(y + 1, 1);
      waiting.erase(y);
    }
    else // queue is empty, enqueue next one
    {
      if (i == n)
        break;
      int x = a[i++].second;
      q.push(x);
      curT = t[x];
      add(x + 1, 1);
    }

  for (int i = 0; i < n; i++)
    cout << ans[i] << " \n"[i == n - 1];
}