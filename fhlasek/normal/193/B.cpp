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

#define MAXN 33
int N,U,R;
long long best = -1000000000000000LL;
int a[MAXN], b[MAXN], k[MAXN], p[MAXN];

void rec(bool can_xor){
  if(!(U%2)){
    long long s = 0;
    REP(i,N) s += (long long)a[i] * k[i];
    best = max(s, best);
  }
  else{
    long long s = 0;
    REP(i,N) s += (long long)(a[i] ^ b[i]) * k[i];
    best = max(s, best);
  }
  if(!U) return;
  int aa[MAXN];
  REP(i,N) aa[i] = a[i];
  if(can_xor || U == 1){
    REP(i,N) a[i] ^= b[i];
    U--;
    rec(false);
    U++;
  }
  REP(i,N) a[i] = aa[p[i]-1] + R;
  U--;
  rec(true);
  U++;
}

int main(int argc, char *argv[]){
  scanf("%d%d%d",&N,&U,&R);
  REP(i,N) scanf("%d",a+i);
  REP(i,N) scanf("%d",b+i);
  REP(i,N) scanf("%d",k+i);
  REP(i,N) scanf("%d",p+i);
//  REP(i,N) scanf("%d%d%d%d", a+i, b+i, k+i, p+i);  
  rec(true);
  cout << best << endl;
  return 0;
}