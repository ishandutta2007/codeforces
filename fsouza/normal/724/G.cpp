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
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

#define MAXN 100000

using namespace std;

typedef long long lint;

const int mod = (int)1e9 + 7;

struct edge_t {
  int u;
  lint weight;
};
vector<edge_t> adj[MAXN];
bool mark[MAXN];
lint accxor[MAXN];
int cntsize;
vector<lint> cntaccs;
vector<lint> xors;

void dfs(int v, lint accxorv) {
  mark[v] = true;
  accxor[v] = accxorv;
  ++cntsize;
  cntaccs.push_back(accxorv);
  for (const edge_t &ed : adj[v]) {
    if (mark[ed.u]) {
      lint value = ed.weight ^ (accxorv ^ accxor[ed.u]);
      if (value != 0)
        xors.push_back(value);
    } else {
      dfs(ed.u, accxorv ^ ed.weight);
    }
  }
}

int get_rank(vector<lint> &values) {
  const int n = values.size();
  int i = 0;
  for (int j = 62; j >= 0; --j) {
    int chosen = -1;
    for (int k = i; k < n; ++k)
      if (values[k] & (1LL << j))
        chosen = k;
    if (chosen == -1) continue;
    swap(values[chosen], values[i]);
    chosen = i;
    ++i;
    for (int k = i; k < n; ++k)
      if (values[k] & (1LL << j))
        values[k] ^= values[chosen];
  }
  values.resize(n - count(values.begin(), values.end(), 0LL));
  return values.size();
}

int binom[64+1][64+1];
vector<int> pow2mod, nevensubset;

int calculate(vector<lint> &choose2, vector<lint> &chooseany) {
  int choose2count[63][2];
  int chooseanycount[63][2];
  memset(choose2count, 0, sizeof(choose2count));
  memset(chooseanycount, 0, sizeof(chooseanycount));
  for (lint value : choose2)
    for (int j = 0; j <= 62; ++j)
      if (value & (1LL << j)) ++choose2count[j][1];
      else ++choose2count[j][0];
  for (lint value : chooseany)
    for (int j = 0; j <= 62; ++j)
      if (value & (1LL << j)) ++chooseanycount[j][1];
      else ++chooseanycount[j][0];

  int result = 0;
  for (int j = 0; j <= 62; ++j) {
    int c20 = choose2count[j][0], c21 = choose2count[j][1];
    int cany0 = chooseanycount[j][0], cany1 = chooseanycount[j][1];

    int nwayc20, nwayc21;
    int nwaycany0, nwaycany1;

    nwayc20 = ((lint)c20 * (c20-1) / 2LL + (lint)c21 * (c21-1) / 2LL) % mod;
    nwayc21 = (lint)c20 * c21 % mod;

    nwaycany0 = (lint)pow2mod[cany0] * nevensubset[cany1] % mod;
    nwaycany1 = ((lint)pow2mod[cany0 + cany1] - nwaycany0 + mod) % mod;

    int nway1 = ((lint)nwayc21 * nwaycany0 + (lint)nwayc20 * nwaycany1) % mod;
    result = (result + (lint)nway1 * pow2mod[j]) % mod;
  }

  return result;
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);

  for (int i = 0; i < m; ++i) {
    int a, b;
    lint c;
    scanf("%d %d %lld", &a, &b, &c), --a, --b;
    adj[a].push_back(edge_t{b, c});
    adj[b].push_back(edge_t{a, c});
  }

  pow2mod.resize(64);
  pow2mod[0] = 1;
  for (int i = 1; i < (int)pow2mod.size(); ++i)
    pow2mod[i] = 2 * pow2mod[i-1] % mod;

  for (int a = 0; a <= 64; ++a)
    binom[a][0] = binom[a][a] = 1;
  for (int a = 0; a <= 64; ++a)
    for (int b = 1; b < a; ++b)
      binom[a][b] = (binom[a-1][b] + binom[a-1][b-1]) % mod;

  nevensubset.resize(64, 0);
  for (int i = 0; i < (int)nevensubset.size(); ++i)
    for (int j = 0; j <= i; j += 2)
      nevensubset[i] = (nevensubset[i] + binom[i][j]) % mod;

  int result = 0;

  for (int i = 0; i < n; ++i) {
    if (!mark[i]) {
      cntsize = 0;
      xors.clear();
      cntaccs.clear();
      dfs(i, 0LL);
      get_rank(xors);
      result = (result + calculate(cntaccs, xors)) % mod;
    }
  }

  printf("%d\n", result);

  return 0;
}