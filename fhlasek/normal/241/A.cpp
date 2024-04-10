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
int M, K, s[MAXN], d[MAXN];

int main(int argc, char *argv[]){
  scanf("%d%d", &M, &K);
  REP(i, M) scanf("%d", d + i);
  REP(i, M) scanf("%d", s + i);
  int fuel = 0, ans = 0, best = s[0];
  REP(i, M){
    fuel += s[i];
    best = max(best, s[i]);
    while(fuel < d[i]){ fuel += best; ans += K; }
    ans += d[i];
    fuel -= d[i];
  }
  printf("%d\n", ans);
  return 0;
}