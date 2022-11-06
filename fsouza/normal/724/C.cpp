#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

#define INFLL LLONG_MAX

using namespace std;

typedef long long lint;

lint gcd(lint a, lint b) {
  if (a == 0) return b;
  return gcd(b%a, a);
}

lint egcd(lint a, lint b, lint &x, lint &y) {
  if (a == 0) { x = 0, y = 1; return b;
  } else {
    lint ret = egcd(b%a, a, y, x); x -= y*(b/a);
    return ret;
  }
}

inline lint safemod(lint a, lint b) {
  lint res = a%b;
  if (res < 0) res += b;
  return res;
}

lint inv(lint a, lint n) {
  lint x, y;
  egcd(a, n, x, y);
  return safemod(x, n);
}

lint solve_linear_equation(lint a, lint b, lint n) {
  lint g = gcd(a, n);
  if (b%g != 0) return -1;
  a /= g, b /= g, n /= g;
  lint inva = inv(a, n);
  return inva * b % n;
}

lint solve2(lint m0, lint m1, lint r0, lint r1) {
  lint rhs = safemod(r1-r0, m1);
  lint k = solve_linear_equation(m0, rhs, m1);
  if (k < 0) return INFLL;
  return k*m0 + r0;
}

lint solve(int n, int m, int x, int y) {
  lint res1 = solve2(2*n, 2*m, x, y);
  lint res2 = solve2(2*n, 2*m, 2*n-x, y);
  lint res3 = solve2(2*n, 2*m, x, 2*m-y);
  lint res4 = solve2(2*n, 2*m, 2*n-x, 2*m-y);
  lint result = min({res1, res2, res3, res4});
  if (result == INFLL) return -1;
  return result;
}

int main() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);

  for (int i = 0; i < k; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    printf("%lld\n", solve(n, m, x, y));
  }

  return 0;
}