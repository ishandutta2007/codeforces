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

lint gcd(lint a, lint b) {
  if (a == 0) return b;
  return gcd(b%a, a);
}

constexpr int maxn = 2e5, maxlogn = 17;

lint gcd_table[maxlogn + 1][maxn];

int solve(const vector<lint> &values) {
  int n = values.size();

  for (int i = 0; i < n; ++i)
    gcd_table[0][i] = values[i];
  for (int l = 1; (1<<l) <= n; ++l)
    for (int i = 0; i + (1<<l) <= n; ++i) {
      gcd_table[l][i] = gcd(gcd_table[l - 1][i],
                            gcd_table[l - 1][i + (1<<(l - 1))]);
    }

  int maxl = 0;
  while ((1<<(maxl + 1)) <= n)
    ++maxl;

  int result = 0;
  for (int i = 0; i < n; ++i) {
    lint cur_gcd = values[i];
    int next = i + 1;
    for (int l = maxl; l >= 0; --l)
      if (next < n && next + (1<<l) <= n) {
        lint cand_g = gcd(cur_gcd, gcd_table[l][next]);
        if (cand_g > 1) {
          cur_gcd = cand_g;
          next += (1<<l);
        }
      }
    if (cur_gcd > 1) {
      result = max(result, next - i);
    }
  }
  return result;
}

int main() {
  int nt;
  scanf("%d", &nt);
  for (int t = 0; t < nt; ++t) {
    int n;
    scanf("%d", &n);
    vector<lint> values(n);
    for (int i = 0; i < n; ++i)
      scanf("%lld", &values[i]);

    if (n == 1) {
      printf("1\n");
      continue;
    }

    vector<lint> diffs(n - 1);
    for (int i = 0; i + 1 < n; ++i)
      diffs[i] = abs(values[i] - values[i + 1]);
    int res = 1 + solve(diffs);
    printf("%d\n", res);
  }
  return 0;
}