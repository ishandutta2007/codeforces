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

#define MAXN 222
int N, a[MAXN];
bool possible[MAXN];

void dfs(int n) {
  if(n > 2*N - 1 || n < 0) return;
  possible[n] = true;
  FOR(i, 0, min(n, N)) {
    int nn = n - i + N - i;
    if(!possible[nn]) dfs(nn);
  }
}

int main(int argc, char *argv[]){
  int n = 0, zeros = 0; 
  scanf("%d", &N);
  REP(i, 2*N-1) {
    scanf("%d", a + i);
    if(a[i] < 0) {
      n ++;
      a[i] *= -1;
    }
    if(!a[i]) zeros++;
  }
  FOR(i, 0, zeros) dfs(n + i);
  sort(a, a + 2*N - 1);
  REP(i, 2*N) if(possible[i]) {
    int ans = 0;
    REP(j, 2*N-1) {
      if(j < i) ans += -a[j];
      else ans += a[j];
    }
    printf("%d\n", ans);
    break;
  }
  return 0;
}