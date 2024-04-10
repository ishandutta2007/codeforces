#include <bits/stdc++.h>
using namespace std;
const int BASE = 998244353;

int main()
{
  int n, m, k;
  long long f[2020] = {0};
  cin >> n >> m >> k;
  f[0] = m;
  for (int i = 2; i <= n; i++)
    for (int j = i; j; j--)
      f[j] = (f[j] + f[j - 1] * (m - 1)) % BASE;
  cout << f[k] << endl;
}