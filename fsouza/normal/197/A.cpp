#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <utility>

using namespace std;

typedef long long lint;

int main() {
  int a, b, r;
  
  scanf("%d %d %d", &a, &b, &r);

  if (a >= 2*r && b >= 2*r) printf("First\n");
  else printf("Second\n");
  
  return 0;
}