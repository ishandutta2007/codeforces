#include <algorithm>
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
#include <numeric>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long lint;

struct Bit {
  int n;
  vector<int> node;
  Bit(int n): n(n), node(n+1) {}
  void update(int i, int delta) {
    for (++i; i <= n; i += i&-i)
      node[i] += delta;
  }
  int query(int i) {
    int res = 0;
    for (++i; i > 0; i -= i&-i)
      res += node[i];
    return res;
  }
};

int main() {
  int nq;
  scanf("%d", &nq);
  vector<int> result(nq, -1);

  vector<int> times;

  struct query_t {
    int kind, when, value, id;
  };
  vector<query_t> queries(nq);
  for (int i = 0; i < nq; ++i) {
    query_t &q = queries[i];
    scanf("%d %d %d", &q.kind, &q.when, &q.value);
    q.id = i;
    times.push_back(q.when);
  }

  sort(times.begin(), times.end());
  times.resize(unique(times.begin(), times.end())-times.begin());
  for (int i = 0; i < nq; ++i)
    queries[i].when = lower_bound(times.begin(), times.end(), queries[i].when) - times.begin();

  Bit bit(times.size());

  stable_sort(queries.begin(), queries.end(), [](const query_t &a, const query_t &b) {
      return a.value < b.value;
    });
  for (int j = 0, i = j; i != (int)queries.size(); i = j) {
    while (j < (int)queries.size() && queries[j].value == queries[i].value) ++j;
    for (int k = i; k < j; ++k) {
      if (queries[k].kind == 1) {
	bit.update(queries[k].when, +1);
      } else if (queries[k].kind == 2) {
	bit.update(queries[k].when, -1);
      } else {
	int res = bit.query(queries[k].when);
	result[queries[k].id] = res;
      }
    }
    for (int k = i; k < j; ++k) {
      if (queries[k].kind == 1) {
	bit.update(queries[k].when, -1);
      } else if (queries[k].kind == 2) {
	bit.update(queries[k].when, +1);
      } else {
      }
    }
  }

  for (int i = 0; i < nq; ++i)
    if (result[i] != -1)
      printf("%d\n", result[i]);

  return 0;
}