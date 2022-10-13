#include <bits/stdc++.h>
using namespace std;
const int BASE = 998244353;

int main()
{
  int n;
  cin >> n;

  long long fact[1000100], f[1000100];
  fact[0] = 1;
  for (int i = 1; i <= n; i++)
    fact[i] = fact[i - 1] * i % BASE;

  f[1] = f[2] = 0;
  for (int i = 3; i <= n; i++)
    f[i] = (f[i - 1] + fact[i - 1] - 1) * i % BASE;

  cout << (f[n] + fact[n]) % BASE << endl;
}