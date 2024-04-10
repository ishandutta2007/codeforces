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
const int N=22;
void build(){

}
int n, m;
bool has[1 << N], vst[1 << N];
void init(){
  n=getint();
  m=getint();
  for(int i=0; i<m; i++)
    has[getint()]=true;
}
int ans;
queue<int> Q;
void go(int now){
  if(vst[now]) return;
  vst[now]=true;
  if(has[now]){
    has[now]=false;
    Q.push(now);
  }
  for(int b=0; b<n; b++)
    if((now >> b) & 1)
      go(now ^ (1 << b));
}
void solve(){
  for(int i=0; i<(1 << n); i++){
    if(not has[i] or vst[i]) continue;
    ans++;
    has[i]=false;
    Q.push(i);
    while(Q.size()){
      int tn=Q.front(); Q.pop();
      go(((1 << n) - 1) ^ tn);
    }
  }
  printf("%d\n", ans);
}
int main(){
  build();
  //__ = getint();
  while(__ --){
    init();
    solve();
  }
}