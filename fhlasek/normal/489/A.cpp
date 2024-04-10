/* Written by Filip Hlasek 2014 */
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

#define MAXN 3333
int a[MAXN];

int main(int argc, char *argv[]) {
  int N;
  scanf("%d", &N);
  REP(i, N) scanf("%d", a + i);
  printf("%d\n", N);
  REP(i, N) {
    int best = i;
    FOR(j, i, N - 1) if (a[j] < a[best]) best = j;
    printf("%d %d\n", i, best);
    swap(a[i], a[best]);
  }
  return 0;
}