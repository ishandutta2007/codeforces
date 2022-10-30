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
const int N=101010;
void build(){

}
int n;
const int S=128;
int cnt[3][S], len[3];
char buf[N];
void init(){
  n=getint();
  for(int i=0; i<3; i++){
    scanf("%s", buf);
    for(int j=0; buf[j]; j++)
      cnt[i][(int)buf[j]]++;
    len[i]=strlen(buf);
  }
}
int mx[3];
void solve(){
  for(int i=0; i<3; i++){
    int cur=*max_element(cnt[i], cnt[i]+S);
    if(n == 0){
      mx[i]=cur;
      continue;
    }
    if(cur == len[i]){
      if(n == 1) mx[i]=len[i]-1;
      else mx[i]=len[i];
      continue;
    }
    mx[i]=min(len[i], cur+n);
  }
  int bst=*max_element(mx, mx+3);
  vector<int> who;
  for(int i=0; i<3; i++)
    if(mx[i] == bst)
      who.push_back(i);
  if(who.size() > 1u) puts("Draw");
  else{
    if(who[0] == 0) puts("Kuro");
    if(who[0] == 1) puts("Shiro");
    if(who[0] == 2) puts("Katie");
  }
}
int main(){
  build();
  //__ = getint();
  while(__ --){
    init();
    solve();
  }
}