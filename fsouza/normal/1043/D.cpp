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
  int len, many;
  scanf("%d %d", &len, &many);
  struct person_t {
    vector<int> perm;
    vector<int> invperm;
  };
  vector<person_t> people(many);
  for (int i = 0; i < many; ++i) {
    person_t &guy = people[i];
    guy.perm.resize(len);
    guy.invperm.resize(len);
    for (int j = 0; j < len; ++j) {
      scanf("%d", &guy.perm[j]), --guy.perm[j];
      guy.invperm[guy.perm[j]] = j;
    }
  }
  lint result = 0LL;
  function<void(int, int)> compute = [&](int l, int r) {
    if (r - l + 1 == 1) {
      result += 1LL;
      return;
    }
    int m = l + (r - l) / 2;

    compute(l, m);
    compute(m + 1, r);

    int limit_l = l, limit_r = r;
    person_t &first = people[0];
    for (int i = 1; i < many; ++i) {
      person_t &guy = people[i];
      if (guy.invperm[first.perm[m]] + 1 != guy.invperm[first.perm[m + 1]]) {
        return;
      }
      int this_limit_r = m + 1;
      while (this_limit_r + 1 <= limit_r &&
             guy.invperm[first.perm[this_limit_r + 1]] == guy.invperm[first.perm[this_limit_r]] + 1) {
        ++this_limit_r;
      }
      int this_limit_l = m;
      while (this_limit_l - 1 >= limit_l &&
             guy.invperm[first.perm[this_limit_l - 1]] == guy.invperm[first.perm[this_limit_l]] - 1) {
        --this_limit_l;
      }
      limit_r = this_limit_r;
      limit_l = this_limit_l;
    }
    result += (lint)(m - limit_l + 1) * (limit_r - (m + 1) + 1);
  };
  compute(0, len - 1);
  printf("%lld\n", result);
  return 0;
}