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
LL n, q, a[N], k[N], sa[N];
void init(){
  n=getint();
  q=getint();
  for(int i=1; i<=n; i++){
    a[i]=getint();
    sa[i]=sa[i-1]+a[i];
  }
  for(int i=0; i<q; i++)
    k[i]=getint();
}
void solve(){
  int nxt=1;
  LL mns=0;
  for(int i=0; i<q; i++){
    LL tk=min(a[nxt]-mns, k[i]);
    mns+=tk;
    k[i]-=tk;
    if(a[nxt]-mns==0){
      nxt++;
      mns=0;
    }
    if(k[i]==0){
      if(nxt>n) nxt=1, mns=0;
      printf("%lld\n",n-nxt+1);
      continue;
    }
    if(nxt <= n){
      int bl=nxt, br=n, ba=nxt-1;
      while(bl <= br){
        int bmid=(bl+br)>>1;
        LL ss=sa[bmid]-sa[nxt-1];
        if(k[i] >= ss) ba=bmid, bl=bmid+1;
        else br=bmid-1;
      }
      k[i]-=sa[ba]-sa[nxt-1];
      nxt=ba+1;
      if(k[i] and nxt <= n)
        mns=k[i];
      else
        mns=0;
    }
    if(nxt > n)
      nxt=1, mns=0;
    printf("%lld\n", n-nxt+1);
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