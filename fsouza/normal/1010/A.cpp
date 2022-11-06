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
typedef long double ldouble;

int main() {
  int n, payload;
  scanf("%d %d", &n, &payload);
  vector<int> wpf_out(n), wpf_in(n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &wpf_out[i]);
  for (int i = 0; i < n; ++i)
    scanf("%d", &wpf_in[i]);

  ldouble l = 0.0, r = 1e9 + 10.0;
  for (int rep = 0; rep < 200; ++rep) {
    ldouble m = (l + r) / 2.0;

    ldouble fuel = m;
    bool ok = true;
    for (int i = 0; i < n; ++i) {
      int j = (i + 1 < n ? i + 1 : 0);

      ldouble cost = (fuel + payload) / wpf_out[i];
      fuel -= cost;
      if (fuel < 0) {
        ok = false;
        break;
      }
      cost = (fuel + payload) / wpf_in[j];
      fuel -= cost;
      if (fuel < 0) {
        ok = false;
        break;
      }
    }

    if (ok) r = m;
    else l = m;
  }

  if (l > 1e9 + 5) printf("-1\n");
  else printf("%.9f\n", (double)l);

  return 0;
}