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

int gcd(int a, int b){ return b?gcd(b, a % b) : a; }

#define MAXN 111111
int N, M; 
int a[MAXN];

int get(int d){
  return M - d;
}

long long go(int D){
  long long ans = 0;
  while(D <= M){
    ans += get(D);
    D *= 2;
  }
  return ans;
}
int main(int argc, char *argv[]){
  scanf("%d%d", &N, &M);
  REP(i, N) scanf("%d", a + i);
  int D = 0;
  REP(i, N) D = gcd(a[i]-1, D);
  long long ans=0;
  while(D%2 == 0) D /= 2;
  for(int i = 1; i * i <= D; i++) if(D % i == 0){
    ans += go(i);
    if(i*i!=D) ans += go(D/i);
  }
  cout << ans << endl;
  return 0;
}