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
const int mod=998244353;
int two[N];
void build(){
  two[0]=1;
  for(int i=1; i<N; i++)
    two[i]=add(two[i-1], two[i-1], mod);
}
int n, m;
vector<int> v[N];
int clr[N];
void init(){
  n=getint();
  for(int i=1; i<=n; i++)
    v[i].clear(), clr[i]=0;
  m=getint(); while(m --){
    int a=getint();
    int b=getint();
    v[a].push_back(b);
    v[b].push_back(a);
  }
}
int ans, gg, cnt[3];
void go(int now, int tclr){
  clr[now]=tclr;
  cnt[tclr]++;
  for(int nxt: v[now]){
    if(clr[nxt]){
      if(clr[nxt] == clr[now])
        gg=1;
      continue;
    }
    go(nxt, 3-tclr);
  }
}
int f(int c1, int c2){
  return two[c2];
}
void cal(int ii){
  gg=0;
  cnt[0]=cnt[1]=cnt[2]=0;
  go(ii, 1);
  if(gg) ans=0;
  int tans=add(f(cnt[1], cnt[2]),
               f(cnt[2], cnt[1]), mod);
  ans=mul(ans, tans, mod);
}
void solve(){
  ans=1;
  for(int i=1; i<=n; i++)
    if(!clr[i])
      cal(i);
  printf("%d\n", ans);
}
int main(){
  build();
  __ = getint();
  while(__ --){
    init();
    solve();
  }
}