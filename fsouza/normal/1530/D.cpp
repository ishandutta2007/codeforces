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
    vector<int> a(n);
    vector<int> to(n, -1);
    for (int i = 0; i < n; ++i) {
      scanf("%d", &a[i]), --a[i];
      to[a[i]] = i;
    }
    vector<int> from(n, -1);
    vector<int> available;
    for (int i = 0; i < n; ++i) {
      if (to[i] != -1) {
        from[to[i]] = i;
      } else {
        available.push_back(i);
      }
    }
    vector<int> selfs;
    for (int i = 0; i < n; ++i) {
      if (from[i] == -1) {
        assert(!available.empty());
        if (available.back() == i) {
          selfs.push_back(i);
        }
        from[i] = available.back();
        available.pop_back();
      }
    }
    assert(available.empty());

    if (selfs.empty()) {
    } else if (selfs.size() == 1) {
      int self = selfs[0];
      int want = a[self];
      int conflict = -1;
      for (int i = 0; i < n; ++i)
        if (from[i] == want) {
          conflict = i;
          break;
        }
      assert(conflict != -1);
      from[self] = want;
      from[conflict] = self;
    } else {
      for (int i = 0; i < (int)selfs.size(); ++i) {
        int next = i + 1 < (int)selfs.size() ? selfs[i + 1] : selfs[0];
        from[selfs[i]] = next;
      }
    }

    int happy = 0;
    for (int i = 0; i < n; ++i)
      if (from[i] == a[i])
        ++happy;
    printf("%d\n", happy);
    for (int i = 0; i < n; ++i) {
      if (i > 0) printf(" ");
      printf("%d", from[i] + 1);
    }
    printf("\n");
  }
  return 0;
}