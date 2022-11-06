#include <algorithm>
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

const int maxn = 100, maxk = 20, mod = 1e9 + 7;

vector<int> adj[maxn];

int has[maxn][maxk+2], need[maxn][maxk];
int hasatleast[maxn][maxk+2], needatleast[maxn][maxk];

void dfs(int v, int p, int k) {
  vector<int> children;
  for (int u : adj[v])
    if (u != p) {
      dfs(u, v, k);
      children.push_back(u);
    }

  memset(has[v], 0, sizeof(has[v]));
  memset(need[v], 0, sizeof(need[v]));

  if (children.empty()) {
    has[v][1] = 1;
    need[v][k-1] = 1;
  } else {
    auto get_nway = [k, &children](int minhas, int minneed) {
      int mult = 1;
      for (int c : children) {
        int sum = 0;
        if (minhas <= k+1) sum += hasatleast[c][max(0, minhas)];
        if (minneed < k) sum += needatleast[c][max(0, minneed)];
        mult = (lint)mult * sum % mod;
      }
      return mult;
    };

    has[v][1] = get_nway(0, 0);

    for (int minhas = 0; minhas <= k+1; ++minhas)
      for (int minneed = 0; minneed < k; ++minneed) {
        lint count = 0;
        count += get_nway(minhas, minneed);
        count -= get_nway(minhas+1, minneed);
        count -= get_nway(minhas, minneed+1);
        count += get_nway(minhas+1, minneed+1);
        count = (count % mod + mod) % mod;

        if (minhas > minneed) {
          if (minneed-1 >= 0)
            need[v][minneed-1] = (need[v][minneed-1] + count) % mod;
        } else {
          has[v][min(minhas+1, k+1)] =
            (has[v][min(minhas+1, k+1)] + count) % mod;
        }
      }

    for (int minhas = 0; minhas <= k+1; ++minhas) {
      lint count = 0;
      count += get_nway(minhas, k);
      count -= get_nway(minhas+1, k);
      count = (count % mod + mod) % mod;
      if (minhas <= k) {
        has[v][min(minhas+1, k+1)] = (has[v][min(minhas+1, k+1)] + count) % mod;
      } else {
        need[v][k-1] = (need[v][k-1] + count) % mod;
      }
    }

    for (int minneed = 0; minneed < k; ++minneed) {
      lint count = 0;
      count += get_nway(k+2, minneed);
      count -= get_nway(k+2, minneed+1);
      count = (count % mod + mod) % mod;
      if (minneed-1 >= 0)
        need[v][minneed-1] = (need[v][minneed-1] + count) % mod;
    }
  }

  hasatleast[v][k+1] = has[v][k+1];
  for (int i = k; i >= 0; --i)
    hasatleast[v][i] = (has[v][i] + hasatleast[v][i+1]) % mod;

  needatleast[v][k-1] = need[v][k-1];
  for (int i = k-2; i >= 0; --i)
    needatleast[v][i] = (need[v][i] + needatleast[v][i+1]) % mod;
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

  int result;
  if (k == 0) {
    result = 1;
  } else {
    dfs(0, -1, k);
    result = 0;
    for (int i = 0; i <= k+1; ++i)
      result = (result + has[0][i]) % mod;
  }

  printf("%d\n", result);

  return 0;
}