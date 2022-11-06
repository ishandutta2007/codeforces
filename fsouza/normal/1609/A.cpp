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
  int nt;
  scanf("%d", &nt);
  for (int t = 0; t < nt; ++t) {
    int n;
    scanf("%d", &n);
    vector<int> values(n);
    int np2 = 0;
    for (int i = 0; i < n; ++i) {
      int v;
      scanf("%d", &v);
      while (v % 2 == 0) {
        np2 += 1;
        v /= 2;
      }
      values[i] = v;
    }
    sort(values.begin(), values.end());
    lint big_value = values.back();
    big_value <<= np2;
    lint sum = accumulate(values.begin(), values.end() - 1, 0LL) + big_value;
    printf("%lld\n", sum);
  }
  return 0;
}