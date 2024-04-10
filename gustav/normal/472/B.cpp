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

#define MAXN 2005

int n, k;
int f[MAXN];

int main(void)
{
  scanf("%d%d", &n, &k);
  REP(i, n) scanf("%d", &f[i]); 

  sort(f, f + n);
  reverse(f, f + n);

  int sol = 0;
  for (int i = 0; i < n; i += k) 
    sol += 2 * (f[i] - 1);

  printf("%d\n", sol);

  return 0;
}