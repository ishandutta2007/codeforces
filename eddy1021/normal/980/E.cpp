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
const int K=20;
const int N=(1 << 20);
int n, k;
vector<int> v[N];
void build(){

}
bool in[N];
int p[K][N], dep[N];
void go(int now, int prt, int tdep){
  p[0][now]=prt;
  dep[now]=tdep;
  for(int son: v[now]){
    if(son == prt) continue;
    go(son, now, tdep+1);
  }
}
void init(){
  n=getint();
  k=getint();
  for(int i=1; i<n; i++){
    int ai=getint();
    int bi=getint();
    v[ai].push_back(bi);
    v[bi].push_back(ai);
  }
  go(n, n, 0);
  for(int j=1; j<K; j++)
    for(int i=1; i<=n; i++)
      p[j][i]=p[j-1][p[j-1][i]];
}
void solve(){
  k=n-k;
  in[n]=true;
  k--;
  for(int i=n-1; i>=1 and k>0; i--){
    if(in[i]) continue;
    int cur=i;
    for(int j=K-1; j>=0; j--)
      if(not in[p[j][cur]])
        cur=p[j][cur];
    if(dep[i]-dep[cur]+1 <= k){
      cur = i;
      while(not in[cur]){
        in[cur]=true;
        k--;
        cur=p[0][cur];
      }
    }
  }
  vector<int> ans;
  for(int i=1; i<=n; i++)
    if(not in[i])
      ans.push_back(i);
  for(size_t i=0; i<ans.size(); i++)
    printf("%d%c", ans[i], " \n"[i + 1 == ans.size()]);
}
int main(){
  build();
  //__ = getint();
  while(__ --){
    init();
    solve();
  }
}