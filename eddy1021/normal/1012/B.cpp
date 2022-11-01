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
int n, m, q, r[N], c[N];
int p[N];
inline int f(int x){
  return x==p[x]?x:p[x]=f(p[x]);
}
void uni(int x, int y){
  p[f(x)]=f(y);
}
void init(){
  n=getint();
  m=getint();
  q=getint();
  for(int i=0; i<q; i++){
    r[i]=getint();
    c[i]=getint();
  }
}
vector<pair<int,int>> x[N], y[N];
bool hasr[N], hasc[N];
void solve(){
  if(q==0){
    printf("%d\n", n+m-1);
    exit(0);
  }
  for(int i=0; i<q; i++) p[i]=i;
  for(int i=0; i<q; i++){
    x[r[i]].push_back({c[i], i});
    y[c[i]].push_back({r[i], i});
    hasr[r[i]]=true;
    hasc[c[i]]=true;
  }
  for(int i=0; i<N; i++){
    {
      sort(x[i].begin(), x[i].end());
      for(size_t j=1; j<x[i].size(); j++)
        uni(x[i][j-1].second, x[i][j].second);
    }
    {
      sort(y[i].begin(), y[i].end());
      for(size_t j=1; j<y[i].size(); j++)
        uni(y[i][j-1].second, y[i][j].second);
    }
  }
  int tot=0;
  for(int i=0; i<q; i++)
    if(i == f(i))
      tot++;
  int ans=tot-1;
  for(int i=1; i<=n; i++) if(not hasr[i]) ans++;
  for(int i=1; i<=m; i++) if(not hasc[i]) ans++;
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