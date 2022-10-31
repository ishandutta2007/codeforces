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
void build(){

}
const int N=202020;
int n, a[N], b[N];
vector<int> v[N], son[N];
void go(int now, int prt){
  for(int s: v[now]){
    if(s == prt) continue;
    son[now].push_back(s);
    go(s, now);
  }
}
void init(){
  n=getint();
  for(int i=1; i<n; i++){
    int x=getint();
    int y=getint();
    v[x].push_back(y);
    v[y].push_back(x);
  }
  for(int i=1; i<=n; i++)
    a[i]=b[i]=getint();
  go(1, 1);
}
void no(){
  puts("No");
  exit(0);
}
void solve(){
  if(a[1] != 1) no();
  int til=1;
  for(int _=1; _<=n; _++){
    int i=a[_];
    sort(son[i].begin(), son[i].end());
    int sz=son[i].size();
    sort(b+til+1, b+til+1+sz);
    for(int j=0; j<sz; j++)
      if(son[i][j] != b[til+1+j])
        no();
    til+=sz;
  }
  puts("Yes");
}
int main(){
  build();
  //__ = getint();
  while(__ --){
    init();
    solve();
  }
}