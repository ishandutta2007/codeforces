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
  int n, s;
  scanf("%d %d", &n, &s), --s;

  vector<bool> right(n, false), left(n, false);
  for (int i = 0; i < n; ++i) {
    int v;
    scanf("%d", &v);
    if (v == 1) right[i] = true;
  }
  for (int i = 0; i < n; ++i) {
    int v;
    scanf("%d", &v);
    if (v == 1) left[i] = true;
  }

  vector<bool> reach_right(n, false), reach_left(n, false);

  reach_right[0] = right[0];
  reach_left[0] = left[0];

  for (int rep = 0; rep < 10050; ++rep) {
    for (int i = 0; i + 1 < n; ++i)
      if (reach_right[i])
        reach_right[i + 1] = true;
    for (int i = n - 1; i - 1 >= 0; --i)
      if (reach_left[i])
        reach_left[i - 1] = true;
    for (int i = 0; i < n; ++i)
      if (right[i] && left[i] && (reach_left[i] || reach_right[i])) {
        reach_left[i] = true;
        reach_right[i] = true;
      }
  }

  bool result = (reach_left[s] && left[s]) || (reach_right[s] && right[s]);
  if (result) printf("YES\n");
  else printf("NO\n");

  return 0;
}