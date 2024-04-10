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
int n, m, k, a[N], b[N];
unordered_set<int> v[N];
void init(){
  n=getint();
  m=getint();
  k=getint();
  for(int i=0; i<m; i++){
    a[i]=getint();
    b[i]=getint();
    v[a[i]].insert(b[i]);
    v[b[i]].insert(a[i]);
  }
}
queue<int> Q;
int alive;
bool died[N];
void kill(int who){
  for(int x: v[who]){
    v[x].erase(who);
    if((int)v[x].size() < k and
       not died[x]){
      died[x]=true;
      alive--;
      Q.push(x);
    }
  }
  v[who].clear();
}
int ans[N];
void killing(){
  while(Q.size()){
    int tn=Q.front(); Q.pop();
    kill(tn);
  }
}
void solve(){
  alive=n;
  {
    for(int i=1; i<=n; i++)
      if((int)v[i].size() < k){
        Q.push(i);
        died[i]=true;
        alive--;
      }
    killing();
  }
  ans[m-1]=alive;
  for(int i=m-1; i>0; i--){
    if(not died[a[i]] and
       not died[b[i]]){
      v[a[i]].erase(b[i]);
      v[b[i]].erase(a[i]);
      if((int)v[a[i]].size() < k){
        Q.push(a[i]);
        died[a[i]]=true;
        alive--;
      }
      if((int)v[b[i]].size() < k){
        Q.push(b[i]);
        died[b[i]]=true;
        alive--;
      }
      killing();
    }
    ans[i-1]=alive;
  }
  for(int i=0; i<m; i++)
    printf("%d\n", ans[i]);
}
int main(){
  build();
  //__ = getint();
  while(__ --){
    init();
    solve();
  }
}