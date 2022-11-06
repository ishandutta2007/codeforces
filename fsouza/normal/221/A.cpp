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
  int n;
  
  scanf("%d", &n);

  printf("%d", n);
  for (int i = 1; i < n; i++) printf(" %d", i);
  printf("\n");

  return 0;
}