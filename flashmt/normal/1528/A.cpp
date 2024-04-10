#include <bits/stdc++.h>
using namespace std;
const long long oo = 1LL << 60;

int n, l[100100], r[100100];
vector<int> a[100100];
long long f[100100][2];

void visit(int x, int par)
{
  f[x][0] = f[x][1] = 0;
  for (int y : a[x])
    if (y != par)
    {
      visit(y, x);
      f[x][0] += max(f[y][0] + abs(l[x] - l[y]), f[y][1] + abs(l[x] - r[y]));
      f[x][1] += max(f[y][0] + abs(r[x] - l[y]), f[y][1] + abs(r[x] - r[y]));
    }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--)
  {
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
      a[i].clear();
      cin >> l[i] >> r[i];
    }
    for (int i = 1; i < n; i++)
    {
      int x, y;
      cin >> x >> y;
      a[x].push_back(y);
      a[y].push_back(x);
    }

    visit(1, 0);
    cout << max(f[1][0], f[1][1]) << '\n';
  }
}