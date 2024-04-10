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
const int N=101010;
const int K=256;
int p[K], l[K], r[K];
int f(int x){
  return x==p[x]?x:p[x]=f(p[x]);
}
void build(){
  for(int i=0; i<K; i++)
    p[i]=l[i]=r[i]=i;
}
int n, k, a[N];
void init(){
  n=getint();
  k=getint();
  for(int i=0; i<n; i++)
    a[i]=getint();
}
int id(int clr){
  int lft=l[f(clr)];
  while(lft){
    int pre=f(lft-1);
    if(r[f(lft)]-l[f(pre)]+1 <= k){
      int p1=f(lft);
      int p2=f(pre);
      p[p1]=p2;
      l[p2]=min(l[p2], l[p1]);
      r[p2]=max(r[p2], r[p1]);
    }else
      break;
    lft=l[f(clr)];
  }
  return l[f(clr)];
}
void solve(){
  for(int i=0; i<n; i++)
    printf("%d%c", id(a[i]), " \n"[i + 1 == n]);
}
int main(){
  build();
  //__ = getint();
  while(__ --){
    init();
    solve();
  }
}