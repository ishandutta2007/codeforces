#include <bits/stdc++.h>
using namespace std;
const int BASE = int(1e9) + 7;

int d, n, v[2222];
vector <int> a[2222];

long long calc(int x, int par, int root)
{
  long long res = 1;
  for (int i = 0; i < int(a[x].size()); i++)
  {
    int y = a[x][i];
    if (y == par || v[y] < v[root] || v[y] > v[root] + d) continue;
    if (v[y] == v[root] && y < root) continue;
    res = res * (calc(y, x, root) + 1) % BASE;
  }
  return res;
}

int main()
{
  ios::sync_with_stdio(0);
  int x, y;
  cin >> d >> n;
  for (int i = 1; i <= n; i++) cin >> v[i];
  for (int i = 1; i < n; i++)
  {
    cin >> x >> y;
    a[x].push_back(y);
    a[y].push_back(x);
  }
  
  long long ans = 0;
  for (int i = 1; i <= n; i++)
    ans = (ans + calc(i, 0, i)) % BASE;
  cout << ans << endl;
}