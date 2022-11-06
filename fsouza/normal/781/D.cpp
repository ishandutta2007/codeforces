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

const int maxn = 500, maxl = 61;

int n;

struct matrix_t {
  array<bitset<maxn>, maxn> mat;
  array<bitset<maxn>, maxn> transp;
  void update_transp() {
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        transp[i].set(j, mat[j].test(i));
  }
};

matrix_t mult(const matrix_t &a, const matrix_t &b) {
  matrix_t res;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      res.mat[i].set(j, (a.mat[i] & b.transp[j]).any());
  res.update_transp();
  return res;
}

matrix_t dp[maxl+1][2];

int main() {
  int m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int a, b, kind;
    scanf("%d %d %d", &a, &b, &kind), --a, --b;
    if (kind == 0) dp[0][0].mat[a].set(b, true);
    else dp[0][1].mat[a].set(b, true);
  }
  dp[0][0].update_transp();
  dp[0][1].update_transp();
  for (int l = 1; l <= maxl; ++l)
    for (int inv = 0; inv < 2; ++inv)
      dp[l][inv] = mult(dp[l - 1][inv], dp[l - 1][inv ^ 1]);

  matrix_t ident;
  for (int i = 0; i < n; ++i) {
    ident.mat[i].set(i, true);
    ident.transp[i].set(i, true);
  }

  lint pathlen = 0;
  int inv = 0;
  matrix_t now = ident;
  for (int l = maxl; l >= 0; --l) {
    matrix_t new_res = mult(now, dp[l][inv]);
    if (new_res.mat[0].any()) {
      now = new_res;
      pathlen += 1LL << l;
      inv = inv ^ 1;
    }
  }

  if (pathlen > 1000000000000000000LL) pathlen = -1;
  cout << pathlen << "\n";

  return 0;
}