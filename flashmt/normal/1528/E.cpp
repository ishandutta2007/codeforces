#include <bits/stdc++.h>
using namespace std;
const int BASE = 998244353;
const int N = 1e6 + 5;

long long f[N], sumF[N];

long long power(long long x, long long y)
{
  if (!y)
    return 1;
  long long res = power(x, y >> 1);
  res = res * res % BASE;
  if (y & 1)
    res = res * x % BASE;
  return res;
}

int main()
{
  int n;
  cin >> n;

  f[0] = sumF[0] = 1;
  for (int i = 1; i <= n; i++)
  {
    f[i] = f[i - 1]; // 1 child
    if (i >= 2)
      f[i] = (f[i] + f[i - 1] * sumF[i - 2]) % BASE; // 2 children with different heights
    f[i] = (f[i] + f[i - 1] * (f[i - 1] + 1) / 2) % BASE; // 2 children with same heights
    sumF[i] = (sumF[i - 1] + f[i]) % BASE;
  }

  long long ans = f[n]; // root with 2 children
  ans = (ans + f[n - 1] * (f[n - 1] + 1) % BASE * (f[n - 1] + 2) % BASE * power(6, BASE - 2)) % BASE; // 3 children of n - 1
  if (n >= 2)
  {
    ans = (ans + f[n - 1] * (f[n - 1] + 1) / 2 % BASE * sumF[n - 2]) % BASE; // 2 children of n - 1
    ans = (ans + sumF[n - 2] * (sumF[n - 2] + 1) / 2 % BASE * f[n - 1]) % BASE; // 1 child of n - 1
  }
  ans = (ans * 2 - 1 + BASE) % BASE; // 2 edge directions and remove special duplicate

  //  \         ^
  //   \       /
  //    v     /
  //     ---->
  //    ^     \
  //   /       \
  //  /         v
  // at least 1 node with deg 3 on left part
  for (int i = 1; i <= n - 2; i++)
  {
    // has exactly 2 children
    long long rightPart = (f[i] - f[i - 1] + BASE) % BASE;
    // ignore the case of straight line since we already covered that in line 34
    long long leftPart = (f[n - 1 - i] - 1 + BASE) % BASE;
    ans = (ans + rightPart * leftPart) % BASE;
  }

  cout << ans << endl;
}