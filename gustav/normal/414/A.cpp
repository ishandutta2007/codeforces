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

#define pb push_back
#define MAX 2000005

int np[MAX];

int main(void)
{
  vector< int > p;
  for (int i = 2; i < MAX; ++i) {
    if (np[i]) continue;
    p.pb(i);
    for (int j = 2 * i; j < MAX; j += i)
      np[j] = 1;
  }

  int n, k;
  scanf("%d%d", &n, &k);

  if (k < n / 2 || (n == 1 && k != 0)) {
    puts("-1");
    return 0;
  }

  if (n == 1 && k == 0) {
    printf("1");
    return 0;
  }

  int d;
  if ((d = k - n / 2 + 1) > 0) {
    printf("%d %d ", d, 2 * d);
    n -= 2;
  }

  while (n >= 2) {
    int a = p.back(); p.pop_back();
    int b = p.back(); p.pop_back();

    if (a == d || b == d) continue;

    printf("%d %d ", a, b);
    n -= 2;
  }

  if (n)
    printf("100000000");

  puts("");
  
  return 0;
}