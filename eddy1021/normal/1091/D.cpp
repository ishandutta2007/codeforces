// eddy1021
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL mod7=998244353;
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
const int N=(1<<20);
const int mod=998244353;
int fac[N], inv[N], ifac[N];
void build(){
	inv[ 1 ] = 1;
  for(int i=2; i<N; i++)
		inv[ i ] = ((LL)(mod - mod / i) * inv[mod % i]) % mod;
  fac[0]=inv[0]=ifac[0]=1;
  for(int i=1; i<N; i++){
    fac[i]=mul(fac[i-1], i, mod);
    ifac[i]=mul(ifac[i-1], inv[i], mod);
  }
}
inline int C(int a, int b){
  if(a<b) return 0;
  return mul(fac[a], mul(ifac[b], ifac[a-b], mod), mod);
}
int n;
void init(){
  n=getint();
}
int ans=1;
void solve(){
  for(int i=1; i<n; i++){
    int nd=n-i+1;
    int way=mul(mul(C(n, nd), nd-1, mod), fac[i-1], mod);
    int tans=mul(way, i, mod);
    ans=add(ans, tans, mod);
    //cerr<<i<<" "<<tans<<endl;
  }
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