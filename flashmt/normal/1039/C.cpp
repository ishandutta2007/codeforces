#include <bits/stdc++.h>
using namespace std;
const int BASE = 1e9 + 7;

int visited[500500], flag[500500];
vector<int> a[500500];

void dfs(int x)
{
  visited[x] = 1;
  for (int y : a[x])
    if (!visited[y])
      dfs(y);
}

void reset(int x, int i)
{
  flag[x] = i;
  a[x].clear();
  visited[x] = 0;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m, k;
  long long c[500500];
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++)
    cin >> c[i];

  vector<tuple<long long, int, int>> candidates;
  for (int i = 0; i < m; i++)
  {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    candidates.push_back({c[x] ^ c[y], x, y});
  }

  long long p2[500500] = {1};
  for (int i = 1; i <= 500000; i++)
    p2[i] = p2[i - 1] * 2 % BASE;

  sort(candidates.begin(), candidates.end());
  memset(flag, -1, sizeof flag);
  long long ans = 0;
  int numValue = 0;
  for (int i = 0; i < m;)
  {
    int j = i;
    long long curVal = get<0>(candidates[i]);
    vector<int> active;
    while (j < m)
    {
      auto [val, x, y] = candidates[j];
      if (val != curVal)
        break;
      j++;

      if (flag[x] != i)
      {
        reset(x, i);
        active.push_back(x);
      }
      a[x].push_back(y);

      if (flag[y] != i)
      {
        reset(y, i);
        active.push_back(y);
      }
      a[y].push_back(x);
    }

    int numComponent = 0;
    for (int x : active)
      if (!visited[x])
      {
        dfs(x);
        numComponent++;
      }

    ans = (ans + p2[numComponent] * p2[n - active.size()]) % BASE;
    numValue++;
    i = j;
  }

  ans = (ans + (p2[k] - numValue + BASE) * p2[n]) % BASE;
  cout << ans << endl;
}