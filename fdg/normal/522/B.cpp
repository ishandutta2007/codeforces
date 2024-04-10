#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int w[200002], h[200002];
multiset<int> f;

int main() {
  int n, ws = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &w[i], &h[i]);
    ws += w[i];
    f.insert(-h[i]);
  }
  for (int i = 0; i < n; ++i) {
    auto it = f.find(-h[i]);
    f.erase(it);
    int ans = -(ws - w[i]) * (*f.begin());
    f.insert(-h[i]);
    printf("%d ", ans);
  }
  printf("\n");
  return 0;
}