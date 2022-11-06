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

const int nbit = 10, maxn = 1000;

int answers[nbit][2][maxn];

int main() {
  int n;
  scanf("%d", &n);

  for (int b = 0; b < nbit; ++b)
    for (int bvalue = 0; bvalue < 2; ++bvalue) {
      vector<int> idxs;
      for (int i = 0; i < n; ++i) {
        int value = (i & (1<<b)) != 0;
        if (value == bvalue)
          idxs.push_back(i);
      }

      if ((int)idxs.size() == n) {
        for (int i = 0; i < n; ++i)
          answers[b][bvalue][i] = 0;
      } else if (idxs.empty()) {
        for (int i = 0; i < n; ++i)
          answers[b][bvalue][i] = INT_MAX;
      } else {
        printf("%d\n", (int)idxs.size());
        for (int j = 0; j < (int)idxs.size(); ++j) {
          if (j > 0) printf(" ");
          printf("%d", idxs[j] + 1);
        }
        printf("\n");
        fflush(stdout);

        for (int i = 0; i < n; ++i)
          scanf("%d", &answers[b][bvalue][i]);
      }
    }

  printf("-1\n");
  for (int i = 0; i < n; ++i) {
    int result = INT_MAX;
    for (int b = 0; b < nbit; ++b) {
      int value = (i & (1<<b)) != 0;
      result = min(result, answers[b][!value][i]);
    }
    if (i > 0) printf(" ");
    printf("%d", result);
  }
  printf("\n");
  fflush(stdout);

  return 0;
}