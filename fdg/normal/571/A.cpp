#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

long long C(int n, int k) {
  long long ret = 1;
  for (int i = 1; i <= k; ++i) {
    ret *= (n + 1 - i);
    ret /= i;
  }
  return ret;
}

long long solve(int a, int b, int c, int l) {
  long long ret = 0;
  for (int mx = max(a, b + c); a + l >= mx; ++mx) {
    int add = min(l - (mx - a), mx - (b + c));
    if (add < 0) continue;
    ret += C(add + 2, 2);
  }
  return ret;
}

int main() {
  int a, b, c, l;
  cin >> a >> b >> c >> l;
  cout << C(l + 3, 3) - (solve(a, b, c, l) + solve(b, a, c, l) + solve(c, a, b, l)) << endl;
  return 0;
}