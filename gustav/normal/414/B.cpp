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

const int mod = 1000000007;

#define MAX 2005

int n, k;
int f[MAX];

int main(void)
{
  scanf("%d%d", &n, &k);

  for (int i = 1; i <= n; ++i)
    f[i] = 1;

  for (int i = 1; i <= k; ++i) {
    for (int j = 1; j <= n; ++j) {
      for (int m = 2 * j; m <= n; m += j) {
        f[j] += f[m];
        if (f[j] >= mod) f[j] -= mod;
      }
    }
  }

  printf("%d\n", f[1]);

  return 0;
}