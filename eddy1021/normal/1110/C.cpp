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
int ans[26];
void build(){
  //for(int i=2; i<=25; i++){
    //int a=(1<<i)-1;
    //int bst=0;
    //for(int b=1; b<a; b++)
      //bst=max(bst, __gcd(a^b, a&b));
    //printf("ans[%d]=%d;\n", i, bst);
  //}
ans[2]=1;
ans[3]=1;
ans[4]=5;
ans[5]=1;
ans[6]=21;
ans[7]=1;
ans[8]=85;
ans[9]=73;
ans[10]=341;
ans[11]=89;
ans[12]=1365;
ans[13]=1;
ans[14]=5461;
ans[15]=4681;
ans[16]=21845;
ans[17]=1;
ans[18]=87381;
ans[19]=1;
ans[20]=349525;
ans[21]=299593;
ans[22]=1398101;
ans[23]=178481;
ans[24]=5592405;
ans[25]=1082401;
}
int a;
void init(){
  a=getint();
}
void solve(){
  int nb=0;
  {
    int b=a;
    while(b){
      nb++;
      b>>=1;
    }
  }
  if(nb == __builtin_popcount(a)){
    printf("%d\n", ans[nb]);
    return;
  }else{
    printf("%d\n", (1<<nb)-1);
  }
}
int main(){
  build();
  __ = getint();
  while(__ --){
    init();
    solve();
  }
}