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

int dfs(int v, vector<vector<int>> &children, vector<int> &many_need) {
  int leaf_count = 0;
  if (children[v].empty()) leaf_count = 1;
  else {
    for (int u : children[v])
      leaf_count += dfs(u, children, many_need);
  }
  many_need[leaf_count] += 1;
  return leaf_count;
}

template<typename T>
ostream &operator<<(ostream &stream, const vector<T> &v) {
  stream << "[";
  for (int i = 0; i < (int)v.size(); ++i) {
    if (i > 0) stream << ", ";
    stream << v[i];
  }
  stream << "]";
  return stream;
}

int main() {
  int n;
  scanf("%d", &n);
  vector<vector<int>> children(n);
  for (int i = 1; i < n; ++i) {
    int p;
    scanf("%d", &p), --p;
    children[p].push_back(i);
  }
  vector<int> many_need(n + 1);
  dfs(0, children, many_need);

  vector<int> many_with_c(n + 1, 0);
  many_with_c[0] = many_need[0];
  for (int c = 1; c <= n; ++c)
    many_with_c[c] = many_need[c] + many_with_c[c - 1];

  vector<int> answer(n + 1, n);
  for (int c = 0; c <= n; ++c)
    answer[many_with_c[c]] = min(answer[many_with_c[c]], c);
  for (int m = n; m - 1 >= 0; --m)
    answer[m - 1] = min(answer[m - 1], answer[m]);

  for (int m = 1; m <= n; ++m) {
    if (m > 1) printf(" ");
    printf("%d", answer[m]);
  }
  printf("\n");

  return 0;
}