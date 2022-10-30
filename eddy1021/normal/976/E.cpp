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
LL n, a, b, hp[N], d[N];
void init(){
  n=getint();
  a=getint();
  b=getint();
  for(int i=0; i<n; i++){
    hp[i]=getint();
    d[i]=getint();
  }
}
bool in[N];
LL cal(){
  if(b == 0) return accumulate(d, d+n, 0LL);
  a=(1LL << a);
  LL sum=accumulate(d, d+n, 0LL);
  vector<pair<LL,LL>> cand;
  for(int i=0; i<n; i++)
    if(hp[i]>d[i])
      cand.push_back({hp[i]-d[i], i});
  sort(cand.begin(), cand.end());
  reverse(cand.begin(), cand.end());
  while((int)cand.size() > b) cand.pop_back();
  LL bns=0;
  for(auto i: cand){
    bns+=i.first;
    in[i.second]=true;
  }
  LL ans=sum+bns;
  for(int i=0; i<n; i++){
    LL gt=hp[i]*a-d[i];
    LL tans=sum+bns+gt;
    if(in[i]) tans-=hp[i]-d[i];
    else if((int)cand.size() >= b) tans-=cand.back().first;
    ans=max(ans, tans);
  }
  return ans;
}
void solve(){
  printf("%lld\n", cal());
}
int main(){
  build();
  //__ = getint();
  while(__ --){
    init();
    solve();
  }
}