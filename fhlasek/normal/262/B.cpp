/* Written by Filip Hlasek 2012 */
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

int main(int argc, char *argv[]){
  int N, K, a[111111], b[111111];
  scanf("%d%d", &N, &K);
  REP(i, N) scanf("%d", a + i);
  REP(i, N) b[i] = a[i];
  int pos = 0;
  while(K--){
    a[pos] *= -1;
    if(pos && b[pos] >= 0 && -b[pos-1] < b[pos]){ a[pos-1] *= -1; a[pos] *= -1; }
    if(pos+1 < N && b[pos] < 0) pos++; 
  }
  int ans = 0;
  REP(i, N) ans += a[i];
  printf("%d\n", ans);
  return 0;
}