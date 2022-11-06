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
  vector<int> state(n);
  for (int i = 0; i < n; ++i) {
    char c;
    scanf(" %c", &c);
    state[i] = (c == '1');
  }
  struct light_t {
    int a, b;
  };
  vector<light_t> lights(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d %d", &lights[i].a, &lights[i].b);
  }
  int result = 0;
  for (int t = 0; t <= 1000; ++t) {
    for (int i = 0; i < n; ++i)
      if (t >= lights[i].b && (t - lights[i].b) % lights[i].a == 0)
        state[i] ^= 1;
    int on_count = accumulate(state.begin(), state.end(), 0);
    result = max(result, on_count);
  }
  printf("%d\n", result);
  return 0;
}