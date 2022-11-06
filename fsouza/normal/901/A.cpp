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
  int maxd;
  scanf("%d", &maxd);
  vector<int> count(maxd + 1);
  for (int d = 0; d <= maxd; ++d)
    scanf("%d", &count[d]);
  int diff_at = -1;
  for (int d = 0; d + 1 <= maxd; ++d)
    if (count[d] > 1 && count[d + 1] > 1) {
      diff_at = d + 1;
      break;
    }
  if (diff_at == -1) {
    printf("perfect\n");
  } else {
    printf("ambiguous\n");
    for (int tree = 0; tree < 2; ++tree) {
      printf("0");
      int last_id = 0;
      for (int d = 1; d <= maxd; ++d) {
        for (int i = 0; i < count[d]; ++i) {
          int parent_id;
          if (d == diff_at && i == count[d] - 1 && tree == 1)
            parent_id = last_id - 1;
          else
            parent_id = last_id;
          printf(" %d", parent_id + 1);
        }
        last_id += count[d];
      }
      printf("\n");
    }
  }
  return 0;
}