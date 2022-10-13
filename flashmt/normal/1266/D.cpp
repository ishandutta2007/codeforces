#include <bits/stdc++.h>
using namespace std;

int n, m;
long long has[100100];

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  while (m--)
  {
    int x, y, z;
    cin >> x >> y >> z;
    has[y] += z;
    has[x] -= z;
  }

  vector<int> pos, neg;
  for (int i = 1; i <= n; i++)
    if (has[i] > 0) pos.push_back(i);
    else if (has[i] < 0)
    {
      has[i] = -has[i];
      neg.push_back(i);
    }
  vector<tuple<int, int, long long>> debts;
  for (int i = 0, j = 0; i < pos.size() && j < neg.size();)
  {
    int x = pos[i], y = neg[j];
    long long pay = min(has[x], has[y]);
    debts.push_back({y, x, pay});
    has[x] -= pay;
    has[y] -= pay;
    if (!has[x])
      i++;
    if (!has[y])
      j++;
  }

  cout << debts.size() << '\n';
  for (auto [x, y, pay] : debts)
    cout << x << ' ' << y << ' ' << pay << '\n';
}