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
  int a, b, c;

  scanf("%d %d %d", &a, &b, &c);
  printf("%d\n", max((a * c + b-1) / b - c, 0));

  return 0;
}