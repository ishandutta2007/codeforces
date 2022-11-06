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

#define MAXN 200000

using namespace std;

typedef long long lint;

int main() {
  int n, cid;
  scanf("%d %d", &n, &cid), --cid;

  int result = 0;
  multiset<int> heights;

  for (int i = 0; i < n; ++i) {
    int h;
    scanf("%d", &h);
    if (cid == i) result += (h != 0);
    else heights.insert(h != 0 ? h : MAXN+2);
  }

  for (int v = 1; !heights.empty(); ++v) {
    auto it = heights.lower_bound(v);
    if (it != heights.end() && *it == v) {
      heights.erase(v);
    } else {
      it = heights.end(); --it;
      heights.erase(it);
      ++result;
    }
  }

  printf("%d\n", result);

  return 0;
}