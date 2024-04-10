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
const int N=303030;
unordered_map<int,int> lft, rgt;
int n;
char c[N];
void init(){
  n=getint(); while(n--){
    scanf("%s", c);
    int len=strlen(c);
    {
      int sum=0, mn=0;
      for(int i=0; i<len; i++){
        if(c[i] == '(') sum++;
        else sum--;
        mn=min(mn, sum);
      }
      if(mn >= 0)
        lft[sum]++;
    }
    {
      int sum=0, mn=0;
      for(int i=len-1; i>=0; i--){
        if(c[i] == ')') sum++;
        else sum--;
        mn=min(mn, sum);
      }
      if(mn >= 0)
        rgt[sum]++;
    }
  }
}
void solve(){
  LL ans=0;
  for(auto i: lft)
    ans+=i.second*(LL)rgt[i.first];
  printf("%lld\n", ans);
}
int main(){
  build();
  //__ = getint();
  while(__ --){
    init();
    solve();
  }
}