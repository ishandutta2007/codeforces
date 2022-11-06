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
  int n, nq;
  scanf("%d %d", &n, &nq);
  vector<int> orig_values(n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &orig_values[i]);
  struct val_t {
    int value;
    bool neg;
    int id;
    int result;
  };
  vector<val_t> vals(n);
  for (int i = 0; i < n; ++i) {
    vals[i] = {abs(orig_values[i]), orig_values[i] < 0, i, -1};
  }
  sort(vals.begin(), vals.end(), [](const val_t &lhs, const val_t &rhs) {
    return lhs.value < rhs.value;
  });
  enum kind_t {
    FLIP,
    SETN,
    SETP,
  };
  struct query_t {
    kind_t kind;
    int l, r;
  };
  vector<query_t> queries;
  for (int qid = 0; qid < nq; ++qid) {
    char op;
    int v;
    scanf(" %c %d", &op, &v);
    if (op == '>') {
      if (v >= 0) {
        queries.push_back({SETN, v + 1, INT_MAX});
      } else {
        queries.push_back({SETN, (-v), INT_MAX});
        if ((-v) - 1 >= 0) {
          queries.push_back({FLIP, 0, (-v) - 1});
        }
      }
    } else {
      if (v <= 0) {
        queries.push_back({SETP, (-v) + 1, INT_MAX});
      } else {
        queries.push_back({SETP, v, INT_MAX});
        if (v - 1 >= 0) {
          queries.push_back({FLIP, 0, v - 1});
        }
      }
    }
  }
  nq = queries.size();
  reverse(queries.begin(), queries.end());
  multiset<int> flips;
  int nflip = 0;
  int next_id = n - 1;
  for (query_t &q : queries) {
    if (q.kind == FLIP) {
      flips.insert(q.r);
    } else {
      while (next_id >= 0 && vals[next_id].value >= q.l) {
        while (!flips.empty() && *flips.rbegin() >= vals[next_id].value) {
          auto it = flips.end();
          --it;
          flips.erase(it);
          ++nflip;
        }

        vals[next_id].result = vals[next_id].value *
          (((nflip % 2) ^ (q.kind == SETP)) ? 1 : -1);

        --next_id;
      }
    }
  }
  while (next_id >= 0) {
    while (!flips.empty() && *flips.rbegin() >= vals[next_id].value) {
      auto it = flips.end();
      --it;
      flips.erase(it);
      ++nflip;
    }

    vals[next_id].result =
        vals[next_id].value * (((nflip % 2) ^ (vals[next_id].neg)) ? -1 : 1);
    --next_id;
  }

  sort(vals.begin(), vals.end(),
       [](const val_t &lhs, const val_t &rhs) { return lhs.id < rhs.id; });

  for (int i = 0; i < n; ++i) {
    if (i > 0) printf(" ");
    printf("%d", vals[i].result);
  }
  printf("\n");

  return 0;
}