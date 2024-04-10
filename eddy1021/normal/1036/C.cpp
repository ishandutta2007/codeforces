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
void build(){

}
LL l, r;
void init(){
  l=getint();
  r=getint();
}
LL b[20], h;
LL C2(LL x){ return x*(x-1)/2; }
LL C3(LL x){ return x*(x-1)*(x-2)/6; }
LL ff(int bt, int g){
  if(g == 0) return 1;
  if(g == 1) return (bt+1)*9;
  if(g == 2) return C2(bt+1)*9*9;
  if(g == 3) return C3(bt+1)*9*9*9;
  return -1;
}
LL go(int bt, int res, bool same){
  if(res == 0 or bt < 0) return 1;
  if(not same){
    LL ret=0;
    for(int g=0; g<=res; g++)
      ret+=ff(bt, g);
    return ret;
  }
  LL ret=0;
  for(int i=0; i<=9; i++){
    if(i and res==0) break;
    if(same and i>b[bt]) break;
    ret+=go(bt-1, res-(i>0), same and i==b[bt]);
  }
  return ret;
}
LL f(LL x){
  if(x == 0) return 1;
  h=0;
  while(x){
    b[h++]=x%10;
    x/=10;
  }
  return go(h-1, 3, true);
}
void solve(){
  printf("%lld\n", f(r)-f(l-1));
}
int main(){
  build();
  __ = getint();
  while(__ --){
    init();
    solve();
  }
}