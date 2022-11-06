#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <numeric>

using namespace std;

int gcd(int a, int b) {
  if (a == 0) return b;
  return gcd(b%a, a);
}

int main() {
  int a, b, n;

  scanf("%d %d %d", &a, &b, &n);

  int winner;
  
  for (int turn = 0; n >= 0; turn++) {
    n -= gcd(n, a);
    if (n < 0) {
      winner = 1;
      break;
    }
    n -= gcd(n, b);
    if (n < 0) {
      winner = 0;
      break;
    }
  }

  printf("%d\n", winner);

  return 0;
}