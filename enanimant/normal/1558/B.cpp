/*
 * author:  ADMathNoob
 * created: 08/24/21 10:35:12
 * problem: https://codeforces.com/contest/1558/problem/B
 */

/*
Comments about problem:


*/

#include <bits/stdc++.h>

using namespace std;

namespace modular {

// const int md = 998244353;
// const int md = (int) 1e9 + 7;
int md;

inline void add(int& a, const int b) {
  a += b;
  if (a >= md) {
    a -= md;
  }
}

inline void sub(int& a, const int b) {
  a -= b;
  if (a < 0) {
    a += md;
  }
}

inline int mul(int a, int b) {
  return (int) ((long long) a * b % md);
}

inline int power(int a, long long b) {
  a %= md;
  if (a < 0) {
    a += md;
  }
  int res = 1;
  while (b > 0) {
    if (b & 1) {
      res = mul(res, a);
    }
    a = mul(a, a);
    b >>= 1;
  }
  return res;
}

inline int inverse(int a) {
  a %= md;
  if (a < 0) {
    a += md;
  }
  int b = md, u = 0, v = 1;
  while (a > 0) {
    int q = b / a;
    b -= q * a;
    swap(a, b);
    u -= q * v;
    swap(u, v);
  }
  assert(b == 1);  // b = gcd(a, md)
  if (u < 0) {
    u += md;
  }
  return u;
}

}  // namespace modular

using namespace modular;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n >> md;
  vector<int> f(n + 2);
  add(f[1], 1);
  sub(f[2], 1);
  for (int i = 1; i <= n; i++) {
    add(f[i + 1], f[i]); // difference array
    add(f[i + 1], f[i]);
    sub(f[n + 1], f[i]);
    for (int j = 2; j * i <= n; j++) {
      int L = j * i;
      int R = min(j * i + j - 1, n);
      add(f[L], f[i]);
      sub(f[R + 1], f[i]);
    }
  }
  cout << f[n] << '\n';
  return 0;
}