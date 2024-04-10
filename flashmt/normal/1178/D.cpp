#include <bits/stdc++.h>
using namespace std;

int isPrime(int x)
{
  for (int i = 2; i * i <= x; i++)
    if (x % i == 0)
      return 0;
  return 1;
}

int main()
{
  int n, extra = 0;
  vector<int> groups[1010];
  cin >> n;
  while (!isPrime(n + extra))
    extra++;
  for (int i = 0; i < n; i++)
    groups[min(i / 3, n / 3 - 1)].push_back(i);

  vector<pair<int, int>> edges;
  for (int i = 0; i < n / 3; i++)
  {
    for (int j = 1; j < groups[i].size(); j++)
      edges.push_back({groups[i][j - 1], groups[i][j]});
    edges.push_back({groups[i][0], groups[i].back()});
  }

  vector<int> order;
  for (int j = 0; j < 3; j++)
    for (int i = 0; i < n / 3; i++)
      order.push_back(i * 3 + j);

  if (n == 4) edges.push_back({0, 2});
  else
  {
    assert(order.size() >= extra * 2);
    for (int i = 0; i < extra; i++)
      edges.push_back({order[i * 2], order[i * 2 + 1]});
  }

  cout << edges.size() << endl;
  for (auto e : edges)
    cout << e.first + 1 << ' ' << e.second + 1 << endl;
}