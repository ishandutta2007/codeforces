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

#define MAXN 1111111
int ans[MAXN];

int main(int argc, char *argv[]){
  int N, K; 
  scanf("%d%d", &N, &K);
  if(3 * K > N){ printf("-1\n"); return 0; }
  FOR(i, 3*K, N-1) ans[i] = 1;
  REP(i, K-2) ans[2*i] = ans[2*i+1] = ans[3*K-1-i] = i + 1;
  ans[2*(K-2)] = ans[2*(K-2)+1] = ans[2*(K-2)+3] = K - 1;
  ans[2*(K-2)+2] = ans[2*(K-2)+4] = ans[2*(K-2)+5] = K;
  REP(i, N){if(i) printf(" ");printf("%d", ans[i]);} printf("\n");
  return 0;
}