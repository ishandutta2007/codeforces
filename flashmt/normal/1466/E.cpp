#include <bits/stdc++.h>
using namespace std;
const int BASE = 1e9 + 7;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  long long p2[66];
  p2[0] = 1;
  for (int i = 1; i <= 60; i++)
    p2[i] = p2[i - 1] * 2 % BASE;

  while (test--)
  {
    int n, cnt[66] = {0};
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
      for (int j = 0; j < 60; j++)
        if (a[i] >> j & 1)
          cnt[j]++;
    }

    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
      long long sumOr = 0;
      for (int j = 0; j < 60; j++)
        if (a[i] >> j & 1) sumOr = (sumOr + p2[j] * n) % BASE;
        else sumOr = (sumOr + p2[j] * cnt[j]) % BASE;

      for (int j = 0; j < 60; j++)
        if (a[i] >> j & 1)
          ans = (ans + sumOr * cnt[j] % BASE * p2[j]) % BASE;
    }

    cout << ans << '\n';
  }
}