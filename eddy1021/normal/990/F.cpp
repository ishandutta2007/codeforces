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
int n, s[N], m, x[N], y[N];
vector<int> v[N], g[N];
void init(){
  n=getint();
  for(int i=1; i<=n; i++)
    s[i]=getint();
  m=getint();
  for(int i=0; i<m; i++){
    x[i]=getint();
    y[i]=getint();
    v[x[i]].push_back(y[i]);
    v[y[i]].push_back(x[i]);
  }
}
void no(){
  puts("Impossible");
  exit(0);
}
bool got[N];
void dfs(int now){
  got[now]=true;
  for(int nxt: v[now]){
    if(got[nxt]) continue;
    g[now].push_back(nxt);
    g[nxt].push_back(now);
    dfs(nxt);
  }
}
unordered_map<int,LL> rf[N];
int con(int now, int prt){
  int ret=s[now];
  for(int son: g[now]){
    if(son == prt) continue;
    int sret=con(son, now);
    rf[now][son]=+sret;
    rf[son][now]=-sret;
    ret+=sret;
  }
  return ret;
}
void solve(){
  for(int i=1; i<=n; i++){
    if(got[i]) continue;
    dfs(i);
    if(con(i, i)) no();
  }
  puts("Possible");
  for(int i=0; i<m; i++)
    printf("%lld\n", rf[x[i]][y[i]]);
}
int main(){
  build();
  //__ = getint();
  while(__ --){
    init();
    solve();
  }
}