#include <algorithm>
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
#include <numeric>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long lint;

int main() {
  int n;
  scanf("%d", &n);
  const int maxv = 1000000;
  vector<int> nvote(maxv+1, 0);
  int winner = -1;
  for (int i = 0; i < n; ++i) {
    int v;
    scanf("%d", &v);
    ++nvote[v];
    if (winner == -1 || nvote[v] > nvote[winner]) winner = v;
  }
  printf("%d\n", winner);

  return 0;
}