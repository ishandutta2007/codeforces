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

int inv(int x, int mod) {
  // x^(mod - 2)

  int ret = 1;
  for (int i = 0; (1 << i) <= mod - 2; ++i) {
    if ((mod - 2) & (1 << i))
      ret = (llint)ret * x % mod;
    x = (llint)x * x % mod;
  }

  return ret;
}

const int MAXN = 100005;
bool np[MAXN];
bool prime(int n) { return !np[n]; }

int main(void)
{
  for (int i = 2; i < MAXN; ++i) {
    if (np[i]) continue;
    for (int j = 2 * i; j < MAXN; j += i)
      np[j] = 1;
  }

  int n;
  scanf("%d", &n);

  if (n == 1) {
    puts("YES");
    puts("1");
    exit(0);
  }

  if (n == 4) {
    puts("YES");
    puts("1");
    puts("3");
    puts("2");
    puts("4");
    exit(0);
  }

  if (!prime(n)) {
    puts("NO");
    exit(0);
  }

  puts("YES");
  puts("1");
  for (int i = 1; i <= n - 2; ++i) {
    printf("%d\n", (llint)i * inv(i + 1, n) % n);
  }
  printf("%d\n", n);
    
  return 0;
}