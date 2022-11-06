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
  map<int, pair<int, int>> gain;
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int id, value;
    scanf("%d %d", &id, &value);
    gain[id].first = value;
  }
  int m;
  scanf("%d", &m);
  for (int i = 0; i < m; ++i) {
    int id, value;
    scanf("%d %d", &id, &value);
    gain[id].second = value;
  }
  lint result = 0LL;
  for (const pair<int, pair<int, int>> &it : gain) {
    result += max(it.second.first, it.second.second);
  }
  printf("%lld\n", result);
  return 0;
}