#include <bits/stdc++.h>
using namespace std;

int w[100100], d[100100], sz[100100];
vector<int> a[100100];
map<int, long long> *f[100100];

void visit(int x)
{
  f[x] = new map<int, long long>();
  for (int y : a[x])
  {
    visit(y);
    if (f[y]->size() > f[x]->size())
      swap(f[x], f[y]);
    for (auto u : *f[y])
      (*f[x])[u.first] += u.second;
  }

  if (!d[x])
    return;

  int currentW = w[x];
  while (currentW)
  {
    auto u = f[x]->upper_bound(d[x]);
    if (u == f[x]->end())
      break;
    if (u->second >= currentW)
    {
      u->second -= currentW;
      break;
    }
    currentW -= u->second;
    f[x]->erase(u);
  }
  (*f[x])[d[x]] += w[x];
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m, k, par;
  cin >> n >> m >> k;
  for (int i = 2; i <= n; i++)
  {
    cin >> par;
    a[par].push_back(i);
  }

  int x;
  while (m--)
  {
    cin >> x;
    cin >> d[x] >> w[x];
  }

  visit(1);
  long long ans = 0;
  for (auto u : *f[1])
    ans += u.second;
  cout << ans << endl;
}