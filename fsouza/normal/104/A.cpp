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
  int n;

  scanf("%d", &n);

  int need = n - 10;
  int ret;

  if (need == 1 || need == 11) ret = 4;
  else if (2 <=	need &&	need < 10) ret = 4;
  else if (need	== 10) ret = 15;
  else ret = 0;

  printf("%d\n", ret);

  return 0;
}