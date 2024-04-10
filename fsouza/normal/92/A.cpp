#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

typedef long long lint;

int main() {
  int n, remain;

  scanf("%d %d", &n, &remain);

  int i = 1;
  for (int rep = 0; i <= remain; rep++) {
    remain -= i;
    i = i+1;
    if (i == n+1) i = 1;
  }

  printf("%d\n", remain);

  return 0;
}