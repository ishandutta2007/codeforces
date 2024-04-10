/* Written by Filip Hlasek 2013 */
#include <cstdio>
#include <cstdlib>

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,b) for(int i=0;i<(b);i++)

using namespace std;

#define MAXN 1111111
int N, T, p[MAXN], q[MAXN];
bool Close[MAXN];

int stack[MAXN], S = 0;

int main(int argc, char *argv[]){
  scanf("%d", &N);
  REP(i, N) scanf("%d", p + i);
  scanf("%d", &T);
  REP(i, T) scanf("%d", q + i);
  REP(i, T) Close[q[i]-1] = true;
  if(N % 2) {
    printf("NO\n");
    return 0;
  }

  FORD(i, N-1, 0) {
    if(!Close[i] && S && stack[S-1] == p[i]) S--; 
    else { stack[S++] = p[i]; p[i] *= -1; }
  }

  if(S) printf("NO\n");
  else {
    printf("YES\n");
    REP(i, N) printf("%d ", p[i]);
    printf("\n");
  }
  return 0;
}