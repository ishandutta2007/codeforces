#include <bits/stdc++.h>
using namespace std;

int n, a[2222], lights[2222], ans;

void solve(int x)
{
  if (x * 2 >= 1 << (n + 1)) return;
  solve(x * 2);
  solve(x * 2 + 1);
  lights[x * 2] += a[x * 2];
  lights[x * 2 + 1] += a[x * 2 + 1];
  lights[x] = max(lights[x * 2], lights[x * 2 + 1]);
  ans += lights[x] * 2 - lights[x * 2] - lights[x * 2 + 1];
}

int main()
{
  ios::sync_with_stdio(0);
  cin >> n;
  for (int i = 2; i < 1 << (n + 1); i++) cin >> a[i];
  solve(1);
  cout << ans << endl;
}