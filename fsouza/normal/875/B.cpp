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
  vector<int> pos(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &pos[i]), --pos[i];
  }
  int last_a = -1;
  vector<int> result(n);
  for (int i = n - 1; i >= 0; --i) {
    if (i == n - 1) result[i] = 1;
    else {
      result[i] = 1 + (last_a - (n - 1 - i - 1));
    }
    last_a = max(last_a, pos[i]);
  }
  printf("1");
  for (int i = 0; i < n; ++i)
    printf(" %d", result[i]);
  printf("\n");
  return 0;
}