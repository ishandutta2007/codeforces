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
  int n, m;
  scanf("%d %d", &n, &m);
  vector<int> targets(m);
  for (int i = 0; i < m; ++i) {
    scanf("%d", &targets[i]);
  }
  vector<int> acc_sums(m);
  for (int i = 1; i < m; ++i)
    acc_sums[i] = acc_sums[i - 1] + targets[i - 1];
  const int tsum = accumulate(targets.begin(), targets.end(), 0);
  vector<int> splits;
  int sum = 0;
  for (int i = 0; i < m; ++i) {
    splits.push_back(sum);
    sum = (sum + targets[i]) % n;
  }
  splits.push_back(n);
  sort(splits.begin(), splits.end());
  splits.resize(unique(splits.begin(), splits.end()) - splits.begin());

  vector<int> group_sizes;
  for (int i = 0; i + 1 < (int)splits.size(); ++i)
    group_sizes.push_back(splits[i + 1] - splits[i]);
  group_sizes.resize(m, 0);

  const int nstep = (tsum + (n - 1)) / n;
  int next_id = 0;
  int cur_sum = 0;

  printf("%d\n", nstep);

  for (int i = 0; i < m; ++i) {
    if (i > 0) printf(" ");
    printf("%d", group_sizes[i]);
  }
  printf("\n");

  for (int step = 0; step < nstep; ++step) {
    for (int i = 0; i < m; ++i) {
      if (i > 0) printf(" ");
      if (group_sizes[i] == 0) {
        printf("1");
      } else {
        while (next_id + 1 < m && acc_sums[next_id + 1] <= cur_sum) ++next_id;
        cur_sum += group_sizes[i];
        printf("%d", next_id + 1);
      }
    }
    printf("\n");
  }

  return 0;
}