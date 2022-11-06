#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <numeric>

using namespace std;

typedef long long lint;

int main() {
  int k, l;

  scanf("%d %d", &k, &l);

  bool ok = true;
  int ret = 0;

  while (l > k) {
    if (l%k > 0) {
      ok = false;
      break;
    }
    l /= k;
    ret++;
  }
  if (l != k)
    ok = false;

  if (ok) printf("YES\n%d\n", ret);
  else printf("NO\n");

  return 0;
}