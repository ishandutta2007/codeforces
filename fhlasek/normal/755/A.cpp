/* Written by Filip Hlasek 2017 */
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

#define MAXN 1000111
bool prime[MAXN];

int main(int argc, char *argv[]) {
  prime[1] = true;
  for (int i = 2; i < MAXN; ++i) if (!prime[i]) {
    for (int j = 2 * i; j < MAXN; j += i) prime[j] = true;
  }
  int N;
  scanf("%d", &N);
  FOR(M, 1, 1000) if (prime[N * M + 1]) {
    printf("%d\n", M);
    break;
  }
  return 0;
}