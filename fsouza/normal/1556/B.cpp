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
    vector<int> evens, odds;
    for (int i = 0; i < n; ++i) {
      int value;
      scanf("%d", &value);
      if (value % 2 == 0) evens.push_back(i);
      else odds.push_back(i);
    }
    lint result = LLONG_MAX;
    for (int start = 0; start < 2; ++start) {
      lint res = 0;
      bool ok = true;

      int cur_parity = start;

      vector<int> back_evens = evens, back_odds = odds;
      for (int i = n - 1; i >= 0; --i) {
        vector<int> *from = (cur_parity == 0) ? &evens : &odds;

        if (from->empty()) {
          ok = false;
          break;
        } else {
          res += abs(from->back() - i);
          from->pop_back();
        }

        cur_parity ^= 1;
      }

      evens = back_evens;
      odds = back_odds;

      if (ok) {
        assert(res % 2 == 0);
        result = min(result, res / 2);
      }
    }
    if (result == LLONG_MAX)
      result = -1;
    printf("%lld\n", result);
  }
  return 0;
}