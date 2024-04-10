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
const int N=5140;
void build(){

}
LL n, a[N], k;
void init(){
  n=getint();
  //n=5000;
  for(int i=0; i<n; i++)
    a[i]=getint();
    //a[i]=i+1;
  k=(n+1)/2;
}
LL dp[2][N][2][2], ans[N];
const LL inf=1e18;
LL down_to(LL cur, LL hill){
  return min(cur, hill-1);
}
void solve(){
  for(int i=0; i<=k; i++)
    for(int j=0; j<2; j++)
      for(int u=0; u<2; u++)
        dp[0][i][j][u]=inf;
  dp[0][0][0][0]=0;
  for(int _=0; _<n; _++){
    int now=_&1, nxt=1^now;
    int h=a[_];
    for(int i=0; i<=k; i++)
      for(int j=0; j<2; j++)
        for(int u=0; u<2; u++)
          dp[nxt][i][j][u]=inf;
    for(int i=0; i<=k; i++)
      for(int j=0; j<2; j++)
        for(int u=0; u<2; u++){
          if(dp[now][i][j][u] == inf) continue;
          { // not hill
            dp[nxt][i][u][0]=min(dp[nxt][i][u][0],
                                 dp[now][i][j][u]);
          }
          if(u == 0 and i+1<=k){
            LL cst=0;
            if(_){
              if(j){
                LL cur=down_to(a[_-1], a[_-2]);
                cst+=cur-down_to(cur, h);
              }else{
                cst+=a[_-1]-down_to(a[_-1], h);
              }
            }
            if(_+1 < n)
              cst+=a[_+1]-down_to(a[_+1], h);
            //printf("%d is hill, i=%d, j=%d, u=%d, cst=%lld\n",
                   //_, i, j, u, cst);
            dp[nxt][i+1][u][1]=min(dp[nxt][i+1][u][1],
                                   dp[now][i][j][u] + cst);
          }
        }
    //for(int i=0; i<=k; i++)
      //for(int j=0; j<2; j++)
        //for(int u=0; u<2; u++)
          //printf("dp[%d][%d][%d][%d]=%lld\n",
                 //_+1, i, j, u, dp[nxt][i][j][u]);
  }
  for(int i=0; i<=k; i++) ans[i]=inf;
  for(int i=0; i<=k; i++)
    for(int j=0; j<2; j++)
      for(int u=0; u<2; u++)
        ans[i]=min(ans[i], dp[n&1][i][j][u]);
  for(int i=1; i<=k; i++)
    printf("%lld%c", ans[i], " \n"[i==k]);
}
int main(){
  build();
  //__ = getint();
  while(__ --){
    init();
    solve();
  }
}