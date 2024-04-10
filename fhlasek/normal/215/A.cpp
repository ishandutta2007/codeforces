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

int a[55], b[55];

int main(int argc, char *argv[]){
  int N, M; 
  scanf("%d", &N);
  REP(i,N) scanf("%d", a + i);
  scanf("%d", &M);
  REP(i,M) scanf("%d", b + i);
  int best = 0, cnt = 0;
  REP(i, N) REP(j, M) if(b[j] % a[i] == 0){
    int tmp = b[j] / a[i];
    if(tmp > best){ best = tmp; cnt = 0; }
    if(tmp == best) cnt++;
  }
  printf("%d\n", cnt);
  return 0;
}