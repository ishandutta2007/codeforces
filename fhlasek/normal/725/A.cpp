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

#define MAXN 222222
char input[MAXN];
int N;

int main(int argc, char *argv[]) {
  scanf("%d", &N);
  scanf("%s", input);
  int l = 0, r = 0;
  while (l < N && input[l] == '<') ++l;
  while (r < N && input[N - 1 - r] == '>') ++r;
  printf("%d\n", l + r);
  return 0;
}