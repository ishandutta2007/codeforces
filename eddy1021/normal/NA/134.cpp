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
#define N 303030
void build(){

}
LL n, x1, x2;
vector<pair<LL,int>> v;
void init(){
  n=getint();
  x1=getint();
  x2=getint();
  for(int i=1; i<=n; i++){
    LL ci=getint();
    v.push_back({ci, i});
  }
  sort(v.begin(), v.end());
}
vector<int> a1, a2;
bool good(){
  for(size_t i=0; i<v.size(); i++){
    LL nd=(x1+v[i].first-1)/v[i].first;
    if((LL)i+nd<(LL)v.size()){
      int i2=i+nd;
      LL nd2=(x2+v[i2].first-1)/v[i2].first;
      if(i2+nd2 <= (LL)v.size()){
        for(size_t ii=i; ii<(size_t)i+nd; ii++)
          a1.push_back(v[ii].second);
        for(size_t ii=i2; ii<(size_t)i2+nd2; ii++)
          a2.push_back(v[ii].second);
        return true;
      }
    }
  }
  return false;
}
void output(){
  puts("Yes");
  printf("%d %d\n", (int)a1.size(), (int)a2.size());
  for(size_t i=0; i<a1.size(); i ++)
    printf("%d%c", a1[i], " \n"[i + 1 == a1.size()]);
  for(size_t i=0; i<a2.size(); i ++)
    printf("%d%c", a2[i], " \n"[i + 1 == a2.size()]);
  exit(0);
}
void solve(){
  if(good()) output();
  swap(x1, x2);
  if(good()){
    swap(a1, a2);
    output();
  }
  puts("No");
}
int main(){
  build();
  //__ = getint();
  while(__ --){
    init();
    solve();
  }
}