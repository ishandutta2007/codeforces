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

#define MAXN 1111
char l[MAXN];
int cnt[MAXN];

int main(int argc, char *argv[]){
  int K;
  scanf("%d", &K);
  scanf("%s", l);
  int N = strlen(l);
  REP(i, N) cnt[l[i] - 'a']++;
  REP(i, 26) if(cnt[i] % K){ printf("-1\n"); return 0; }
  REP(k, K) REP(i, 26) REP(j, cnt[i] / K) printf("%c", i + 'a');
  printf("\n");
  return 0;
}