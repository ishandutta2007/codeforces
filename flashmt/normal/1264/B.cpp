#include <bits/stdc++.h>
using namespace std;

int n, a, b, c, d, ans[100100];

void check()
{
  for (int i = 1; i < n; i++)
    if (abs(ans[i] - ans[i - 1]) != 1)
      return;

  cout << "YES\n";
  for (int i = 0; i < n; i++)
    cout << ans[i] << " \n"[i == n - 1];
  exit(0);
}

void solve02()
{
  for (int i = 0; i < a + c; i++)
    ans[i * 2] = i < a ? 0 : 2;
  for (int i = 0; i < b + d; i++)
    ans[i * 2 + 1] = i < b ? 1 : 3;
  check();
}

void solve13()
{
  for (int i = 0; i < b + d; i++)
    ans[i * 2] = i < b ? 1 : 3;
  for (int i = 0; i < a + c; i++)
    ans[i * 2 + 1] = i < a ? 0 : 2;
  check();
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> a >> b >> c >> d;
  n = a + b + c + d;
  if (n % 2 == 0)
  {
    if (a + c == b + d)
    {
      solve02();
      solve13();
    }
  }
  else
  {
    if (a + c == b + d + 1) solve02();
    else if (a + c + 1 == b + d) solve13();
  }

  cout << "NO" << endl;
}