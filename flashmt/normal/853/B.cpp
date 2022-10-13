#include <bits/stdc++.h>
using namespace std;
const int D = 1000000, oo = 27081993;
const long long ooo = 1LL << 60;

int n, k, curCost[100100];
vector < pair<int, int> > arrive[1000100], depart[1000100];
long long arriveCost[1000100];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(NULL);

  int m, d, x, y, c;
  cin >> n >> m >> k;
  while (m--)
  {
    cin >> d >> x >> y >> c;
    if (!x) depart[d].push_back({y, c});
    else arrive[d].push_back({x, c});
  }

  int cnt = 0;
  long long sumCost = 1LL * n * oo;
  for (int i = 1; i <= n; i++)
    curCost[i] = oo;

  for (int i = 1; i <= D; i++)
  {
    for (auto u : arrive[i])
    {
      int x = u.first, c = u.second;
      if (curCost[x] == oo)
        cnt++;
      if (c < curCost[x])
      {
        sumCost += c - curCost[x];
        curCost[x] = c;
      }
    }

    if (cnt == n) arriveCost[i] = sumCost;
    else arriveCost[i] = ooo;
  }

  cnt = 0;
  sumCost = 1LL * n * oo;
  for (int i = 1; i <= n; i++)
    curCost[i] = oo;

  long long ans = ooo;
  for (int i = D; i >= k + 2; i--)
  {
    for (auto u : depart[i])
    {
      int x = u.first, c = u.second;
      if (curCost[x] == oo)
        cnt++;
      if (c < curCost[x])
      {
        sumCost += c - curCost[x];
        curCost[x] = c;
      }
    }

    if (cnt == n)
      ans = min(ans, sumCost + arriveCost[i - k - 1]);
  }

  if (ans == ooo)
    ans = -1;
  cout << ans << endl;
}