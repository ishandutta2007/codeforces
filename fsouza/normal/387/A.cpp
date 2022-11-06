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
  char c;
  int ch, cm;
  int dh, dm;
  int sh, sm;

  cin >> ch >> c >> cm;
  cin >> dh >> c >> dm;

  sh = ch - dh;
  sm = cm - dm;

  if (sm < 0) {
    sm += 60;
    sh--;
  }

  if (sh < 00) {
    sh += 24;
  }

  printf("%02d:%02d\n", sh, sm);

  return 0;
}