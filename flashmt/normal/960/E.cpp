#include <bits/stdc++.h>
using namespace std;
const int BASE = 1e9 + 7;

int n, v[200200];
vector<int> a[200200];
long long f[200200][2], cnt[200200][2], ans;

void visit(int x, int par)
{
  ans = (ans + v[x]) % BASE;
  f[x][1] = v[x];
  cnt[x][1] = 1;
  for (int y : a[x])
    if (y != par)
    {
      visit(y, x);
      for (int i = 0; i < 2; i++)
      {
        long long cost = (f[x][i] * cnt[y][i ^ 1] + f[y][i ^ 1] * cnt[x][i]) % BASE;
        ans = (ans + cost * 2) % BASE;
      }

      for (int i = 0; i < 2; i++)
      {
        long long toAdd = cnt[y][i ^ 1] * v[x] % BASE;
        if (!i)
          toAdd = BASE - toAdd;
        f[x][i] = (f[x][i] + f[y][i ^ 1] + toAdd) % BASE;
        cnt[x][i] = (cnt[x][i] + cnt[y][i ^ 1]) % BASE;
      }
    }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> v[i];
    if (v[i] < 0)
      v[i] += BASE;
  }
  for (int i = 1; i < n; i++)
  {
    int x, y;
    cin >> x >> y;
    a[--x].push_back(--y);
    a[y].push_back(x);
  }
  visit(0, -1);
  cout << ans << endl;
}