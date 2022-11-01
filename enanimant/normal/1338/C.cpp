// April 12, 2020
// https://codeforces.com/contest/1338/problem/C

/*

*/


#include <bits/stdc++.h>

using namespace std;


long long pow4[31];
long long psa[32];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);
#endif


  // set<int> s;
  // int a = 1;
  // for (int it = 0; it < 100; it++) {
  //   for (int b = a + 1; b < 1000; b++) {
  //     if (!s.count(b) && !s.count(a ^ b)) {
  //       int c = a ^ b;
  //       s.insert(a);
  //       s.insert(b);
  //       s.insert(c);
  //       cerr << a << ' ' << b << ' ' << c << '\n';
  //       // cerr << b << "; popcount = " << __builtin_popcountll(b) << '\n';
  //       if (it % 4 == 0) {
  //         cerr << '\n';
  //       }
  //       break;
  //     }
  //   }
  //   while (s.count(a)) {
  //     a++;
  //   }
  // }

  pow4[0] = 1;
  psa[0] = 0;
  psa[1] = 1;
  for (int i = 1; i < 31; i++) {
    pow4[i] = pow4[i - 1] * 4;
    psa[i + 1] = psa[i] + pow4[i];
  }

  int tt;
  cin >> tt;
  while (tt--) {
    long long n;
    cin >> n;
    if (n <= 3) {
      cout << n << '\n';
      continue;
    }
    n -= 3;
    long long m = (n + 2) / 3;
    int e = 31;
    while (m < psa[e]) {
      e--;
    }
    m -= psa[e];
    long long x = pow4[e] + m;
    long long y = pow4[e] * 2;
    for (int i = 0; i < e; i++) {
      int b = (x >> (2 * i)) % 4;
      if (b == 1) {
        y |= 2LL << (2 * i);
      } else if (b == 2) {
        y |= 3LL << (2 * i);
      } else if (b == 3) {
        y |= 1LL << (2 * i);
      }
    }
    if (n % 3 == 1) {
      cout << x << '\n';
    } else if (n % 3 == 2) {
      cout << y << '\n';
    } else {
      cout << (x ^ y) << '\n';
    }
  }


  return 0;
}