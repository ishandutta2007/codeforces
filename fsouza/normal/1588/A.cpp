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
    multiset<int> as;
    for (int i = 0; i < n; ++i) {
      int v;
      scanf("%d", &v);
      as.insert(v);
    }
    vector<int> b(n);
    for (int i = 0; i < n; ++i)
      scanf("%d", &b[i]);
    sort(b.begin(), b.end(), greater<int>());
    bool ok = true;
    for (int val : b) {
      auto it = as.find(val);
      if (it != as.end()) {
        as.erase(it);
        continue;
      }
      it = as.find(val - 1);
      if (it != as.end()) {
        as.erase(it);
        continue;
      }
      ok = false;
      break;
    }
    if (ok) printf("YES\n");
    else printf("NO\n");
  }
  return 0;
}