/* Written by Filip Hlasek 2016 */
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstring>

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,b) for(int i=0;i<(b);i++)

using namespace std;

int main(int argc, char *argv[]) {
  int Y, X;
  scanf("%d%d", &X, &Y);
  int a[3];
  REP(i, 3) a[i] = Y;
  int ans = 0;
  while (a[ans % 3] < X) {
    a[ans % 3] = a[(ans + 1) % 3] + a[(ans + 2) % 3] - 1;
    ans++;
  }
  printf("%d\n", ans);
  return 0;
}