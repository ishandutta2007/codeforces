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

#define MAX_NEEDLE 1111111
int N; //lenght of the needle
char needle[MAX_NEEDLE];
int fail[MAX_NEEDLE];
bool ok_suffix[MAX_NEEDLE];

void failure() { //precomputes the failure function
  int k;
  fail[0] = -1;
  FOR(i, 1, N) {
    for (k = fail[i - 1]; k >= 0 && needle[k] != needle[i - 1]; k = fail[k]) ;
    fail[i] = k + 1;
  }
  k = N;
  while (k >= 0) {
    ok_suffix[k] = true;
    k = fail[k];
  }
}

#define MOD 1000000007

int main(int argc, char *argv[]) {
  int L, ans = 1, Q;
  scanf("%d%d", &L, &Q);
  scanf("%s", needle);
  N = strlen(needle);
  failure();
  int last = -N + 1;
  while (Q--) {
    int cur;
    scanf("%d", &cur);
    if (last + N <= cur) REP(i, cur - (last + N)) ans = (ans * 26LL) % MOD;
    else if (!ok_suffix[N + last - cur]) ans = 0;
    last = cur;
  }
  REP(i, L - (last + N) + 1) ans = (ans * 26LL) % MOD;
  printf("%d\n", ans);
  return 0;
}