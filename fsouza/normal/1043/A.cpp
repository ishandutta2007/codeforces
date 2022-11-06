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
  vector<int> first(n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &first[i]);
  int left = *max_element(first.begin(), first.end()), right = 201;
  while (left < right) {
    int m = left + (right - left) / 2;
    int other = 0, me = 0;
    for (int i = 0; i < n; ++i) {
      other += first[i];
      me += m - first[i];
    }
    if (me > other) right = m;
    else left = m + 1;
  }
  printf("%d\n", left);
  return 0;
}