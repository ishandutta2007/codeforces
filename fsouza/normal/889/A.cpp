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
  set<int> result;
  result.insert(0);
  for (int i = 0; i < n; ++i) {
    int v;
    scanf("%d", &v);
    if (result.find(v) != result.end()) {
      result.erase(v);
    }
    result.insert(i + 1);
  }
  printf("%d\n", (int)result.size());
  return 0;
}