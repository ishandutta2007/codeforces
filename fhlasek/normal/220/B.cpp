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

#define MAXN 211111

int a[MAXN], N;
int L[MAXN], R[MAXN], o[MAXN], ans[MAXN];
int f[MAXN], last[MAXN], act[MAXN], next[MAXN];

void add(int v, int val){
  while(v <= N){
    f[v] += val;
    v += v & -v;
  }
}

int get(int v){
  int sum = 0;
  while(v){
    sum += f[v];
    v -= v & -v;
  }
  return sum;
}

bool cmp(int x, int y){ return L[x] < L[y]; }

int main(int argc, char *argv[]){
  int M;
  scanf("%d%d", &N, &M);
  REP(i, N) scanf("%d", a + i);
  REP(i, N) if(a[i] > N) a[i] = N + 1;

  REP(i, M){
    scanf("%d%d", L + i, R + i);
    o[i] = i;
  }
  sort(o, o + M, cmp);

  REP(i, N){
    next[i] = N + 1;
    if(last[a[i]]) next[last[a[i]] - 1] = i;
    last[a[i]] = i + 1;
  }
  next[N + 1] = next[N] = N + 1;
  REP(i, N + 2) last[i] = 0;
  REP(i, N + 2) act[i] = N + 1;
  REP(i, N){
    if(last[a[i]] == a[i]) add(i + 1, -1);
    last[a[i]]++;
    if(last[a[i]] == a[i]){
      act[a[i]] = i;
      add(i + 1, 1);
    }
  }
  
  /*
  printf("fenwick:");
  REP(i, N) printf(" %d", get(i + 1));
  printf("\n");
  */

  int pos = 0;
  REP(i, N){
    while(pos < M && L[o[pos]] - 1 == i){
      ans[o[pos]] = get(R[o[pos]]);
      pos++;
    }
    add(act[a[i]] + 1, -1);
    //printf("act: %d next: %d\n", act[a[i]],next[act[a[i]]]);
    act[a[i]] = next[act[a[i]]];
    add(act[a[i]] + 1, +2);
    add(next[act[a[i]]] + 1, -1);
    
    /*
    printf("fenwick:");
    REP(i, N) printf(" %d", get(i + 1));
    printf("\n");
    */
  }
  REP(i, M) printf("%d\n", ans[i]);
  return 0;
}