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

const lint ten18 = 1000000000000000000LL;

int main() {
  int n;
  scanf("%d", &n);
  vector<lint> start(n);
  for (int i = 0; i < n; ++i)
    scanf("%lld", &start[i]);
  sort(start.begin(), start.end());

  vector<lint> limit(n);
  for (int i = 0; i + 1 < n; ++i)
    limit[i] = start[i + 1] - start[i];
  limit[n - 1] = 2LL * ten18 + 1;

  vector<pair<lint, int>> limits(n);
  for (int i = 0; i < n; ++i)
    limits[i] = {limit[i], i};
  sort(limits.begin(), limits.end());

  int nq;
  scanf("%d", &nq);
  struct query_t {
    lint size;
    int id;
    lint result;
  };
  vector<query_t> queries(nq);
  for (int q = 0; q < nq; ++q) {
    lint l, r;
    scanf("%lld %lld", &l, &r);
    queries[q].size = r - l + 1;
    queries[q].id = q;
    queries[q].result = -1LL;
  }
  sort(queries.begin(), queries.end(),
       [](const query_t &lhs, const query_t &rhs) {
         return lhs.size < rhs.size;
       });

  lint cur_result = 0LL;
  lint cur_size = 0LL;
  int cur_limit = 0;

  for (query_t &q : queries) {
    while (cur_limit < n && limits[cur_limit].first <= q.size) {
      lint next_size = limits[cur_limit].first;
      cur_result += (next_size - cur_size) * (n - cur_limit);
      cur_size = next_size;
      ++cur_limit;
    }

    cur_result += (q.size - cur_size) * (n - cur_limit);
    cur_size = q.size;
    q.result = cur_result;
  }

  sort(queries.begin(), queries.end(),
       [](const query_t &lhs, const query_t &rhs) { return lhs.id < rhs.id; });

  for (int qid = 0; qid < nq; ++qid) {
    if (qid > 0) printf(" ");
    printf("%lld", queries[qid].result);
  }
  printf("\n");

  return 0;
}