#include <bits/stdc++.h>
using namespace std;
const long long oo = 1LL << 60;

int v[200200], n;
long long f[200200][2], ans[200200];
vector <int> a[200200];

void calc(int x)
{
  f[x][1] = -oo;
  for (auto y : a[x])
  {
    calc(y);
    long long g[2] = {-oo, -oo};
    for (int i = 0; i < 2; i++)
      for (int j = 0; j < 2; j++)
        g[i ^ j] = max(g[i ^ j], f[x][i] + f[y][j]);
    for (int i = 0; i < 2; i++)
      f[x][i] = g[i];
    ans[x] += ans[y];
  }
  
  f[x][1] = max(f[x][1], f[x][0] + v[x]);
  ans[x] = max(ans[x], f[x][0] + v[x]);
}

int main()
{
  ios::sync_with_stdio(0);
  int p;
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    cin >> p >> v[i];
    if (p > 0) a[p].push_back(i);
  }
  
  calc(1);
  cout << ans[1] << endl;
}