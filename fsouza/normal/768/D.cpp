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
typedef long double ldouble;

const ldouble E = 1e-11L;

int main() {
  int n, nq;
  scanf("%d %d", &n, &nq);
  struct query_t {
    int want_prob, id, result;
  };
  vector<query_t> queries(nq);
  for (int q = 0; q < nq; ++q) {
    int want_prob;
    scanf("%d", &want_prob);
    queries[q] = {want_prob, q, -1};
  }
  sort(queries.begin(), queries.end(),
       [](const query_t &a, const query_t &b) {
         return a.want_prob < b.want_prob;
       });

  vector<ldouble> probs(n + 1), next_probs(n + 1);
  int result = 0;
  fill(probs.begin(), probs.end(), 0.0);
  probs[0] = 1.0L;

  for (int q = 0; q < nq; ++q) {
    while (probs[n] < queries[q].want_prob / 2000.0 - E) {
      fill(next_probs.begin(), next_probs.end(), 0.0);
      for (int have = 0; have < n; ++have) {
        next_probs[have + 1] += probs[have] * (1.0L * (n - have) / n);
        next_probs[have] += probs[have] * (1.0L * have / n);
      }
      next_probs[n] += probs[n];
      swap(next_probs, probs);
      ++result;
    }
    queries[q].result = result;
  }
  sort(queries.begin(), queries.end(),
       [](const query_t &a, const query_t &b) {
         return a.id < b.id;
       });
  for (int q = 0; q < nq; ++q)
    printf("%d\n", queries[q].result);

  return 0;
}