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

int gcd(int a, int b) {
  if (a == 0) return b;
  return gcd(b%a, a);
}

int main() {
  int nt;
  scanf("%d", &nt);
  for (int t = 0; t < nt; ++t) {
    int n;
    scanf("%d", &n);
    vector<int> values(n);
    for (int i = 0; i < n; ++i)
      scanf("%d", &values[i]);
    int ans_div = 0;
    for (int b = 0; b < 30; ++b) {
      int many = 0;
      for (int i = 0; i < n; ++i)
        if (values[i] & (1<<b))
          many += 1;
      ans_div = gcd(ans_div, many);
    }
    vector<int> result;
    if (ans_div == 0) {
      result.resize(n);
      iota(result.begin(), result.end(), 1);
    } else {
      for (int v = 1; v <= ans_div; ++v)
        if (ans_div % v == 0)
          result.push_back(v);
    }
    for (int i = 0; i < (int)result.size(); ++i) {
      if (i > 0) printf(" ");
      printf("%d", result[i]);
    }
    printf("\n");
  }
  return 0;
}