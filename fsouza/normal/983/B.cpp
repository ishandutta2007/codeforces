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

const int maxn = 5000;

int values[maxn], f[maxn][maxn], max_f[maxn][maxn];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &values[i]);
    f[i][i] = max_f[i][i] = values[i];
  }
  for (int s = 2; s <= n; ++s)
    for (int i = 0; i + s - 1 < n; ++i) {
      const int j = i + s - 1;
      f[i][j] = f[i + 1][j] ^ f[i][j - 1];
      max_f[i][j] = max({f[i][j], max_f[i + 1][j], max_f[i][j - 1]});
    }
  int nq;
  scanf("%d", &nq);
  for (int q = 0; q < nq; ++q) {
    int l, r;
    scanf("%d %d", &l, &r), --l, --r;
    printf("%d\n", max_f[l][r]);
  }
  return 0;
}