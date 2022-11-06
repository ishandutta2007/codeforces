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
  int n, m;
  scanf("%d %d", &n, &m);
  vector<int> values(2 * n);
  for (int i = 0; i < 2 * n; ++i)
    scanf("%d", &values[i]);
  struct pair_t {
    int i, j;
    int delta;
  };
  vector<int> pair_of(2 * n, -1);
  vector<pair_t> pairs(m);
  for (int i = 0; i < m; ++i) {
    int a, b;
    scanf("%d %d", &a, &b), --a, --b;
    if (values[a] < values[b]) swap(a, b);
    pairs[i] = {a, b, values[a] - values[b]};
    pair_of[a] = b;
    pair_of[b] = a;
  }
  sort(pairs.begin(), pairs.end(), [](const pair_t &lhs, const pair_t &rhs) {
      return lhs.delta > rhs.delta;
    });

  vector<bool> taken(2 * n, false);
  int taken_count = 0;
  int next_pair = 0;

  vector<int> ids(2 * n);
  iota(ids.begin(), ids.end(), 0);
  sort(ids.begin(), ids.end(), [&values](const int &lhs, const int &rhs) {
      return values[lhs] > values[rhs];
    });
  int next_id = 0;

  int turn;
  scanf("%d", &turn);

  if (turn == 2) turn = 0;

  while (taken_count < 2 * n) {
    if (turn == 1) {
      while (next_pair < m && taken[pairs[next_pair].i])
        ++next_pair;
      if (next_pair < m) {
        printf("%d\n", pairs[next_pair].i + 1);
        fflush(stdout);

        int ans;
        scanf("%d", &ans);
        assert(ans == pairs[next_pair].j + 1);

        taken[pairs[next_pair].i] = true;
        taken[pairs[next_pair].j] = true;
        taken_count += 2;
      } else {
        while (next_id < 2 * n && taken[ids[next_id]])
          ++next_id;
        assert(next_id < 2 * n);
        assert(!taken[ids[next_id]]);
        printf("%d\n", ids[next_id] + 1);
        fflush(stdout);
        taken[ids[next_id]] = true;
        taken_count += 1;
        turn ^= 1;
      }
    } else {
      int id;
      scanf("%d", &id);
      --id;

      taken[id] = true;
      taken_count += 1;

      if (pair_of[id] != -1) {
        assert(!taken[pair_of[id]]);
        printf("%d\n", pair_of[id] + 1);
        fflush(stdout);

        taken[pair_of[id]] = true;
        taken_count += 1;
      } else {
        turn ^= 1;
      }
    }
  }

  return 0;
}