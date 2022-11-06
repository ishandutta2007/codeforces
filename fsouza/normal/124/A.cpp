#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <numeric>

using namespace std;

int main() {
  int n, a, b;

  scanf("%d %d %d", &n, &a, &b);
  
  int l = max(a, n-1-b);
  int r = n-1;

  printf("%d\n", max(0, r-l+1));

  return 0;
}