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
const int N=2020;
void build(){

}
int n, p;
char c[N];
void init(){
  n=getint();
  p=getint();
  scanf("%s", c);
}
void solve(){
  for(int i=0; i<min(p,n); i++){
    bool has0=false, has1=false;
    for(int j=i; j<n; j+=p){
      if(c[j]=='0') has0=true;
      if(c[j]=='1') has1=true;
    }
    for(int j=i; j<n; j+=p)
      if(c[j]=='.'){
        if(not has0) c[j]='0';
        else c[j]='1';
        if(c[j]=='0') has0=true;
      }
  }
  for(int i=0; i<min(p,n); i++){
    bool has0=false, has1=false;
    for(int j=i; j<n; j+=p){
      if(c[j]=='0') has0=true;
      if(c[j]=='1') has1=true;
    }
    if(has0 and has1){
      puts(c);
      exit(0);
    }
  }
  puts("No");
}
int main(){
  build();
  //__ = getint();
  while(__ --){
    init();
    solve();
  }
}