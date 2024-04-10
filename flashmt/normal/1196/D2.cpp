#include <bits/stdc++.h>
using namespace std;

int n, k;
string a;

int calc(string pattern)
{
  int res = k;
  vector<int> cost(n + 1, 0);
  for (int i = 0; i < n; i++)
    cost[i + 1] = cost[i] + (a[i] != pattern[i % 3]);
  for (int i = k; i <= n; i++)
    res = min(res, cost[i] - cost[i - k]);
  return res;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int test;
  cin >> test;
  while (test--)
  {
    cin >> n >> k >> a;
    cout << min(min(calc("RGB"), calc("GBR")), calc("BRG")) << '\n';
  }
}