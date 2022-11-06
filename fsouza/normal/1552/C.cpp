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
    int n, k;
    scanf("%d %d", &n, &k);
    struct chord_t {
      int a, b;
    };
    vector<chord_t> chords(k);
    vector<bool> used(2 * n, false);
    for (int i = 0; i < k; ++i) {
      scanf("%d %d", &chords[i].a, &chords[i].b), --chords[i].a, --chords[i].b;
      if (chords[i].a > chords[i].b)
        swap(chords[i].a, chords[i].b);
      used[chords[i].a] = true;
      used[chords[i].b] = true;
    }
    vector<int> available;
    for (int i = 0; i < 2 * n; ++i)
      if (!used[i])
        available.push_back(i);
    for (int j = 0; j + (n - k) < (int)available.size(); ++j)
      chords.push_back({available[j], available[j + (n - k)]});
    assert((int)chords.size() == n);

    int result = 0;
    for (int i = 0; i < n; ++i)
      for (int j = i + 1; j < n; ++j) {
        bool first = chords[i].a <= chords[j].a && chords[j].a <= chords[i].b;
        bool second = chords[i].a <= chords[j].b && chords[j].b <= chords[i].b;
        if (first != second)
          ++result;
      }
    printf("%d\n", result);
  }
  return 0;
}