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

#define MAXN 1111111
int N, T;
char in[MAXN];

int start[MAXN], end[MAXN], A;

bool possible(int k){
  int s = -1, last = -1;
  A = 0;
  REP(i, N) if(in[i] == 'H'){
    if(k) k--;
    else{
      s++;
      while(in[s] != 'S') s++;
      if(s > i){ start[A] = i; end[A] = s; A++; }
    }
    last = i;
  }
  last = max(last, s);
  if(!A) return T >= last + 1;
  if(last - start[0] + last + 1 <= T) return true;
  int extra = 0, last_end = -1;
  start[A] = last;
  REP(i, A){
    extra += 2 * (end[i] - max(last_end, start[i]));
    last_end = end[i];
    if(last - start[i+1] + last + 1 + extra <= T) return true;
  }
  return false;
}

int main(int argc, char *argv[]){
  scanf("%d%d", &N, &T);
  scanf("%s", in);
  int H = 0, S = 0;
  REP(i, N){
    if(in[i] == 'H') H++;
    if(in[i] == 'S') S++;
  }
  int left = max(0, H - S), right = N;
  if(!possible(right)) printf("-1\n");
  else{
    while(left < right){
      int middle = (left + right) / 2;
      if(possible(middle)) right = middle;
      else left = middle + 1;
    }
    printf("%d\n", left);
  }
  return 0;
}