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

int q[MAXN], s[MAXN], p[MAXN];
int N, K;

bool same(){
  REP(i, N) if(s[i] != p[i]) return false;
  return true;
}

void next(){
  int tmp[MAXN];
  REP(i, N) tmp[i] = p[q[i]];
  REP(i, N) p[i] = tmp[i];
}

void before(){
  int tmp[MAXN];
  REP(i, N) tmp[q[i]] = p[i];
  REP(i, N) p[i] = tmp[i];
}

bool solve(){
  REP(i, N) p[i] = i;
  int r = 0, l = 0;
  while(r < MAXN && !same()){ next(); r++; }

  REP(i, N) p[i] = i;
  while(l < MAXN && !same()){ before(); l++; }
  if(r == 0) return false;
  if(K == 1) return (r == 1) || (l == 1);
  if(r == 1 && l == 1) return false;
  return (r <= K && r % 2 == K % 2) || (l <= K && l % 2 == K % 2);
}

int main(int argc, char *argv[]){
  scanf("%d%d", &N, &K);
  REP(i, N) scanf("%d", q + i);
  REP(i, N) scanf("%d", s + i);
  REP(i, N){ q[i]--; s[i]--; }
  if(solve()) printf("YES\n");
  else printf("NO\n");
  return 0;
}