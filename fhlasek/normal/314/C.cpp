/* Written by Filip Hlasek 2013 */
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

#define MOD 1000000007
#define MAXN 1111111
int f[MAXN];

void add(int x, int val) {
  while(x < MAXN) {
    f[x] = (f[x] + val) % MOD;
    x += x&(-x);
  }
}

int get(int x) {
  int ans = 0;
  while(x) { ans = (ans + f[x]) % MOD; x -= x&(-x); }
  return ans;
}

int main(int argc, char *argv[]){
  int N, a;
  scanf("%d", &N);
  REP(i, N) {
    scanf("%d", &a);
    add(a, ((long long)(1 + get(a)) * a - get(a) + get(a-1)) % MOD );
  }
  printf("%d\n", (get(MAXN-1) + MOD) % MOD);
  return 0;
}