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
  int n;

  scanf("%d", &n);

  if (n <= 1) printf("0 0 %d\n", n);
  else {
    int a = 0, b = 1;
    for (int i = 1; b != n; i++) {
      a += b;
      swap(a, b);
    }
    swap(a, b);
    a -= b;
    printf("0 %d %d\n", a, b);
  }
  
  return 0;
}