/* Written by Filip Hlasek 2013 */
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
#define REP(i,b) for(int i=0;i<(b);i++)

using namespace std;

int N;
int inverse(int n) {
  int ans = 0, i = 0;
  while(n) { ans |= ((1-n%2) << i); i++; n /= 2; }
  return ans;
}

#define MAXN 1111111
int ans[MAXN];

void solve(int N) {
  if(N == -1) return;
  int n = inverse(N);
  FOR(i, 0, N-n) ans[n+i] = N-i;
  solve(n-1);
}

int main(int argc, char *argv[]){
  int N;
  scanf("%d", &N);
  solve(N);
  long long A = 0;
  REP(i, N+1) A += (i ^ ans[i]);
  cout << A << endl;
  REP(i, N+1) {
    if(i) printf(" ");
    printf("%d", ans[i]);
  }
  printf("\n");
  return 0;
}