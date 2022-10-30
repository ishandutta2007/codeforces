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
int n, A, B;
const int N=1021;
void init(){
  n=getint();
  A=getint();
  B=getint();
}
void imp(){
  puts("NO");
  exit(0);
}
int a[N][N];
bool is(int i){
  return i==0 or i>=B;
}
void con(){
  if(A>1) imp();
  if(n==1) return;
  if(n==2){
    if(B==1) imp();
    a[0][1]=a[1][0]=1;
    return;
  }
  if(n==3){
    if(B==1) imp();
    if(B==2){
      a[0][2]=a[2][0]=1;
      a[1][2]=a[2][1]=1;
      return;
    }
    if(B==3){
      for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
          if(i != j)
            a[i][j]=1;
      return;
    }
    assert(false);
    return;
  }
  for(int i=0; i+1<n; i++)
    a[i][i+1]=a[i+1][i]=1;
  for(int i=0; i<n; i++)
    for(int j=0; j<n; j++){
      if(i == j or (is(i) and is(j)))
        continue;
      a[i][j]=1;
    }
}
void solve(){
  int rev=0;
  if(B==1){
    swap(A,B);
    rev=1;
  }
  con();
  if(rev){
    for(int i=0; i<n; i++)
      for(int j=0; j<n; j++)
        if(i!=j)
          a[i][j]=1-a[i][j];
  }
  puts("YES");
  for(int i=0; i<n; i++, puts(""))
    for(int j=0; j<n; j++)
      printf("%d", a[i][j]);
}
int main(){
  build();
  //__ = getint();
  while(__ --){
    init();
    solve();
  }
}