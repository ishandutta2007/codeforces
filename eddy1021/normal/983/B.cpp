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
const int N = 5140;
void build(){

}
int n, a[N], v[N][N], b[N];
void init(){
  n=getint();
  for(int i=1; i<=n; i++)
    a[i]=getint();
  for(int i=1; i<=n; i++){
    for(int j=1; j<=n-i+1; j++)
      v[j][j+i-1]=a[j];
    for(int j=1; j<=n-i+1; j++)
      b[j]=a[j];
    for(int j=1; j<=n-i; j++)
      a[j]=b[j]^b[j+1];
  }
  for(int d=2; d<=n; d++)
    for(int i=1; i+d-1<=n; i++)
      v[i][i+d-1]=max(v[i][i+d-1],
                      max(v[i][i+d-2], v[i+1][i+d-1]));
}
void solve(){
  int q=getint(); while(q--){
    int ql=getint();
    int qr=getint();
    printf("%d\n", v[ql][qr]);
  }
}
int main(){
  build();
  //__ = getint();
  while(__ --){
    init();
    solve();
  }
}