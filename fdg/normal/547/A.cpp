#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

pair<long long, long long> get(int h, int a, int x, int y, int mod) {
  pair<int, int> ret(-1, -1);
  for (int it = 1; ; ++it) {
    h = (1LL * x * h + y) % mod;
    if (h == a) {
      if (ret.first == -1) ret.first = it;
      else {
        ret.second = it - ret.first;
        break;
      }
    }
    if (it > 2 * mod + 100) break;
  }
  return ret;
}

long long gcd (long long a, long long b, long long & x, long long & y) {
  if (a == 0) {
    x = 0; y = 1;
    return b;
  }
  long long x1, y1;
  long long d = gcd (b%a, a, x1, y1);
  x = y1 - (b / a) * x1;
  y = x1;
  return d;
}
 
bool find_any_solution (long long a, long long b, long long c, long long & x0, long long & y0, long long & g) {
  g = gcd (abs(a), abs(b), x0, y0);
  if (c % g != 0)
    return false;
  x0 *= c / g;
  y0 *= c / g;
  if (a < 0)   x0 *= -1;
  if (b < 0)   y0 *= -1;
  return true;
}

int main() {
  int m, h1, a1, x1, y1, h2, a2, x2, y2;
  cin >> m >> h1 >> a1 >> x1 >> y1 >> h2 >> a2 >> x2 >> y2;
  auto p1 = get(h1, a1, x1, y1, m), p2 = get(h2, a2, x2, y2, m);
  // if (p1.second == p2.second || (p1.first - p2.first) % (p2.second - p1.second) != 0) {
  //   if (p1.first == p2.first) cout << p1.first << endl;
  //   else cout << -1 << endl;
  //   return 0;
  // }
  // long long k = (p1.first - p2.first) / (p2.second - p1.second);
  // cout << p1.first + k * p1.second << endl;
  
  // cout << p2.first << " " << p2.second << endl;

  if (p1.first != -1 && p2.first != -1)
    for (int it = 0; it < 20000000; ++it) {
      if (p1.first >= p2.first && (p1.first == p2.first || ((p1.first - p2.first) % p2.second) == 0 && p2.second > 0)) {
        cout << p1.first << endl;
        return 0;
      }
      p1.first += p1.second;
      if (p1.second == -1) break;
    }
  cout << -1 << endl;

  // long long x0, y0, g;
  // if (p1.first != -1 && p2.first != -1 && find_any_solution(p1.second, -p2.second, p2.first - p1.first, x0, y0, g)) {
  //   // cout << p1.second << " " << -p2.second << endl;
  //   long long K = -x0 / (p2.second / g);
  //   if (x0 < 0) {
  //     x0 += K * p2.second / g;
  //     y0 += K * p1.second / g;
  //     while (x0 < 0) {
  //       x0 += p2.second / g;
  //       y0 += p1.second / g;
  //       // cout << x0 << " " << y0 << endl;
  //     }
  //   }
  //   if (y0 < 0) {
  //     K = -y0 / (p2.second / g);
  //     x0 += K * p2.second / g;
  //     y0 += K * p1.second / g;
  //     while (y0 < 0) {
  //       x0 += p2.second / g;
  //       y0 += p1.second / g;
  //     }
  //   }

  //   if (x0 >= 0 && y0 >= 0) {
  //     K = min(x0 / (p2.second / g), y0 / (p1.second / g));
  //     x0 -= K * p2.second / g;
  //     y0 -= K * p1.second / g;
  //     while (p2.second / g > 0 || p1.second / g > 0) {
  //       if (x0 - p2.second / g >= 0 && y0 - p1.second / g >= 0) {
  //         x0 -= p2.second / g;
  //         y0 -= p1.second / g;
  //       } else {
  //         break;
  //       }
  //     }
  //   }
  //   if (x0 >= 0 && y0 >= 0) {
  //     cout << p1.first + x0 * p2.second << endl;
  //   } else {
  //     cout << -1 << endl;
  //   }
  //   // cout << x0 << " " << y0 << "  " << g << endl;
  // } else {
  //   cout << -1 << endl;
  // }
  return 0;
}