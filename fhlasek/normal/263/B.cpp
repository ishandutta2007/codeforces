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

#define MAXN 111
int a[MAXN];

int main(int argc, char *argv[]){
  int N, K;
  scanf("%d%d", &N, &K);
  REP(i, N) scanf("%d", a + i);
  sort(a, a + N);
  if(K > N || (K < N && a[N-K] == a[N-K-1])) printf("-1\n");
  else printf("%d 0\n", a[N-K]);
  return 0;
}