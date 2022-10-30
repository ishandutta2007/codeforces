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
const int N=52;
int C[N][N], C2[N][2];
void build(){
  for(int i=0; i<N; i++)
    C[i][0]=C[i][i]=1;
  for(int i=2; i<N; i++)
    for(int j=1; j<i; j++)
      C[i][j]=add(C[i-1][j], C[i-1][j-1]);
  for(int i=0; i<N; i++)
    for(int j=0; j<N; j++)
      C2[i][j&1]=add(C2[i][j&1], C[i][j]);
}
inline int CC(int x, int p){
  return C2[x][p];
}
int n, req, c[N];
void init(){
  n=getint();
  req=getint();
  for(int i=1; i<=n; i++)
    c[i]=getint();
}
int dp[2][N][N][N][N][2];
int inq[2][N][N][N][N][2];
vector< tuple<int,int,int,int,int> > Q[2];
void solve(){
  Q[0].push_back(make_tuple(0, 0, 0, 0, 0));
  dp[0][0][0][0][0][0]=1;
  int ans=0;
  for(int i=1; i<=n+1; i++){
    int now=i&1, pre=1-now;
    for(auto tp: Q[pre]){
      int o1=get<0>(tp);
      int e1=get<1>(tp);
      int o2=get<2>(tp);
      int e2=get<3>(tp);
      int pr=get<4>(tp);
      int val=dp[pre][o1][e1][o2][e2][pr];
      if(i == n+1){
        if(pr == req)
          ans=add(ans, val);
        continue;
      }
      if(val == 0) continue;
      for(int to_o1=0; to_o1<2; to_o1++)
        for(int to_e1=0; to_e1<2; to_e1++)
      for(int to_o2=0; to_o2<2; to_o2++)
        for(int to_e2=0; to_e2<2; to_e2++){
          for(int my_clr=0; my_clr<2; my_clr++){
            if(c[i]>=0 and c[i] != my_clr) continue;

            int way=val;
            way=mul(way, CC(o1, to_o1));
            way=mul(way, CC(e1, to_e1));
            way=mul(way, CC(o2, to_o2));
            way=mul(way, CC(e2, to_e2));           
            
            int no1=o1, ne1=e1;
            int no2=o2, ne2=e2;

            int my_par=1;
            if(my_clr == 0)
              my_par=(my_par+to_o2)&1;
            else
              my_par=(my_par+to_o1)&1;
            if(my_clr == 0){
              if(my_par) no1 ++;
              else ne1 ++;
            }else{
              if(my_par) no2 ++;
              else ne2 ++;
            }
            
            int npr=(pr+my_par)&1;

            int& to=dp[now][no1][ne1][no2][ne2][npr];
            to=add(to, way);
            if(inq[now][no1][ne1][no2][ne2][npr] != i){
              inq[now][no1][ne1][no2][ne2][npr] = i;
              Q[now].push_back(make_tuple(no1, ne1, no2, ne2, npr));
            }
          }
        }
      Q[pre].clear();
    }
  }
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