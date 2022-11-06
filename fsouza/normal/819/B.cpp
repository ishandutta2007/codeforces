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
  vector<int> perm(n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &perm[i]), --perm[i];
  priority_queue<int, vector<int>, greater<int>> positives;
  lint positive_sum = 0LL, negative_sum = 0LL;
  for (int i = 0; i < n; ++i) {
    int diff = perm[i] - i;
    if (diff > 0) {
      positives.push(diff);
      positive_sum += diff;
    } else {
      negative_sum += diff;
    }
  }
  int best_k = 0;
  lint best_deviation = positive_sum + (-negative_sum);
  for (int k = 1; k < n; ++k) {
    int old_diff = perm[n - k] - (n - k);
    negative_sum -= old_diff;
    int new_diff = perm[n - k] - (-k);
    positives.push(new_diff);
    positive_sum += new_diff;
    while (!positives.empty() && positives.top() - k <= 0) {
      const int move = positives.top();
      positives.pop();
      positive_sum -= move;
      negative_sum += move;
    }
    lint current_deviation = positive_sum + (-negative_sum)
      - (lint)k * positives.size() + (lint)k * (n - positives.size());
    if (current_deviation < best_deviation) {
      best_k = k;
      best_deviation = current_deviation;
    }
  }
  printf("%lld %d\n", best_deviation, best_k);
  return 0;
}