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
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long lint;

bool is_prime(lint value) {
  if (value <= 1)
    return false;
  for (lint p = 2; p*p <= value; ++p)
    if (value % p == 0)
      return false;
  return true;
}

int main() {
  lint n;
  cin >> n;

  int result = 0;

  if (is_prime(n)) {
    result = 1;
  } else if (n % 2 == 0) {
    result = 2;
  } else if (is_prime(n - 2)) {
    result = 2;
  } else {
    result = 3;
  }

  printf("%d\n", result);

  return 0;
}