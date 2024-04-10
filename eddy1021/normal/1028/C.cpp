// eddy1021
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL mod7=1000000007LL;
inline LL getint(){
  LL _x=0,_tmp=1; char _tc=getchar();    
  while( (_tc<'0'||_tc>'9')&&_tc!='-' ) _tc=getchar();
  if( _tc == '-' ) _tc=getchar() , _tmp = -1;
  while(_tc>='0'&&_tc<='9') _x*=10,_x+=(_tc-'0'),_tc=getchar();
  return _x*_tmp;
}
inline LL add(LL _x, LL _y, LL _mod=mod7){
  _x+=_y;
  return _x>=_mod ? _x-_mod : _x;
}
inline LL sub(LL _x, LL _y, LL _mod=mod7){
  _x-=_y;
  return _x<0 ? _x+_mod : _x;
}
inline LL mul(LL _x, LL _y ,LL _mod=mod7){
  _x*=_y;
  return _x>=_mod ? _x%_mod : _x;
}
LL mypow(LL _a, LL _x, LL _mod){
  if(_x == 0) return 1LL;
  LL _ret = mypow(mul(_a, _a, _mod), _x>>1, _mod);
  if(_x & 1) _ret=mul(_ret, _a, _mod);
  return _ret;
}
LL mymul(LL _a, LL _x, LL _mod){
  if(_x == 0) return 0LL;
  LL _ret = mymul(add(_a, _a, _mod), _x>>1, _mod);
  if(_x & 1) _ret=add(_ret, _a, _mod);
  return _ret;
}
void sleep(double sec = 1021){
  clock_t s = clock();
  while(clock() - s < CLOCKS_PER_SEC * sec);
}
#define Bye exit(0)
int __ = 1 , _cs;
/*********default*********/
const int N=202020;
void build(){

}
int n, lx[N], ly[N], rx[N], ry[N];
void init(){
  n=getint();
  for(int i=1; i<=n; i++){
    lx[i]=getint();
    ly[i]=getint();
    rx[i]=getint();
    ry[i]=getint();
  }
}
int lftlx[N];
int lftly[N];
int lftrx[N];
int lftry[N];
const int inf=1e9;
void go(int anslx, int ansrx,
        int ansly, int ansry){
  if(anslx > ansrx) return;
  if(ansly > ansry) return;
  printf("%d %d\n", anslx, ansly);
  exit(0);
}
void solve(){
  lftlx[0]=-inf; lftrx[0]=inf;
  lftly[0]=-inf; lftry[0]=inf;
  for(int i=1; i<=n; i++){
    lftlx[i]=max(lftlx[i-1], lx[i]);
    lftly[i]=max(lftly[i-1], ly[i]);
    lftrx[i]=min(lftrx[i-1], rx[i]);
    lftry[i]=min(lftry[i-1], ry[i]);
  }
  int rgtlx=-inf;
  int rgtly=-inf;
  int rgtrx=inf;
  int rgtry=inf;
  for(int i=n; i>=1; i--){
    go( max(lftlx[i-1], rgtlx),
        min(lftrx[i-1], rgtrx),
        max(lftly[i-1], rgtly),
        min(lftry[i-1], rgtry));
    rgtlx=max(rgtlx, lx[i]);
    rgtly=max(rgtly, ly[i]);
    rgtrx=min(rgtrx, rx[i]);
    rgtry=min(rgtry, ry[i]);
  }
  assert(false);
}
int main(){
  build();
  //__ = getint();
  while(__ --){
    init();
    solve();
  }
}