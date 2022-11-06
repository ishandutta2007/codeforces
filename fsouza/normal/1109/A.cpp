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
  vector<int> values(n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &values[i]);
  map<int, int> many[2];
  lint result = 0;
  int acc = 0;
  many[1][acc] += 1;
  for (int i = 0; i < n; ++i) {
    acc ^= values[i];
    result += many[i % 2][acc];
    many[i % 2][acc] += 1;
  }
  printf("%lld\n", result);
  return 0;
}