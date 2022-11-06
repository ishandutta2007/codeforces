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

const int maxv = 1e5;

int main() {
  vector<int> ndiv(maxv + 1);
  for (int v = 1; v <= maxv; ++v)
    for (int d = 1; d * d <= v; ++d)
      if (v % d == 0) {
        ++ndiv[v];
        if (v / d != d) ++ndiv[v];
      }

  vector<vector<int>> valid_choices;
  for (int a = 1; a < (1<<3); ++a)
    for (int b = a; b < (1<<3); ++b)
      for (int c = b; c < (1<<3); ++c) {
        int perm[3] = {a, b, c};
        bool any = false;
        do {
          bool ok = true;
          for (int i = 0; i < 3; ++i)
            if (!(perm[i] & (1<<i))) {
              ok = false;
              break;
            }
          if (ok) {
            any = true;
            break;
          }
        } while (next_permutation(perm, perm + 3));
        if (any) valid_choices.push_back({a, b, c});
      }

  int nt;
  scanf("%d", &nt);
  for (int t = 0; t < nt; ++t) {
    int values[3];
    for (int i = 0; i < 3; ++i)
      scanf("%d", &values[i]);
    int mask_count[1<<3] = {};
    for (int mask = (1<<3) - 1; mask > 0; --mask) {
      int g = 0;
      for (int i = 0; i < 3; ++i)
        if (mask & (1<<i))
          g = gcd(g, values[i]);
      mask_count[mask] = ndiv[g];
      int comp = ((1<<3) - 1) ^ mask;
      for (int sub_comp = comp; sub_comp > 0; sub_comp = (sub_comp - 1) & comp) {
        int super = mask | sub_comp;
        mask_count[mask] -= mask_count[super];
      }
    }
    lint result = 0;
    for (const vector<int> &choice : valid_choices) {
      lint res = 1;
      for (int j = 0, i = j; i < (int)choice.size(); i = j) {
        while (j < (int)choice.size() && choice[j] == choice[i]) ++j;
        int have = mask_count[choice[i]];
        int want = j - i;
        if (have == 0) res = 0;
        else {
          for (int k = 0; k < want; ++k)
            res = res * (want + have - 1 - k) / (k + 1);
        }
      }
      result += res;
    }
    printf("%lld\n", result);
  }

  return 0;
}