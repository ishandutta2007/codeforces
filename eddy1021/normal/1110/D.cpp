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
const int N=(1<<20);
void build(){

}
int n, m, cnt[N];
void init(){
  //n=m=1000000;
  //for(int i=0; i<n; i++)
    //cnt[i+1]++;


  n=getint();
  m=getint();
  while(n--) cnt[getint()]++;
}
int ans;
int dp[2][7][7];
LL tg[2];
inline int enc(int a, int b){
  return (a*7)+b;
}
void solve(){
  //for(int i=1; i<=m; i++)
    //while(cnt[i] > 6){
      //ans++;
      //cnt[i]-=3;
    //}
  tg[0]=(1LL<<enc(0, 0));
  dp[0][0][0]=0;
  for(int i=0; i<m; i++){
    int now=i&1, nxt=now^1;
    tg[nxt]=0;
    while(tg[now]){
      int bt=__lg(tg[now]&(-tg[now]));
      int a=bt/7, b=bt%7;

      for(int con=0; con<=min(a, min(b, cnt[i+1])); con++){
        int res=cnt[i+1]-con;
        int at_least=max(0, (res-6)/3);
        if(res-at_least*3>6) at_least++;
        for(int same=at_least; same*3+con<=cnt[i+1]; same++){
          int na=b-con;
          int nb=cnt[i+1]-con-same*3;
          int val=dp[now][a][b]+con+same;

          int at=enc(na, nb);
          if((tg[nxt] >> at) & 1LL){
            dp[nxt][na][nb]=max(dp[nxt][na][nb],
                                val);
          }else
            dp[nxt][na][nb]=val;
          tg[nxt]|=(1LL<<at);
        }
      }

      tg[now]^=(1LL<<bt);
    }
  }
  int cans=0;
  int now=m&1;
  while(tg[now]){
    int nb=__lg(tg[now]&(-tg[now]));
    int a=nb/7, b=nb%7;

    cans=max(cans, dp[now][a][b]);

    tg[now]^=(1LL<<nb);
  }
  ans+=cans;
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