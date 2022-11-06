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
  int n;
  scanf("%d", &n);

  vector<int> ret(n);

  for (int i = 0; i < n; i++) {
    int v;
    scanf("%d", &v); v--;
    ret[v] = i;
  }
  
  for (int i = 0; i < n; i++) {
    if (i-1 >= 0) printf(" ");
    printf("%d", ret[i]+1);
  }
  printf("\n");

  return 0;
}