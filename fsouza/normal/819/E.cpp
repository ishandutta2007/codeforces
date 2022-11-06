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

vector<vector<int>> solve(int n) {
  assert(n >= 3);
  if (n == 3) {
    return {{0, 1, 2}, {0, 1, 2}};
  } else if (n == 4) {
    return {{0, 1, 3, 2}, {0, 1, 2, 3}, {0, 2, 1, 3}};
  } else {
    vector<vector<int>> result = solve(n - 2);
    if (n % 2 == 0) {
      result.push_back({0, n - 1, 1, n - 2});
      result.push_back({0, n - 1, n - 2});
      result.push_back({1, n - 1, n - 2});
      for (int i = 2; i + 1 < n - 2; i += 2) {
        result.push_back({i, n - 1, i + 1, n - 2});
        result.push_back({i, n - 1, i + 1, n - 2});
      }
    } else {
      result.push_back({0, n - 2, n - 1});
      result.push_back({0, n - 2, n - 1});
      for (int i = 1; i + 1 < n - 2; i += 2) {
        result.push_back({i, n - 1, i + 1, n - 2});
        result.push_back({i, n - 1, i + 1, n - 2});
      }
    }
    return move(result);
  }
}

int main() {
  int n;
  scanf("%d", &n);
  vector<vector<int>> result = solve(n);
  printf("%d\n", (int)result.size());
  for (const vector<int> &cycle : result) {
    printf("%d", (int)cycle.size());
    for (int v : cycle)
      printf(" %d", v + 1);
    printf("\n");
  }
  return 0;
}