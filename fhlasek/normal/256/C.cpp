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

#define MAXN 900000
int sg[MAXN], pref[MAXN][5];
int visited[MAXN];

long long sqrt2(long long x){
  long long left = 0, right = min(x, 1000000000LL), middle;
  while(left < right){
    middle = (left + right + 1) / 2;
    if(middle * middle <= x) left = middle;
    else right = middle - 1;
  }
  return left;
}

long long sqrt4(long long x){
  long long left = 0, right = min(x, 1000LL), middle;
  while(left < right){
    middle = (left + right) / 2;
    if(middle * middle * middle * middle >= x) right = middle;
    else left = middle + 1;
  }
  return left;
}

int compute(long long x){
  if(x < 2) return sg[x];
  long long down = sqrt4(x), up = sqrt2(x);
  int cnt[5];
  REP(i, 5) cnt[i] = pref[up][i];
  if(down) REP(i, 5) cnt[i] -= pref[down-1][i];
  REP(i, 5) if(!cnt[i]) return i;
  return 5;
}

int main(int argc, char *argv[]){
  int maximum = 0;
  FOR(x, 2, MAXN-1){
    sg[x] = compute(x);
    if(x) REP(i, 5) pref[x][i] = pref[x-1][i];
    pref[x][sg[x]]++;
  }
  int N, x = 0;
  long long M;
  scanf("%d", &N);
  while(N--){ scanf("%I64d", &M); x ^= compute(M); }
  if(x) printf("Furlo\n");
  else  printf("Rublo\n");
  return 0;
}