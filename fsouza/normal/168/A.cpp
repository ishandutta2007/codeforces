#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

int main() {
  int n, x, y;

  scanf("%d %d %d", &n, &x, &y);

  int need = (n * y+99)/100;

  printf("%d\n", max(0, need - x));

  return 0;
}