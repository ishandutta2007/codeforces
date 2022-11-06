#include <algorithm>
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
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long lint;

int main() {
  int n, nship, shiplen, nshot;
  scanf("%d %d %d %d", &n, &nship, &shiplen, &nshot);

  string is_shot(n, ' ');
  scanf(" %s", &is_shot[0]);

  int can_fit = 0;
  int last_run = 0;
  for (int i = 0; i <= n; ++i) {
    if (i == n || is_shot[i] == '1') {
      can_fit += last_run / shiplen;
      last_run = 0;
    } else {
      ++last_run;
    }
  }

  vector<int> result;
  last_run = 0;
  for (int i = 0; i <= n; ++i) {
    if (i == n || is_shot[i] == '1') {
      last_run = 0;
    } else {
      ++last_run;
      if (last_run >= shiplen && can_fit >= nship) {
        result.push_back(i);
        last_run = 0;
        --can_fit;
      }
    }
  }
  printf("%d\n", (int)result.size());
  for (int i = 0; i < (int)result.size(); ++i) {
    if (i > 0) printf(" ");
    printf("%d", result[i]+1);
  }
  printf("\n");

  return 0;
}