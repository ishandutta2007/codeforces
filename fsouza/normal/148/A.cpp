#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <numeric>
#include <utility>

using namespace std;

typedef long long lint;

int main() {
  int m[4], n;
  for (int i = 0; i < 4; i++) scanf("%d", &m[i]);
  scanf("%d", &n);
  vector<bool> hurt(n, false);
  
  for (int i = 0; i < 4; i++) {
    int mi = m[i];
    for (int j = mi-1; j < n; j += mi)
      hurt[j] = true;
  }

  int ret = 0;

  for (int j = 0; j < n; j++)
    if (hurt[j])
      ret++;

  printf("%d\n", ret);

  return 0;
}