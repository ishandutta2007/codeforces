#include <cmath>
#include <ctime>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <set>
#include <map>
#include <unordered_set>
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
  int n, k;
  scanf("%d%d", &n, &k);

  int s[2] = {1, n};
  int step = 0;

  REP(i, k) {
    printf("%d ", s[step]);
    if (step == 0) {
      ++s[step];
    } else {
      --s[step];
    }
    step ^= 1;
  }

  REP(i, n - k) {
    if (step == 0) {
      printf("%d ", s[1]);
      --s[1];
    } else {
      printf("%d ", s[0]);
      ++s[0];
    }
  }

  puts("");

  return 0;
}