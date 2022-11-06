#include <iostream>
#include <cstdio>
#include <algorithm>
#include <numeric>
#include <climits>
#include <sstream>
#include <cstring>
#include <cassert>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <map>
#include <set>

#define INF (INT_MAX/2)

typedef long long lint;

using namespace std;

int main(int argc, char ** argv)
{
  int n, na = 0, nb = 0;

  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    int v;
    scanf("%d", &v);
    if (v == 100) na++;
    else nb++;
  }

  bool ok = false;

  for (int cb = 0; cb <= nb; cb++) {
    int remain = (na * 100 + nb * 200)/2 - cb * 200;
    if (remain < 0 || remain%100) continue;
    int ca = remain/100;
    if (ca > na) continue;
    ok = true;
  }

  printf(ok ? "YES\n" : "NO\n");

  return 0;
}