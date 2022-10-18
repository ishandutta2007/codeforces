#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int main() {
  double a, b;
  cin >> a >> b;
  double len = a + b;
  int k = (a + b) / (b + b);
  if (k < 1)
    puts("-1");
  else
    printf("%.12lf\n", len / 2.0 / k);
  return 0;
}