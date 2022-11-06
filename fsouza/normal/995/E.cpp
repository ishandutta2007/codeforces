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

int modpow(int x, int y, int mod) {
  int ret = 1 % mod, x2p = x;
  while (y > 0) {
    if (y % 2) ret = (lint)ret * x2p % mod;
    y /= 2;
    x2p = (lint)x2p * x2p % mod;
  }
  return ret;
}

int main() {
  int a, b, p;
  scanf("%d %d %d", &a, &b, &p);

  struct state_t {
    int dist, op, prev;
  };

  queue<int> qa, qb;
  map<int, state_t> statea, stateb;

  qa.push(a);
  statea[a] = {0, -1, -1};

  qb.push(b);
  stateb[b] = {0, -1, -1};

  int mid = -1;

  while (true) {
    if (!qa.empty()) {
      int va = qa.front(); qa.pop();
      int adj[3] = {va - 1, va + 1, modpow(va, p - 2, p)};
      if (adj[0] < 0) adj[0] += p;
      if (adj[1] >= p) adj[1] -= p;

      state_t &stateva = statea[va];
      for (int i = 0; i < 3; ++i) {
        int ua = adj[i];

        auto insert_result = statea.insert(make_pair(ua, state_t()));
        if (insert_result.second) {
          auto &state = insert_result.first->second;
          state.dist = stateva.dist + 1;
          state.op = i;
          state.prev = va;
          qa.push(ua);

          if (stateb.find(ua) != stateb.end()) {
            mid = ua;
            break;
          }
        }
      }
      if (mid != -1) break;
    }

    if (!qb.empty()) {
      int va = qb.front(); qb.pop();
      int adj[3] = {va - 1, va + 1, modpow(va, p - 2, p)};
      if (adj[0] < 0) adj[0] += p;
      if (adj[1] >= p) adj[1] -= p;

      state_t &stateva = stateb[va];
      for (int i = 0; i < 3; ++i) {
        int ua = adj[i];

        auto insert_result = stateb.insert(make_pair(ua, state_t()));
        if (insert_result.second) {
          auto &state = insert_result.first->second;
          state.dist = stateva.dist + 1;
          state.op = i;
          state.prev = va;
          qb.push(ua);

          if (statea.find(ua) != statea.end()) {
            mid = ua;
            break;
          }
        }
      }
      if (mid != -1) break;
    }
  }
  assert(mid != -1);

  vector<int> ops_a, ops_b;
  {
    int v = mid;
    while (v != a) {
      ops_a.push_back(statea[v].op);
      v = statea[v].prev;
    }
  }
  {
    int v = mid;
    while (v != b) {
      int op = stateb[v].op;
      if (op <= 1) op = 1 - op;
      ops_b.push_back(op);
      v = stateb[v].prev;
    }
  }
  reverse(ops_a.begin(), ops_a.end());
  ops_a.insert(ops_a.end(), ops_b.begin(), ops_b.end());

  printf("%d\n", (int)ops_a.size());
  for (int i = 0; i < (int)ops_a.size(); ++i) {
    int op = ops_a[i];
    if (op <= 1) op = 1 - op;
    if (i > 0) printf(" ");
    printf("%d", op + 1);
  }
  printf("\n");

  return 0;
}