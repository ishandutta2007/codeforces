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
typedef unsigned long long ulint;

int main() {
  const int lim = 30;
  set<lint> marked;
  vector<vector<int>> bad;

  for (int n1 = 0; n1 <= lim; ++n1)
    for (int n5 = 0; n5 <= lim; ++n5)
      for (int n10 = 0; n10 <= lim; ++n10)
        for (int n50 = 0; n50 <= lim; ++n50) {
          lint num = (n1 + 5 * n5 + 10 * n10 + 50 * n50) * (4 * (lim + 2)) +
            n1 + n5 + n10 + n50;

          if (marked.find(num) != marked.end()) {
            vector<int> new_bad = {n1, n5, n10, n50};
            bool skip = false;
            for (const vector<int> &prev : bad) {
              bool sub = true;
              for (int i = 0; i < 4; ++i)
                if (new_bad[i] < prev[i]) {
                  sub = false;
                  break;
                }
              if (sub) {
                skip = true;
                break;
              }
            }
            if (!skip)
              bad.push_back(new_bad);
          } else {
            marked.insert(num);
          }
        }

  int n;
  scanf("%d", &n);

  ulint result = 0;

  int nbad = bad.size();
  for (int s = 0; s < (1<<nbad); ++s) {
    vector<int> minv = {0, 0, 0, 0};
    int set_size = 0;
    for (int i = 0; i < nbad; ++i)
      if (s & (1<<i)) {
        set_size += 1;
        for (int j = 0; j < 4; ++j)
          minv[j] = max(minv[j], bad[i][j]);
      }

    ulint res;

    int n2 = n;
    for (int j = 0; j < 4; ++j) n2 -= minv[j];

    if (n2 < 0) res = 0;
    else {
      ulint vals[3] = {(ulint)(n2 + 3), (ulint)(n2 + 2), (ulint)(n2 + 1)};

      for (int k = 0; k < 3; ++k)
        if (vals[k] % 2 == 0) {
          vals[k] /= 2;
          break;
        }
      for (int k = 0; k < 3; ++k)
        if (vals[k] % 3 == 0) {
          vals[k] /= 3;
          break;
        }

      res = 1;
      for (int k = 0; k < 3; ++k)
        res *= vals[k];
    }

    if (set_size % 2 == 0) result += res;
    else result -= res;
  }

  printf("%llu\n", result);

  return 0;
}