#include <bits/stdc++.h>
using namespace std;

int askCrossProduct(int i, int j, int k)
{
  cout << 2 << ' ' << i << ' ' << j << ' ' << k << endl;
  cout.flush();
  int sign;
  cin >> sign;
  return sign;
}

long long askArea(int i, int j, int k)
{
  cout << 1 << ' ' << i << ' ' << j << ' ' << k << endl;
  cout.flush();
  long long area;
  cin >> area;
  return area;
}

vector<int> solve(vector<int> l, int top, int bottom)
{
  if (l.empty())
    return vector<int>();
  vector<pair<long long, int>> areas;
  for (int x : l)
    areas.push_back({askArea(top, bottom, x), x});
  sort(areas.begin(), areas.end(), greater<pair<long long, int>>());

  auto [_, u] = areas[0];
  vector<int> upper, lower;
  for (int i = 1; i < areas.size(); i++)
  {
    auto [_, v] = areas[i];
    int sign = askCrossProduct(top, v, u);
    if (sign > 0) upper.push_back(v);
    else lower.push_back(v);
  }

  vector<int> res;
  reverse(upper.begin(), upper.end());
  for (int x : upper)
    res.push_back(x);
  res.push_back(u);
  for (int x : lower)
    res.push_back(x);
  return res;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  vector<int> l, r;
  for (int i = 3; i <= n; i++)
  {
    int sign = askCrossProduct(1, 2, i);
    if (sign < 0) l.push_back(i);
    else r.push_back(i);
  }

  auto sortedL = solve(l, 1, 2);
  auto sortedR = solve(r, 2, 1);
  cout << 0 << ' ' << 1 << ' ';
  for (int x : sortedL)
    cout << x << ' ';
  cout << 2  << ' ';
  for (int x : sortedR)
    cout << x << ' ';
}