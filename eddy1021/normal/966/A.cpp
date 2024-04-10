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
LL n, m, cl, ce, v;
set<LL> s, e;
void init(){
  n=getint();
  m=getint();
  cl=getint();
  ce=getint();
  v=getint();
  for(int i=0; i<cl; i++)
    s.insert(getint());
  for(int i=0; i<ce; i++)
    e.insert(getint());
}
int sx, sy, tx, ty;
const LL inf9=1e9;
const LL inf=inf9 * inf9;
inline LL cal(){
  if(sx == tx) return abs(sy-ty);
  LL ans=inf;
  {
    auto it = s.lower_bound(sy);
    if(it != s.end()){
      LL at=*it;
      LL tans=abs(sy-at)+abs(sx-tx)+abs(ty-at);
      ans=min(ans, tans);
    }
    if(it != s.begin()){
      --it;
      LL at=*it;
      LL tans=abs(sy-at)+abs(sx-tx)+abs(ty-at);
      ans=min(ans, tans);
    }
  }
  {
    auto it = e.lower_bound(sy);
    if(it != e.end()){
      LL at=*it;
      LL tans=abs(sy-at)+(abs(sx-tx)+v-1)/v+abs(ty-at);
      ans=min(ans, tans);
    }
    if(it != e.begin()){
      --it;
      LL at=*it;
      LL tans=abs(sy-at)+(abs(sx-tx)+v-1)/v+abs(ty-at);
      ans=min(ans, tans);
    }
  }
  return ans;
}
void solve(){
  int q=getint(); while(q--){
    sx=getint(); sy=getint();
    tx=getint(); ty=getint();
    printf("%lld\n", cal());
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