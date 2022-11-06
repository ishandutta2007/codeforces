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

bool is_prefix(const vector<int> &a, const vector<int> &b) {
  if (a.size() > b.size())
    return false;
  for (int i = 0; i < (int)a.size(); ++i)
    if (a[i] != b[i])
      return false;
  return true;
}

void dfs(int v, vector<bool> &mark, const vector<vector<int>> &implies) {
  if (mark[v]) return;
  mark[v] = true;
  for (int u : implies[v])
    dfs(u, mark, implies);
}

int main() {
  int n, nletter;
  scanf("%d %d", &n, &nletter);
  vector<vector<int>> seq(n);
  for (int i = 0; i < n; ++i) {
    int len;
    scanf("%d", &len);
    seq[i].resize(len);
    for (int j = 0; j < len; ++j)
      scanf("%d", &seq[i][j]), --seq[i][j];
  }
  vector<vector<int>> implies(nletter);
  vector<int> must, must_not;
  bool ok = true;
  for (int i = 0; i + 1 < n; ++i) {
    if (seq[i] == seq[i + 1]) {
    } else if (is_prefix(seq[i], seq[i + 1])) {
    } else if (is_prefix(seq[i + 1], seq[i])) {
      ok = false;
      break;
    } else {
      int differ_at = 0;
      while (seq[i][differ_at] == seq[i + 1][differ_at])
        ++differ_at;
      const int a = seq[i][differ_at], b = seq[i + 1][differ_at];
      if (a < b) {
        implies[b].push_back(a);
      } else {
        must.push_back(a);
        must_not.push_back(b);
      }
    }
  }
  vector<bool> mark(nletter, false);
  if (ok) {
    for (int v : must)
      dfs(v, mark, implies);
    for (int v : must_not)
      if (mark[v]) {
        ok = false;
        break;
      }
  }
  if (ok) {
    vector<int> result;
    for (int v = 0; v < nletter; ++v)
      if (mark[v])
        result.push_back(v);
    printf("Yes\n");
    printf("%d\n", (int)result.size());
    if (!result.empty()) {
      for (int i = 0; i < (int)result.size(); ++i) {
        if (i > 0) printf(" ");
        printf("%d", result[i] + 1);
      }
      printf("\n");
    }
  } else {
    printf("No\n");
  }
  return 0;
}