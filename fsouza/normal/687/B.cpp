#include <algorithm>
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

using namespace std;

typedef long long lint;

int main() {
  const int maxv = 1000000;
  vector<int> div(maxv+1, -1);
  for (int p = 2; p <= maxv; ++p)
    if (div[p] == -1)
      for (int v = p; v <= maxv; v += p)
	div[v] = p;

  vector<int> kfact(maxv+1, 0);
  vector<int> lcmfact(maxv+1, 0);

  int n, k;
  scanf("%d %d", &n, &k);

  for (int value = k, next; value != 1; value = next) {
    int d = div[value], exp = 0;
    for (next = value; div[next] == d; next /= d)
      ++exp;
    kfact[d] = exp;
  }

  for (int i = 0; i < n; ++i) {
    int ci;
    scanf("%d", &ci);
    for (int value = ci, next; value != 1; value = next) {
      int d = div[value], exp = 0;
      for (next = value; div[next] == d; next /= d)
	++exp;
      lcmfact[d] = max(lcmfact[d], exp);
    }
  }

  bool ok = true;
  for (int v = 2; v <= maxv; ++v)
    if (kfact[v] > lcmfact[v]) {
      ok = false;
      break;
    }
  if (ok) printf("Yes\n");
  else printf("No\n");

  return 0;
}