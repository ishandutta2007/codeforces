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

int main() {
  int nt;
  scanf("%d", &nt);
  for (int t = 0; t < nt; ++t) {
    int n;
    scanf("%d", &n);

    vector<int> a(n);
    for (int &v : a) scanf("%d", &v);
    sort(a.begin(), a.end());
    vector<int> acc_a(n + 1, 0);
    for (int i = 0; i < n; ++i)
      acc_a[i + 1] = acc_a[i] + a[i];

    vector<int> b(n);
    for (int &v : b) scanf("%d", &v);
    sort(b.begin(), b.end());
    vector<int> acc_b(n + 1, 0);
    for (int i = 0; i < n; ++i)
      acc_b[i + 1] = acc_b[i] + b[i];

    int extra_l = 0, extra_r = n;
    while (extra_l < extra_r) {
      int extra = (extra_l + extra_r) / 2;
      int total = n + extra;
      int nget = total - total/4;

      int score1 = 100 * min(nget, extra);
      int more_a = nget - min(nget, extra);
      score1 += acc_a[n] - acc_a[n - more_a];

      int more_b = min(nget, n);
      int score2 = acc_b[n] - acc_b[n - more_b];

      if (score1 >= score2) extra_r = extra;
      else extra_l = extra + 1;
    }
    printf("%d\n", extra_l);
  }
  return 0;
}