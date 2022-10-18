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
int a[MAXN], b[MAXN];

int main(int argc, char *argv[]){
  int N; 
  scanf("%d", &N);
  REP(i, N){ scanf("%d", a + i); b[i] = a[i]; }
  sort(a, a + N);
  int diff = 0;
  REP(i, N) diff += (a[i] != b[i]);
  if(diff <= 2) printf("YES\n");
  else printf("NO\n");
  return 0;
}