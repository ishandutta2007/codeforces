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

char ans[222222];

int main(int argc, char *argv[]){
  int A, B, N; 
  scanf("%d%d%d", &A, &B, &N);
  bool ok = true;
  int mod = A % B;
  REP(i, N){
    mod = (10 * mod) % B;
    int digit = -1;
    REP(i, 10) if(mod + i == 0 || mod + i == B) digit = i; 
    if(digit == -1){ ok = false; break; }
    ans[i] = digit + '0';
    mod += digit;
  }
  ans[N] = '\0';
  if(ok) printf("%d%s\n", A, ans);
  else printf("-1\n");
  return 0;
}