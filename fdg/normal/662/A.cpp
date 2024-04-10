#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <set>
#include <queue>
#include <map>

using namespace std;

vector<long long> v;

void add(long long x) {
  for (long long e : v) {
    if (x & e & -e) {
      x ^= e;
    }
  }
  if (!x) return;
  for (long long &e : v) {
    if (e & x & -x) e ^= x;
  }
  v.push_back(x);
}

int main() {
  int n;
  scanf("%d", &n);
  long long total = 0;
  for (int i = 0; i < n; ++i) {
    long long a, b;
    scanf("%lld%lld", &a, &b);
    total ^= a;
    add(a ^ b);
  }
  for (long long e : v) {
    if (total & e & -e) total ^= e;
  }
  if (total) puts("1/1");
  else printf("%lld/%lld\n", (1LL << v.size()) - 1, (1LL << v.size()));
  return 0;
}