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
const int N=514;
void build(){

}
int n;
char mp[N][N];
int dp[N][N], stmp;
inline bool ok(int r1, int c1, int r2, int c2){
  fprintf(stderr, "q %d %d -> %d %d\n", r1, c1, r2, c2);
  assert(r2 >= r1 and c2 >= c1);
  int dlt=r2-r1+c2-c1;
  assert(dlt >= n-1);
#ifdef TEST
  ++ stmp;
  for(int i=r2; i>=r1; i--)
    for(int j=c2; j>=c1; j--){
      if(mp[i][j] == '#') continue;
      if(i == r2 and j == c2){
        dp[i][j]=stmp;
        continue;
      }
      if(i+1 <= r2 and dp[i+1][j] == stmp) dp[i][j]=stmp;
      if(j+1 <= c2 and dp[i][j+1] == stmp) dp[i][j]=stmp;
    }
  return dp[r1][c1]==stmp;
#else
  printf("? %d %d %d %d\n", r1, c1, r2, c2);
  fflush(stdout);
  char buf[64]; scanf("%s", buf);
  return buf[0]=='Y';
#endif
}
void init(){
  n=getint();
#ifdef TEST
  for(int i=1; i<=n; i++)
    scanf("%s", mp[i]+1);
#endif
}
string lans, rans;
void go(){
  {
    int r1=1, c1=1;
    while(r1 + c1 < n+1){
      {
        if(c1+1 <= n and ok(r1, c1+1, n, n)){
          lans+="R";
          c1++;
          continue;
        }
      }
      lans+="D";
      r1++;
    }
  }
  int r2=n, c2=n;
  while(r2 + c2 > n+1){
    {
      if(r2-1 >= 1 and ok(1, 1, r2-1, c2)){
        rans+="D";
        r2--;
        continue;
      }
    }
    rans+="R";
    c2--;
  }
  reverse(rans.begin(), rans.end());
  lans+=rans;
  printf("! %s\n", lans.c_str());
  fflush(stdout);
  exit(0);
}
void solve(){
  go();
}
int main(){
  build();
  //__ = getint();
  while(__ --){
    init();
    solve();
  }
}