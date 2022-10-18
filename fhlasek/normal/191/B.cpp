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
#include <iostream>

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,b) for(int i=0;i<b;i++)

using namespace std;

long long B;
#define MAXN 111111
int a[MAXN], N, K, o[MAXN];

bool cmp(int x, int y){ return a[x] > a[y]; }

int main(int argc, char *argv[]){
  scanf("%d%d",&N,&K);
  cin >> B;
  REP(i,N){
    scanf("%d", a + i);
    o[i] = i;
  }
  sort(o, o + N-1, cmp);
  //REP(i,N-1) printf("%d\n",o[i]);
  long long sum = 0;
  K = min(K, N-1);
  REP(i,K) sum += a[o[i]];
  if(sum <= B){ printf("%d\n", N); return 0; }
  int best = N;
  sum -= a[o[K-1]];
  REP(i,N-1){
    if(i < K) best = min(best, o[i] + 1);
    else if(sum + a[o[i]] > B) best = min(best, o[i] + 1);
  }
  printf("%d\n",best);
  return 0;
}