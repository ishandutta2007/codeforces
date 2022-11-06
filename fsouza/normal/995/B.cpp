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

int count_inv(vector<int> a, vector<int> b) {
  if (a[0] > b[1]) return 0;
  else if (a[1] < b[0]) return 0;
  else if (a[0] <= b[0] && b[1] <= a[1]) return 2;
  else if (b[0] <= a[0] && a[1] <= b[1]) return 2;
  else return 1;
}

int main() {
  int n;
  scanf("%d", &n);
  vector<int> values(2 * n);
  vector<vector<int>> pos_of(n);
  for (int i = 0; i < 2 * n; ++i) {
    scanf("%d", &values[i]), --values[i];
    pos_of[values[i]].push_back(i);
  }
  for (int i = 0; i < n; ++i) {
    sort(pos_of[i].begin(), pos_of[i].end());
    assert(pos_of[i].size() == 2);
  }
  int result = 0;
  for (int i = 0; i < n; ++i)
    for (int j = i + 1; j < n; ++j)
      result += count_inv(pos_of[i], pos_of[j]);
  printf("%d\n", result);

  return 0;
}