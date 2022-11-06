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
  int nt;
  scanf("%d", &nt);
  for (int t = 0; t < nt; ++t) {
    int n;
    scanf("%d", &n);
    int result = 0;
    for (int b = 0; (1<<b) < n; ++b) {
      vector<int> l1, l2;
      for (int i = 0; i < n; ++i) {
        if (i & (1<<b)) l1.push_back(i);
        else l2.push_back(i);
      }
      printf("%d %d", (int)l1.size(), (int)l2.size());
      for (const vector<int> &l : {l1, l2})
        for (int v : l)
          printf(" %d", v + 1);
      printf("\n");
      fflush(stdout);
      int ans = -1;
      scanf(" %d", &ans);
      if (ans == -1) exit(0);
      result = max(result, ans);
    }
    printf("-1 %d\n", result);
    fflush(stdout);
  }
  return 0;
}