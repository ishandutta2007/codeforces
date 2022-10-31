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
//inline LL add(LL _x, LL _y, LL _mod=mod7){
  //_x+=_y;
  //return _x>=_mod ? _x-_mod : _x;
//}
//inline LL sub(LL _x, LL _y, LL _mod=mod7){
  //_x-=_y;
  //return _x<0 ? _x+_mod : _x;
//}
//inline LL mul(LL _x, LL _y ,LL _mod=mod7){
  //_x*=_y;
  //return _x>=_mod ? _x%_mod : _x;
//}
//LL mypow(LL _a, LL _x, LL _mod){
  //if(_x == 0) return 1LL;
  //LL _ret = mypow(mul(_a, _a, _mod), _x>>1, _mod);
  //if(_x & 1) _ret=mul(_ret, _a, _mod);
  //return _ret;
//}
//LL mymul(LL _a, LL _x, LL _mod){
  //if(_x == 0) return 0LL;
  //LL _ret = mymul(add(_a, _a, _mod), _x>>1, _mod);
  //if(_x & 1) _ret=add(_ret, _a, _mod);
  //return _ret;
//}
void sleep(double sec = 1021){
  clock_t s = clock();
  while(clock() - s < CLOCKS_PER_SEC * sec);
}
#define Bye exit(0)
int __ = 1 , _cs;
/*********default*********/
const int N=100;
int mu[ N ] , p_tbl[ N ];
vector<int> primes;
void build(){
  mu[ 1 ] = p_tbl[ 1 ] = 1;
  for( int i = 2 ; i < N ; i ++ ){
    if( !p_tbl[ i ] ){
      p_tbl[ i ] = i;
      primes.push_back( i );
      mu[ i ] = -1;
    }
    for( int p : primes ){
      int x = i * p;
      if( x >= N ) break;
      p_tbl[ x ] = p;
      mu[ x ] = -mu[ i ];
      if( i % p == 0 ){
        mu[ x ] = 0;
        break;
      }
    }
  }
}
const LL inf=2e18;
inline LL mmul(LL a, LL b){
  if(!a or !b) return 0;
  if(a<inf/b) return a*b;
  return inf;
}
inline LL mpow(LL a, LL b){
  LL ret=1;
  while(b){
    if(b&1) ret=mmul(ret, a);
    a=mmul(a, a);
    b>>=1;
  }
  return ret;
}
LL n;
void init(){
  n=getint();
}
LL cnt[60];
void solve(){
  for(int i=0; i<60; i++) cnt[i]=0;
  cnt[1]=n-1;
  for(int i=2; i<60; i++){
    LL cand=cnt[i-1]+1;
    if(cand <= 10){
      while(mpow(cand, i) > n) cand--;
      if(cand < 2) break;
      cnt[i]=cand-1;
      continue;
    }
    cand=powl(n, 1./i);
    while(mpow(cand, i) <= n) cand++;
    cand--;
    cnt[i]=cand-1;

    //LL bl=2, br=cnt[i-1]+1, ba=-1;
    //while(bl <= br){
      //LL bmid=(bl+br)>>1;
      //if(mpow(bmid, i) <= n) ba=bmid, bl=bmid+1;
      //else br=bmid-1;
    //}
    //if(ba == -1) break;
    //cnt[i]=ba-1;
  }
  //(int i=2; i<60; i++)
    //if(cnt[i])
      //printf("%d %lld\n", i, cnt[i]);
  //for(int i=59; i>=2; i--)
    //for(int j=i+i; j<60; j+=i)
      //cnt[i]-=cnt[j];
  LL ans=n-1;
  //for(int i=2; i<60; i++) ans-=cnt[i];
  for(int i=2; i<60; i++)
    ans+=cnt[i]*mu[i];
  //for(int i=2; i<60; i++)
    //if(cnt[i])
      //printf("%d %lld\n", i, cnt[i]);
  printf("%lld\n", ans);
}
int main(){
  build();
  __ = getint();
  while(__ --){
    init();
    solve();
  }
}