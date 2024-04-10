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

int gcd(int a, int b) {
  if (a == 0) return b;
  return gcd(b%a, a);
}

int main() {
  int la, ra, ta;
  int lb, rb, tb;
  scanf("%d %d %d", &la, &ra, &ta);
  scanf("%d %d %d", &lb, &rb, &tb);
  if (ta < tb) {
    swap(la, lb);
    swap(ra, rb);
    swap(ta, tb);
  }

  int every = gcd(ta, tb);
  int start = lb % ta;
  int len = rb - lb + 1;

  int start1;
  if (start == la) {
    start1 = la;
  } else if (start > la) {
    start1 = start - ((start - la) / every) * every;
  } else {
    start1 = start + ((la - start + every - 1) / every) * every;
    if (start1 >= ta) start1 -= ta;
  }

  int start2 = start1 - every;
  if (start2 < 0) start2 += ta;

  int result = 0;
  for (int from : {start1, start2}) {
    int to = from + len - 1;
    vector<pair<int, int>> ranges;

    int res = 0;
    if (to < ta) ranges = {{from, to}};
    else ranges = {{from, ta - 1}, {0, to - ta}};
    for (const pair<int, int> &range : ranges)
      res += max(min(range.second, ra) - max(range.first, la) + 1, 0);
    result = max(result, res);
  }
  printf("%d\n", result);
  return 0;
}