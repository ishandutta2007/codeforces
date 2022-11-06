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

const int mod = 998244353;
const int maxn = 100000, maxk = 100000;

int modpow(int x, int y, int m) {
  int ret = 1 % m, x2p = x;
  while (y > 0) {
    if (y % 2) ret = (lint)ret * x2p % m;
    y /= 2;
    x2p = (lint)x2p * x2p % m;
  }
  return ret;
}

int inv(int a, int p) { return modpow(a, p - 2, p); }

vector<int> fact, inv_fact;

void prepare_binom(int lim) {
  fact.resize(lim + 1);
  fact[0] = 1;
  for (int i = 1; i <= lim; ++i)
    fact[i] = (lint)i * fact[i - 1] % mod;

  inv_fact.resize(lim + 1);
  inv_fact[lim] = inv(fact[lim], mod);
  for (int i = lim - 1; i >= 0; --i)
    inv_fact[i] = (lint)(i + 1) * inv_fact[i + 1] % mod;
}

int binom(int a, int b) {
  if (!(0 <= b && b <= a)) return 0;
  return (lint)fact[a] * inv_fact[b] % mod * inv_fact[a - b] % mod;
}

int main() {
  prepare_binom(maxn + maxk);
  vector<int> inv(maxn + maxk + 1, -1);
  for (int v = 1; v < (int)inv.size(); ++v)
    inv[v] = (lint)inv_fact[v] * fact[v - 1] % mod;

  int n, m, nq;
  scanf("%d %d %d", &n, &m, &nq);

  vector<int> total_count(m, 0);
  vector<int> values(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &values[i]), --values[i];
    total_count[values[i]] += 1;
  }

  struct query_t {
    int l, r, k, id;
    int result = -1;
  };
  vector<query_t> queries(nq);
  for (int q = 0; q < nq; ++q) {
    int l, r, k;
    scanf("%d %d %d", &l, &r, &k), --l, --r;
    queries[q] = {l, r, k, q};
  }

  vector<int> count(m, 0);
  vector<int> len_mult(n + 1, 0);

  sort(queries.begin(), queries.end(),
       [](const query_t &lhs, const query_t &rhs) { return lhs.k < rhs.k; });
  for (int j = 0, i = j; i < (int)queries.size(); i = j) {
    while (j < (int)queries.size() && queries[j].k == queries[i].k) ++j;
    const int k = queries[i].k;

    const lint s = n + (lint)k * m;
    len_mult[n] = 1;
    for (int len = n - 1; len >= 1; --len)
      len_mult[len] = (lint)len_mult[len + 1] * ((s - len) % mod) % mod;

    const int group_size = ceil(n / sqrt(j - i));
    sort(queries.begin() + i, queries.begin() + j,
         [&](const query_t &lhs, const query_t &rhs) {
           if (lhs.l / group_size != rhs.l / group_size)
             return lhs.l < rhs.l;
           return lhs.r < rhs.r;
         });

    int mult1 = 1;
    auto add = [&](int v) {
      mult1 = (lint)mult1 * (total_count[v] + k - count[v]) % mod;
      ++count[v];
    };

    auto del = [&](int v) {
      --count[v];
      mult1 = (lint)mult1 * inv[total_count[v] + k - count[v]] % mod;
    };

    int l = 0, r = -1;
    for (int w = i; w < j; ++w) {
      query_t &q = queries[w];

      while (r < q.r) add(values[++r]);
      while (l > q.l) add(values[--l]);
      while (r > q.r) del(values[r--]);
      while (l < q.l) del(values[l++]);

      q.result = (lint)mult1 * len_mult[q.r - q.l + 1] % mod;
    }
    fill(count.begin(), count.end(), 0);
  }

  sort(queries.begin(), queries.end(),
       [](const query_t &lhs, const query_t &rhs) { return lhs.id < rhs.id; });
  for (const query_t &q : queries)
    printf("%d\n", q.result);

  return 0;
}