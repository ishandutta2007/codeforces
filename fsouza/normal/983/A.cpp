#include <algorithm>
#include <array>
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
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long lint;

lint gcd(lint a, lint b) {
  if (a == 0) return b;
  return gcd(b%a, a);
}

int main() {
  int nt;
  scanf("%d", &nt);
  for (int t = 0; t < nt; ++t) {
    lint p, q, b;
    scanf("%lld %lld %lld", &p, &q, &b);
    lint g;
    g = gcd(p, q);
    p /= g;
    q /= g;
    g = b;
    while ((g = gcd(q, g)) != 1)
      q /= g;
    if (q != 1) printf("Infinite\n");
    else printf("Finite\n");
  }
  return 0;
}