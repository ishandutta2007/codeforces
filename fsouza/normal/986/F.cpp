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
typedef __float128 ldouble;
typedef unsigned long long ulint;

const ldouble E = pow((long double)10.0, (long double)-13.0);
const int sqrt_maxk = 31622777;

lint egcd(lint a, lint b, lint &x, lint &y) {
  if (a == 0) {
    x = 0, y = 1;
    return b;
  } else {
    lint g = egcd(b % a, a, y, x);
    x -= y * (b / a);
    return g;
  }
}

template <typename T>
T my_abs(T v) {
  return v < 0 ? -v : v;
}

template <typename T>
T my_ceil(T v) {
  T x = ceil((long double)v) - 1.0;
  while (x < v) x += 1.0;
  return x;
}

template <typename T>
T my_floor(T v) {
  T x = floor((long double)v) + 1.0;
  while (x > v) x -= 1.0;
  return x;
}

ldouble mod1(ldouble v) { return v - my_floor(v); }

vector<bool> is_prime;
vector<int> primes;
void run_sieve(int limit) {
  is_prime.resize(limit + 1, false);
  for (int v = 2; v <= limit; ++v) is_prime[v] = true;
  for (int v = 2; v <= limit; ++v)
    if (is_prime[v]) {
      primes.push_back(v);
      for (int u = v + v; u <= limit; u += v)
        is_prime[u] = false;
    }
}

vector<lint> get_primes(lint value) {
  vector<lint> result;
  for (int p : primes) {
    if ((lint)p * p > value) break;
    if (value % p == 0) {
      result.push_back(p);
      while (value % p == 0) value /= p;
    }
  }
  if (value > 1) {
    result.push_back(value);
    value = 1;
  }
  return result;
}

