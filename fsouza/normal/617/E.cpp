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

int main() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k), ++n;
  vector<int> values(n);
  values[0] = 0;
  for (int i = 1; i < n; ++i) {
    scanf("%d", &values[i]);
    values[i] ^= values[i-1];
  }

  struct query_t {
    int l, r, id;
  };
  vector<query_t> queries(m);
  for (int i = 0; i < m; ++i) {
    query_t &q = queries[i];
    scanf("%d %d", &q.l, &q.r);
    --q.l;
    q.id = i;
  }

  const int sqn = sqrt(n);
  sort(queries.begin(), queries.end(), [sqn](const query_t &a, const query_t &b) {
      if (a.l/sqn != b.l/sqn) return a.l < b.l;
      return a.r < b.r;
    });

  vector<lint> result(m);

  const int maxv = 1000000;
  lint res = 0;
  int l = 0, r = -1;
  vector<int> manyv(2*maxv+1, 0);

  for (query_t &q : queries) {
    auto add = [&](int i) {
      int want = values[i] ^ k;
      res += manyv[want];
      ++manyv[values[i]];
    };
    auto del = [&](int i) {
      int want = values[i] ^ k;
      --manyv[values[i]];
      res -= manyv[want];
    };
    while (r < q.r) add(++r);
    while (l > q.l) add(--l);
    while (r > q.r) del(r--);
    while (l < q.l) del(l++);
    result[q.id] = res;
  }

  for (lint r : result)
    cout << r << endl;
  
  return 0;
}