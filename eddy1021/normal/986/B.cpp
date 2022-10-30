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
const int N=(1 << 20);
int n, a[N], BIT[N];
int lb(int x){
  return x & (-x);
}
void modify(int x){
  for(int i=x; i<N; i+=lb(i))
    BIT[i]++;
}
int q(int x){
  int ret=0;
  for(int i=x; i; i-=lb(i))
    ret+=BIT[i];
  return ret;
}
void build(){

}
void Petr(){
  
}
void Um_nik(){

}
void init(){
  n=getint();
  for(int i=1; i<=n; i++)
    a[i]=getint();
}
void solve(){
  LL cnt=0;
  for(int i=n; i>=1; i--){
    cnt+=q(a[i]);
    modify(a[i]);
  }
  cnt &= 1;
  if(cnt == (n & 1))
    puts("Petr");
  else
    puts("Um_nik");
}
int main(){
  build();
  //__ = getint();
  while(__ --){
    init();
    solve();
  }
}