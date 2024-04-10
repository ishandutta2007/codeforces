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

struct edge_t {
  int u;
  int weight;
};

vector<int> root;
vector<int> path_xor;
vector<int> cntsize;
vector<vector<int>> full_cnt;

int main() {
  int nq;
  scanf("%d", &nq);

  map<int, int> value2idp1;
  auto get_id = [&](int val) {
    int &idp1 = value2idp1[val];
    if (idp1 == 0) {
      int new_id = value2idp1.size() - 1;
      idp1 = new_id + 1;

      root.push_back(new_id);
      path_xor.push_back(0);
      cntsize.push_back(1);
      full_cnt.push_back({new_id});
    }
    return idp1 - 1;
  };

  int last_answer = 0;
  for (int q = 0; q < nq; ++q) {
    int kind;
    scanf("%d", &kind);
    if (kind == 1) {
      int l, r, x;
      scanf("%d %d %d", &l, &r, &x);
      l ^= last_answer;
      r ^= last_answer;
      x ^= last_answer;
      if (l > r) swap(l, r);
      ++r;

      int l_id = get_id(l), r_id = get_id(r);
      if (root[l_id] != root[r_id]) {
        if (cntsize[root[l_id]] < cntsize[root[r_id]])
          swap(l_id, r_id);

        int rl = root[l_id], rr = root[r_id];

        cntsize[rl] += cntsize[rr];

        int path_xor_r_id = path_xor[r_id];
        for (int other : full_cnt[rr]) {
          root[other] = rl;

          path_xor[other] = (path_xor[other] ^ path_xor_r_id) ^ x ^ path_xor[l_id];

          full_cnt[rl].push_back(other);
        }
        full_cnt[rr].clear();
      }
    } else {
      int l, r;
      scanf("%d %d", &l, &r);
      l ^= last_answer;
      r ^= last_answer;
      if (l > r) swap(l, r);
      ++r;

      int l_id = get_id(l), r_id = get_id(r);

      int result;
      if (root[l_id] == root[r_id]) {
        result = path_xor[l_id] ^ path_xor[r_id];
      } else {
        result = -1;
      }

      printf("%d\n", result);
      if (result != -1) last_answer = result;
      else last_answer = 1;
    }
  }
  return 0;
}