#include <bits/stdc++.h>
using namespace std;
const long long oo = 1LL << 60;

int main()
{
  int n, k, l[2020], r[2020], a[2020];
  cin >> n >> k;
  for (int i = 0; i < n; i++)
    cin >> l[i] >> r[i] >> a[i];

  vector<long long> f(n + 1, oo);
  f[0] = 0;
  long long ans = oo;
  for (int i = 0; i < n; i++)
  {
    int bullets = k;
    for (int j = i; j < n; j++)
    {
      int reload = (a[j] - bullets + k - 1) / k;
      int curTime = l[j] + reload;
      if (curTime > r[j])
        break;

      bullets = reload * k + bullets - a[j];
      if (j + 1 == n) ans = min(ans, f[i]);
      else if (curTime < l[j + 1]) f[j + 1] = min(f[j + 1], f[i] + bullets);
    }
  }

  long long sumA = accumulate(a, a + n, 0LL);

  cout << (ans == oo ? -1 : ans + sumA) << endl;
}