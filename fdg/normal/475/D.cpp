#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int arr[100005];

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b);}

int g[18][100005];
int ind[100005];

int get(int l, int r) {
  if (l == r) return arr[l];
  int t = ind[r - l + 1];
  return gcd(g[t][l], g[t][r - (1<<t) + 1]);
}

map<int, long long> f;

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &arr[i]);
    g[0][i] = arr[i];
  }
  for (int t = 1; t < 18; ++t) {
    for (int i = 0; i + (1<<t) <= n; ++i) {
      g[t][i] = gcd(g[t - 1][i], g[t - 1][i + (1<<t) / 2]);
    }
  }
  for (int t = 0; t < 17; ++t) {
    for (int i = (1<<t); i < (2<<t) && i <= n + 1; ++i)
      ind[i] = t;
  }
  // cout << get(1, 1) << endl;

  for (int i = 0; i < n; ++i) {
    int cg = arr[i], b = i;
    while (b < n) {
      int l = b, r = n;
      while (r - l > 1) {
        int m = (l + r) >> 1;
        if (get(i, m) != cg) r = m;
        else l = m;
      }
      f[cg] += (r - b);
      b = r;
      cg = get(i, b);
    }
  }

  int q, x;
  scanf("%d", &q);
  while (q--) {
    scanf("%d", &x);
    printf("%I64d\n", f[x]);
  }
  return 0;
}