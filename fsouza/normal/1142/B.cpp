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
  int n, m, nq;
  scanf("%d %d %d", &n, &m, &nq);
  vector<int> perm(n), inv_perm(n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &perm[i]), --perm[i];
  for (int i = 0; i < n; ++i)
    inv_perm[perm[i]] = i;

  vector<int> seq(m);
  for (int i = 0; i < m; ++i) {
    scanf("%d", &seq[i]), --seq[i];
    seq[i] = inv_perm[seq[i]];
  }

  vector<int> to_left(m), to_right(m);
  {
    vector<int> last(n, -1);
    for (int i = 0; i < m; ++i) {
      if (seq[i] == 0) to_left[i] = i;
      else {
        int prev = last[seq[i] - 1];
        if (prev == -1) to_left[i] = -1;
        else to_left[i] = to_left[prev];
      }
      last[seq[i]] = i;
    }
  }
  {
    vector<int> last(n, m);
    for (int i = m - 1; i >= 0; --i) {
      if (seq[i] == n - 1) to_right[i] = i;
      else {
        int next = last[seq[i] + 1];
        if (next == m) to_right[i] = m;
        else to_right[i] = to_right[next];
      }
      last[seq[i]] = i;
    }
  }

  vector<vector<int>> positions(n);
  for (int i = 0; i < m; ++i)
    positions[seq[i]].push_back(i);

  vector<int> smallest_end(m, m);
  for (int i = 0; i < m; ++i) {
    if (to_right[i] == m) continue;
    if (seq[i] == 0) smallest_end[i] = min(smallest_end[i], to_right[i]);
    else {
      vector<int> &prevs = positions[seq[i] - 1];
      if (prevs.empty()) continue;

      int l = 0, r = (int)prevs.size();
      while (l < r) {
        int mid = l + (r - l) / 2;
        int pos = prevs[mid];
        int from = to_left[pos];
        if (from > to_right[i]) r = mid;
        else l = mid + 1;
      }

      if (l != (int)prevs.size()) {
        int pos = prevs[l];
        int from = to_left[pos];
        assert(from > to_right[i]);
        smallest_end[i] = min(smallest_end[i], pos);
      }
    }
  }

  struct query_t {
    int l, r;
    int id;
    bool result;
  };
  vector<query_t> queries(nq);
  for (int qid = 0; qid < nq; ++qid) {
    query_t &q = queries[qid];
    q.id = qid;
    scanf("%d %d", &q.l, &q.r), --q.l, --q.r;
  }
  sort(queries.begin(), queries.end(),
       [](const query_t &lhs, const query_t &rhs) { return lhs.l > rhs.l; });

  int cur_l = m - 1;
  int best_end = m;
  for (query_t &q : queries) {
    while (cur_l >= q.l) {
      best_end = min(best_end, smallest_end[cur_l]);
      --cur_l;
    }
    q.result = (q.r >= best_end);
  }

  sort(queries.begin(), queries.end(),
       [](const query_t &lhs, const query_t &rhs) { return lhs.id < rhs.id; });
  for (query_t &q : queries)
    printf("%d", (int)q.result);
  printf("\n");

  return 0;
}