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
const int N=303030;
void build(){

}
int n, x, y;
int sz[N];
vector<int> v[N];
void init(){
  n=getint();
  x=getint();
  y=getint();
  for(int i=1; i<n; i++){
    int ui=getint();
    int vi=getint();
    v[ui].push_back(vi);
    v[vi].push_back(ui);
  }
}
bool go(int now, int prt){
  sz[now]=1;
  bool flag=(now == y);
  int dlt=0;
  for(int son: v[now]){
    if(son == prt) continue;
    if(go(son, now)){
      flag=true;
      if(now == prt)
        dlt=sz[son];
    }
    sz[now]+=sz[son];
  }
  sz[now]-=dlt;
  return flag;
}
void solve(){
  go(x, x);
  LL ans=(LL)n*n-(LL)sz[x]*(LL)sz[y];
  ans-=n;
  cout<<ans<<endl;
}
int main(){
  build();
  //__ = getint();
  while(__ --){
    init();
    solve();
  }
}