#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <numeric>
#include <utility>

using namespace std;

typedef long long lint;

int main() {
  int n, k;

  scanf("%d %d", &n, &k);

  vector<int> h(2*n+1);

  for (int i = 0; i < 2*n+1; i++) scanf("%d", &h[i]);

  int remain = k;

  for (int i = 1; i < 2*n+1; i += 2)
    if (remain > 0 && h[i]-1 > h[i-1] && h[i]-1 > h[i+1]) {
      h[i]--;
      remain--;
    }

  for (int i = 0; i < 2*n+1; i++) {
    if (i-1 >= 0) printf(" ");
    printf("%d", h[i]);
  }
  printf("\n");

  return 0;
}