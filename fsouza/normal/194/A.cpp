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
  int n, k;

  scanf("%d %d", &n, &k);

  printf("%d\n", max(0, 3*n-k));

  return 0;
}