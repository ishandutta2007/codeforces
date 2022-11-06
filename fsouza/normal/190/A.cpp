#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <numeric>
#include <utility>
#include <vector>
#include <map>
#include <set>

using namespace std;

typedef long long lint;

int main() {
  int n, m;

  scanf("%d %d", &n, &m);

  if (n == 0) {
    if (m > 0) printf("Impossible\n");
    else printf("0 0\n");
  } else if (m == 0) {
    printf("%d %d\n", n, n);
  } else {
    int mi = n + m - min(n, m);
    int ma = n + m - 1;
    printf("%d %d\n", mi, ma);
  }
  
  return 0;
}