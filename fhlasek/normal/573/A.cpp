/* Written by Filip Hlasek 2015 */
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
  int n;
  int d = 0;
  scanf("%d", &n);
  while (n--) {
    int a;
    scanf("%d", &a);
    while (a % 2 == 0) a /= 2;
    while (a % 3 == 0) a /= 3;
    if (d != 0 && a != d) { printf("No\n"); return 0; }
    d = a;
  }
  printf("Yes\n");
  return 0;
}