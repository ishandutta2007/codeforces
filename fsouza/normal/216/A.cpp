#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <numeric>
#include <utility>

using namespace std;

typedef long long lint;

int solve(int a, int b, int c) {
  if (a == 1 || b == 1 || c == 1)
    return a * b * c;
  return 2 * (a + b + c) - 6 + solve(a - 1, b - 1, c - 1);
}

int main() {
  int a, b, c;

  scanf("%d %d %d", &a, &b, &c);

  printf("%d\n", solve(a, b, c));

  return 0;
}