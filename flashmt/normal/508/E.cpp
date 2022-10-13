#include <bits/stdc++.h>
using namespace std;

int n, f[666][666], l[666], r[666], tr[666][666];
char ans[2222];

int dp(int x, int y)
{
  if (x == y) return !l[x];
  int &res = f[x][y];
  if (res >= 0) return res;
  
  if (l[x] <= y - x && y - x <= r[x] && dp(x + 1, y)) return res = 1;
  for (int i = x; i < y; i++)
    if (dp(x, i) && dp(i + 1, y))
    {
      tr[x][y] = i;
      return res = 1;
    }
  
  return res = 0;
}

void trace(int x, int y, int l, int r)
{
  if (!tr[x][y])
  {
    ans[l] = '(';
    ans[r] = ')';
    if (x == y) return;
    trace(x + 1, y, l + 1, r - 1);
  }
  else
  {
    int i = tr[x][y];
    trace(x, i, l, l + (i - x + 1) * 2 - 1);
    trace(i + 1, y, l + (i - x + 1) * 2, r);
  }
}

int main()
{
  ios::sync_with_stdio(0);
  
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    cin >> l[i] >> r[i];
    if (l[i] == r[i] && l[i] % 2 == 0)
    {
      cout << "IMPOSSIBLE\n";
      return 0;
    }
    
    l[i] /= 2;
    r[i] = (r[i] - 1) / 2;
  }
  
  memset(f, -1, sizeof f);
  if (!dp(1, n)) cout << "IMPOSSIBLE\n";
  else 
  {
    trace(1, n, 1, n * 2);
    for (int i = 1; i <= n * 2; i++) cout << ans[i];
    cout << endl;
  }
}