#include <bits/stdc++.h>
using namespace std;
const int K = 1300;

int n, numPath[100100], longest[100100], secondLongest[100100];
vector<int> a[100100], nodes;

void dfs(int x, int par)
{
  int idPar = -1;
  for (int i = 0; i < a[x].size(); i++)
    if (a[x][i] == par) idPar = i;
    else dfs(a[x][i], x);
  if (idPar >= 0)
    a[x].erase(a[x].begin() + idPar);
  nodes.push_back(x);
}

inline int solve(int k)
{
  for (int x : nodes)
  {
    numPath[x] = longest[x] = secondLongest[x] = 0;
    for (int y : a[x])
    {
      numPath[x] += numPath[y];
      if (longest[y] > longest[x])
      {
        secondLongest[x] = longest[x];
        longest[x] = longest[y];
      }
      else if (longest[y] > secondLongest[x]) secondLongest[x] = longest[y];
    }

    if (longest[x] + secondLongest[x] + 1 >= k)
    {
      numPath[x]++;
      longest[x] = 0;
    }
    else longest[x]++;
  }

  return numPath[1];
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 1; i < n; i++)
  {
    int x, y;
    cin >> x >> y;
    a[x].push_back(y);
    a[y].push_back(x);
  }

  dfs(1, 0);

  cout << n << '\n';
  for (int k = 2; k <= min(K, n); k++)
    cout << solve(k) << '\n';

  for (int k = min(K, n) + 1; k <= n;)
  {
    int curAns = solve(k), low = k + 1, high = n, newK = n + 1;
    while (low <= high)
    {
      int mid = (low + high) / 2;
      if (solve(mid) < curAns)
      {
        newK = mid;
        high = mid - 1;
      }
      else low = mid + 1;
    }

    for (int i = k; i < newK; i++)
      cout << curAns << '\n';
    k = newK;
  }
}