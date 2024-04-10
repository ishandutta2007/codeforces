/* Writen by Filip Hlasek 2012 */
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

#define MAXN 111111
int N, H, a[MAXN], o[MAXN], ans[MAXN];

bool cmp(int x, int y){ return a[x] > a[y]; }

int main(int argc, char *argv[]){
  scanf("%d%d", &N, &H);
  REP(i, N) scanf("%d", a + i);
  REP(i, N) o[i] = i;
  sort(o, o + N, cmp);
  int good1 = a[o[0]] + a[o[1]] - (a[o[N - 1]] + a[o[N-2]]);
  int good2 = max(a[o[0]] + a[o[1]], a[o[0]] + a[o[N-1]] + H) - (min(a[o[N-2]] + a[o[N-3]], a[o[N-1]] + a[o[N-2]] + H));
  if(N == 2) good2 = 0;
  if(good1 < good2){
    printf("%d\n", good1);
    REP(i, N){
      if(i) printf(" ");
      printf("1");
    }
    printf("\n");
  }
  else{
    printf("%d\n", good2);
    REP(i, N){
      if(i) printf(" ");
      printf("%d", 1 + (int)(o[N-1] == i));
    }
    printf("\n");
  }
  return 0;
}