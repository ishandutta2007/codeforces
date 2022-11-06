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

int reach(int pos, int when, int m) {
  int cycle = 2*m-2;
  int cand[] = {pos, m-1+(m-1-pos)};
  int ret = 1000000000;
  for (int i = 0; i < 2; i++)
    ret = min(ret, ((cand[i] - when)%cycle + cycle)%cycle);
  return ret + when;
}

int main() {
  int n, m;
  
  scanf("%d %d", &n, &m);

  for (int i = 0; i < n; i++) {
    int s, f, t;
    scanf("%d %d %d", &s, &f, &t); s--, f--;
    int ret;
    if (s == f) ret = t;
    else {
      int r0 = reach(s, t, m);
      int r1 = reach(f, r0, m);
      ret = r1;
    }
    printf("%d\n", ret);
  }
  
  return 0;
}