#include <string>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); e++)
typedef long long LL;
typedef pair<int, int> PII;

int n, x, k = 0;
bool b[1000005];
int ans[1000005];
int c = 0;

int main() {
  scanf("%d", &n);
  REP(i, 1000004)
    b[i] = false;
  REP(i, n) {
    scanf("%d", &x);
    b[x] = true;
  }
  for (int i = 1; i <= 500000; ++i) {
    if (b[i] && b[1000001 - i])
      ++k;
    else if (b[i])
      ans[c++] = 1000001 - i;
    else if (b[1000001 - i])
      ans[c++] = i;
  }
  if (k)
    for (int i = 1; i <= 500000; ++i) {
      if (!b[i] && !b[1000001 - i]) {
        ans[c++] = i;
        ans[c++] = 1000001 - i;
        if (--k == 0)
          break;
      }
    }
  printf("%d\n", c);
  REP(i, c)
    printf("%d ", ans[i]);
  printf("\n");
  return 0;
}