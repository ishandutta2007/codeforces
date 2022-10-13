#include <bits/stdc++.h>
using namespace std;
const int BASE = int(1e9) + 7;
const long long oo = 1LL << 60;

long long p2[200200], value, r[200200], l[200200];
int n, k, a[200200], good[200200];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;
  p2[0] = 1;
  for (int i = 0; i <= n; i++)
  {
    cin >> a[i];
    value += a[i] * p2[i];
    value %= BASE;
    p2[i + 1] = p2[i] * 2 % BASE;
  }

  good[n] = 1;
  r[n] = a[n];
  for (int i = n - 1; i >= 0; i--)
  {
    r[i] = a[i] + r[i + 1] * 2;
    if (llabs(r[i]) > oo)
      break;
    good[i] = 1;
  }

  int ans = 0;
  l[0] = a[0];
  if (good[0] && llabs(r[0] - a[0]) <= k)
    ans++;

  for (int i = 1; i <= n; i++)
  {
    if (abs(l[i - 1]) % 2)
      break;
    if (i == n && !l[i - 1])
      break;
    l[i] = a[i] + l[i - 1] / 2;
    if (good[i])
    {
      long long need = r[i] + l[i - 1] / 2 - a[i];
      if (llabs(need) <= k)
        ans++;
    }
  }

  cout << ans << endl;
}