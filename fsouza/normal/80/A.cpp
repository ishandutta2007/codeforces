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
  int n, m;
  
  scanf("%d %d", &n, &m);

  int p[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
  bool ok = false;

  for (int i = 0; i+1 < (sizeof(p)/sizeof(int)); i++)
    if (p[i] == n && p[i+1] == m) {
      ok = true;
      break;
    }
  
  if (ok) printf("YES\n");
  else printf("NO\n");

  return 0;
}