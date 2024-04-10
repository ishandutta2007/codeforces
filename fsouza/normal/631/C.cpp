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
#include <vector>

using namespace std;

typedef long long lint;

int main() {
  int n, nq;
  scanf("%d %d", &n, &nq);
  vector<int> values(n);
  for (int i = 0; i < n; ++i) scanf("%d", &values[i]);

  vector<pair<int, int>> queries;
  for (int q = 0; q < nq; ++q) {
    int kind, size;
    scanf("%d %d", &kind, &size);
    pair<int, int> query = {kind, size};
    while (!queries.empty() && queries.back().second <= size)
      queries.pop_back();
    queries.push_back(query);
  }
  nq = queries.size();

  multiset<int> vset;
  for (int i = 0; i < n; ++i) vset.insert(values[i]);

  vector<int> result(n);
  int q = -1;
  for (int i = n-1; i >= 0; --i) {
    while (q+1 < nq && queries[q+1].second > i) ++q;
    int value;
    if (q == -1) value = values[i];
    else if (queries[q].first == 1) value = *vset.rbegin();
    else value = *vset.begin();
    vset.erase(vset.find(value));
    result[i] = value;
  }

  for (int i = 0; i < n; ++i) {
    if (i > 0) printf(" ");
    printf("%d", result[i]);
  }
  printf("\n");
  
  return 0;
}