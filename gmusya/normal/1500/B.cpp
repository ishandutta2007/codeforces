#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef __int128 i128;

i128 gcd(i128 a, i128 b, i128 &x, i128 &y) {
  if (!b) {
    x = 1, y = 0;
    return a;
  }
  i128 x1, y1;
  i128 g = gcd(b, a % b, x1, y1);
  y = x1 - (a / b) * y1;
  x = y1;
  return g;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  ll n, m, bad;
  cin >> n >> m >> bad;
  vector <ll> a(n);
  for (i128 i = 0; i < n; i++) {
    cin >> a[i];
    a[i]--;
  }
  vector <ll> b(m);
  for (i128 i = 0; i < m; i++) {
    cin >> b[i];
    b[i]--;
  }
  vector <i128> p(2 * m + 2 * n, -1);
  for (i128 i = 0; i < n; i++)
    p[a[i]] = i;
  vector <i128> ks(m), ds(m);
  i128 L = 0, R = 1e18;
  for (i128 i = 0; i < m; i++) {
    i128 j = p[b[i]];
    if (j == -1) {
      ks[i] = -1, ds[i] = -1;
      continue;
    }
    // x = km + i
    // x = cn + j
    // km - cn = j - i
    // k >= 0
    // k < (M - i) / m
    i128 k, c;
    i128 g = gcd(m, n, k, c);
    if ((i - j) % g) {
      ks[i] = -1, ds[i] = -1;
      continue;
    }
    k *= (j - i) / g;
    k = k % (n / g);
    while (k < 0)
      k += n / g;
    i128 d = n / g;
    ks[i] = k;
    ds[i] = d;
    /*i128 val = (M - i + m - 1) / m;
    cnt += (val - k + d - 1) / d;*/
  }
  while (L != R) {
    i128 M = (L + R) / 2;
    i128 cnt = 0; //   
    for (int i = 0; i < m; i++) {
      if (ks[i] == -1)
        continue;
      i128 val = (M - i + m - 1) / m;
      cnt += (val - ks[i] + ds[i] - 1) / ds[i];
    }
    if (M - cnt < bad)
      L = M + 1;
    else
      R = M;
  }
  cout << (ll)L;
  return 0;
}