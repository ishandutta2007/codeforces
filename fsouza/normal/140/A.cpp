#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <numeric>
#include <utility>

using namespace std;

typedef long long lint;

bool solve(int n, int R, int r) {
  if (n <= 0) return true;
  if (r > R) return false;
  if (2*r > R) return (n <= 1);
  if (2*r == R) return (n <= 2);
  if (n == 1) return r <= R;
  if (n == 2) return 2*r <= R;
  int dist = R-r;
  
  return sin(M_PI/n) >= 1.0*r/dist - 1e-9;
}

int main() {
  int n, r, R;

  scanf("%d %d %d", &n, &r, &R);

  printf(solve(n, r, R) ? "YES\n" : "NO\n");

  return 0;
}