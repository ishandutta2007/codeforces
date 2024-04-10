#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  if (n == 1)
  {
    cout << "1 1\n" << -a[0] << '\n';
    cout << "1 1\n0\n";
    cout << "1 1\n0\n";
  }
  else
  {
    vector<long long> b(n - 1, -1);
    for (int i = 0; i < n; i++)
      b[1LL * i * n % (n - 1)] = 1LL * i * n;

    cout << "1 " << n << '\n';
    for (int i = 0; i < n; i++)
    {
      int mod = abs(a[i]) % (n - 1);
      if (a[i] > 0 && mod)
        mod = n - 1 - mod;
      cout << b[mod] << " \n"[i == n - 1];
      a[i] += b[mod];
    }

    cout << "1 1\n" << -a[0] << '\n';

    cout << "2 " << n << '\n';
    for (int i = 1; i < n; i++)
    {
      assert(a[i] % (n - 1) == 0);
      cout << -a[i] << " \n"[i == n - 1];
    }
  }
}