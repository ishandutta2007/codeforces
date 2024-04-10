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

#define MAXN 200000

using namespace std;

typedef long long lint;

struct distsum_t {
  int k;
  vector<int> many;
  vector<lint> distsum;
  distsum_t() {}
  distsum_t(int _k): k(_k), many(k, 0), distsum(k, 0LL) {}
  distsum_t &operator += (const distsum_t &o) {
    for (int i = 0; i < k; ++i) {
      many[i] += o.many[i];
      distsum[i] += o.distsum[i];
    }
    return *this;
  }
  distsum_t &operator -= (const distsum_t &o) {
    for (int i = 0; i < k; ++i) {
      many[i] -= o.many[i];
      distsum[i] -= o.distsum[i];
    }
    return *this;
  }
  distsum_t increasing(lint delta) const {
    distsum_t result = *this;

    for (int i = 0; i < k; ++i)
      result.distsum[i] += delta * result.many[i];

    int new0 = (k - delta % k) % k;
    rotate(result.many.begin(), result.many.begin() + new0, result.many.end());
    rotate(result.distsum.begin(), result.distsum.begin() + new0,
           result.distsum.end());

    return result;
  }
};

vector<int> adj[MAXN];
distsum_t downsum[MAXN], upsum[MAXN], totalsum[MAXN];

void dfs1(int v, int p, int k) {
  downsum[v] = distsum_t(k);

  downsum[v].many[0] += 1;
  downsum[v].distsum[0] += 0;

  for (int u : adj[v])
    if (u != p) {
      dfs1(u, v, k);
      downsum[v] += downsum[u].increasing(1);
    }
}

void dfs2(int v, int p, int k) {
  if (p == -1) {
    upsum[v] = distsum_t(k);

    upsum[v].many[0] += 1;
    upsum[v].distsum[0] += 0;
  } else {
    upsum[v] = totalsum[p];
    upsum[v] -= downsum[v].increasing(1);
    upsum[v] = upsum[v].increasing(1);

    upsum[v].many[0] += 1;
    upsum[v].distsum[0] += 0;
  }

  totalsum[v] = upsum[v];
  totalsum[v] += downsum[v];

  totalsum[v].many[0] -= 1;
  totalsum[v].distsum[0] -= 0;

  for (int u : adj[v])
    if (u != p) {
      dfs2(u, v, k);
    }
}

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n-1; ++i) {
    int a, b;
    scanf("%d %d", &a, &b), --a, --b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  dfs1(0, -1, k);
  dfs2(0, -1, k);

  lint result = 0;

  for (int i = 0; i < n; ++i) {
    result += totalsum[i].distsum[0];
    for (int r = 1; r < k; ++r)
      result += totalsum[i].distsum[r] + (lint)(k-r) * totalsum[i].many[r];
  }
  assert(result % k == 0);
  result /= k;
  assert(result % 2 == 0);
  result /= 2;

  printf("%lld\n", result);

  return 0;
}