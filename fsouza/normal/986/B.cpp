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

int main() {
  int n;
  scanf("%d", &n);
  vector<int> perm(n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &perm[i]), --perm[i];

  int parity = 0;
  for (int i = 0; i < n; ++i)
    while (perm[i] != i) {
      parity ^= 1;
      swap(perm[i], perm[perm[i]]);
    }

  if (parity == n % 2) printf("Petr\n");
  else printf("Um_nik\n");

  return 0;
}