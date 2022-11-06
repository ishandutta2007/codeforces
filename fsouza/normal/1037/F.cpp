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

const int mod = 1e9 + 7;

template<typename T, class Cmp=greater<T> >
struct rmq_t {
  Cmp cmp; vector<vector<T>> table;
  rmq_t() {}
  rmq_t(const vector<T> &values, Cmp _cmp = Cmp()): cmp(_cmp) {
    table.push_back(values);
    for (int l = 1; l <= (int)__lg(values.size()); ++l) {
      table.push_back(vector<T>(values.size() - (1<<l) + 1));
      for (int i = 0; i+(1<<l) <= (int)values.size(); ++i)
	table[l][i] = min(table[l-1][i], table[l-1][i+(1<<(l-1))], cmp);
    }
  }
  T query(int a, int b) {
    int size = b-a+1, l = __lg(size);
    return min(table[l][a], table[l][b-(1<<l)+1], cmp);
  }
};

struct state_t {
  lint total = 0LL;
  stack<pair<int, int>, vector<pair<int, int>>> blocks;
};

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  vector<int> values(n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &values[i]);
  rmq_t<int> rmq(values);

  vector<state_t> states(k);

  int result = 0;

  for (int i = n - 1; i >= 0; --i) {
    state_t &st = states[i % (k - 1)];
    int end = i + k - 1;
    int rv = rmq.query(i, min(end, n - 1));

    if (end >= n) {
      continue;
    }

    int size = 1;
    while (!st.blocks.empty() && st.blocks.top().first <= rv) {
      st.total -= (lint)st.blocks.top().first * st.blocks.top().second;
      size += st.blocks.top().second;
      st.blocks.pop();
    }

    st.blocks.emplace(rv, size);
    st.total += (lint)rv * size;

    result = ((lint)result + st.total) % mod;
  }

  printf("%d\n", result);

  return 0;
}