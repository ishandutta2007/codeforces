#include <cmath>
#include <ctime>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

#include <stack>
#include <queue>
#include <vector>

#include <bitset>

#include <string>

#include <algorithm>
#include <functional>

#include <iostream>
#include <sstream>

using namespace std;
typedef long long llint;

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

int main(void)
{
  int n;
  scanf("%d", &n);
  vector< int > h(n + 1);

  FOR(i, 1, n + 1)
    scanf("%d", &h[i]);

  int sol = 0;
  int energy = 0;

  REP(i, n) {
    int d = h[i] - h[i + 1];

    if (d < 0) {
      if (energy + d >= 0) 
        energy += d;
      else {
        sol -= energy + d;
        h[i] -= energy + d;
        energy += h[i] - h[i + 1];
      }
    } else {
      energy += d;
    }
  }

  printf("%d\n", sol);

  return 0;
}