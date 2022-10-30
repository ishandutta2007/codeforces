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
const int N=100010;
const int K=102;
void build(){

}
int n, m, k, s, a[N];
int d[N][K];
vector<int> v[N];
void init(){
  n=getint();
  m=getint();
  k=getint();
  s=getint();
  for(int i=1; i<=n; i++)
    a[i]=getint();
  while(m --){
    int ui=getint();
    int vi=getint();
    v[ui].push_back(vi);
    v[vi].push_back(ui);
  }
}
int ans[N];
void solve(){
  for(int i=1; i<=k; i++){
    for(int j=1; j<=n; j++)
      d[j][i]=-1;
    queue<int> wt;
    for(int j=1; j<=n; j++)
      if(a[j] == i){
        d[j][i]=0;
        wt.push(j);
      }
    while(wt.size()){
      int tn=wt.front(); wt.pop();
      for(int nxt : v[tn]){
        if(d[nxt][i] >= 0) continue;
        d[nxt][i]=d[tn][i]+1;
        wt.push(nxt);
      }
    }
  }
  for(int i=1; i<=n; i++){
    sort(d[i]+1, d[i]+k+1);
    ans[i]=accumulate(d[i]+1, d[i]+s+1, 0);
  }
  for(int i=1; i<=n; i++)
    printf("%d%c", ans[i], " \n"[i == n]);
}
int main(){
  build();
  //__ = getint();
  while(__ --){
    init();
    solve();
  }
}