int main() {
  run_sieve(sqrt_maxk);

  int nq;
  scanf("%d", &nq);
  struct query_t {
    lint n, k;
    int id;
    bool result;
  };
  vector<query_t> queries(nq);
  for (int q = 0; q < nq; ++q) {
    lint n, k;
    scanf("%lld %lld", &n, &k);
    queries[q] = {n, k, q, false};
  }
  sort(queries.begin(), queries.end(),
       [](const query_t &a, const query_t &b) { return a.k < b.k; });
  for (int qj = 0, qi = qj; qi < nq; qi = qj) {
    while (qj < nq && queries[qj].k == queries[qi].k) ++qj;
    const lint k = queries[qi].k;
    vector<lint> primes_k = get_primes(k);
    if (primes_k.size() == 0) {
    } else if (primes_k.size() == 1) {
      for (int qk = qi; qk < qj; ++qk)
        queries[qk].result = (queries[qk].n % primes_k[0] == 0);
    } else if (primes_k.size() == 2) {
      lint pa = primes_k[0], pb = primes_k[1];
      lint x, y;
      lint _g = egcd(pa, pb, x, y);
      assert(_g == 1);
      assert((ulint)pa * x + (ulint)pb * y == (ulint)1);
      ldouble m0 = (ldouble)-x / pb, m1 = (ldouble)y / pa;
      if (m0 < 0.0) {
        m0 *= -1.0, m1 *= -1.0;
        swap(m0, m1);
      }
      assert(m0 <= m1);

      for (int qk = qi; qk < qj; ++qk) {
        query_t &query = queries[qk];
        if (query.n >= pa * pb) {
          query.result = true;
        } else {
          ldouble v0 = m0 * query.n, v1 = m1 * query.n;
          query.result = (my_ceil(v0 - E) <= v1 + E);
        }
      }
    } else if (primes_k.size() == 3) {
      sort(primes_k.begin(), primes_k.end());
      lint pc = primes_k[0], pa = primes_k[1], pb = primes_k[2];
      lint x, y;
      lint _g = egcd(pa, pb, x, y);
      assert(_g == 1);
      ldouble m0 = (ldouble)-x / pb, m1 = (ldouble)y / pa;
      if (m0 < 0.0) {
        m0 *= -1.0, m1 *= -1.0;
        swap(m0, m1);
      }
      assert(m0 <= m1);
      for (int qk = qi; qk < qj; ++qk) {
        query_t &query = queries[qk];
        if (query.n >= pc * pa) {
          query.result = true;
        } else {
          lint max_mc = query.n / pc;
          lint div = 1;
          while (((div + 1) - 1) * (div + 1) + ((div + 1) - 1) <= max_mc)
            ++div;
          for (lint mc = (div - 1) * div + (div - 1) + 1; mc <= max_mc; ++mc) {
            ldouble v0 = m0 * (query.n - mc * pc);
            ldouble v1 = m1 * (query.n - mc * pc);
            if (my_ceil(v0 - E) <= v1 + E) {
              query.result = true;
              break;
            }
          }
          if (query.result == true) continue;

          struct partial_t {
            ldouble start, size;
            bool operator<(const partial_t &o) const { return start < o.start; }
          };

          vector<partial_t> rests(div);
          for (lint rest = 0; rest < div; ++rest) {
            ldouble pre_v0 = m0 * (-rest * pc);
            ldouble pre_v1 = m1 * (-rest * pc);
            ldouble start = mod1(pre_v0), size = pre_v1 - pre_v0;
            if (my_abs(start) <= E) start += 1.0;
            rests[rest] = {start, size};
          }
          sort(rests.begin(), rests.end());

          vector<ldouble> max_pref_sum(div + 1);
          max_pref_sum[0] = -1e50;
          for (int i = 0; i < div; ++i) {
            max_pref_sum[i + 1] =
                max(max_pref_sum[i], rests[i].start + rests[i].size);
          }

          vector<ldouble> max_suf_sum(div + 1);
          max_suf_sum[div] = -1e50;
          for (int i = div - 1; i >= 0; --i) {
            max_suf_sum[i] =
                max(max_suf_sum[i + 1], rests[i].start + rests[i].size);
          }

          vector<partial_t> quos(div);
          for (lint quo = 0; quo < div; ++quo) {
            ldouble pre_v0 = m0 * (query.n - quo * div * pc);
            ldouble pre_v1 = m1 * (query.n - quo * div * pc);
            ldouble start = mod1(pre_v0), size = pre_v1 - pre_v0;
            if (my_abs(start) <= E) start += 1.0;
            quos[quo] = {start, size};
          }
          sort(quos.begin(), quos.end());

          int j = rests.size() - 1;
          for (int i = 0; i < (int)quos.size(); ++i) {
            while (j >= 0 && rests[j].start + quos[i].start > 1.0 + E)
              --j;

            ldouble best_sum = quos[i].start + quos[i].size +
              max(max_pref_sum[j + 1], max_suf_sum[j + 1] - 1.0);
            if (best_sum >= 1.0 - E) {
              query.result = true;
              break;
            }
          }
        }
      }
    } else {
      sort(primes_k.begin(), primes_k.end());
      int limit = primes_k[0] * primes_k[1];
      vector<ulint> mask((limit + 63) / 64);
      mask[0] |= 1ULL<<0;
      for (int p : primes_k) {
        if (p < 64) {
          for (int i = 0; i + p < limit; ++i)
            if (mask[i / 64] & (1ULL<<(i % 64))) {
              int j = i + p;
              mask[j / 64] |= 1ULL<<(j % 64);
            }
        } else {
          for (int i = 0; i < (int)mask.size(); ++i) {
            int nblock = p / 64, rest = p % 64;
            if (i + nblock < (int)mask.size()) {
              mask[i + nblock] |= (mask[i]<<rest);
            }
            if (i + nblock + 1 < (int)mask.size()) {
              mask[i + nblock + 1] |= (mask[i]>>(64 - rest));
            }
          }
        }
      }

      for (int qk = qi; qk < qj; ++qk) {
        query_t &query = queries[qk];
        if (query.n >= limit) {
          query.result = true;
        } else {
          query.result = ((mask[query.n / 64] & (1ULL << (query.n % 64))) != 0);
        }
      }
    }
  }

  sort(queries.begin(), queries.end(),
       [](const query_t &a, const query_t &b) { return a.id < b.id; });
  for (query_t &q : queries) {
    if (q.result) printf("YES\n");
    else printf("NO\n");
  }

  return 0;
}