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
const int N=200020;
vector<int> f[N];
void build(){
  for(int i=1; i<N; i++)
    for(int j=i; j<N; j+=i)
      f[j].push_back(i);
}
int n, a[N];
vector<int> v[N];
vector<int> wt[N];
void init(){
#ifdef TEST
  n=200000;
#else
  n=getint();
#endif
  for(int i=1; i<=n; i++)
#ifdef TEST
    a[i]=166320;
#else
    a[i]=getint();
#endif
  for(int i=1; i<n; i++){
#ifdef TEST
    int xi=i;
    int yi=i+1;
#else
    int xi=getint();
    int yi=getint();
#endif
    v[xi].push_back(yi);
    v[yi].push_back(xi);
  }
  for(int i=1; i<=n; i++)
    for(int d: f[a[i]])
      wt[d].push_back(i);
}
LL cnt[N];
int tg[N], got;
LL C(LL x){return x*(x+1)/2;}
void gogo(int now, int g){
  tg[now]=g;
  got++;
  for(int nxt: v[now]){
    if(tg[nxt]==g or
       a[nxt] % g)
      continue;
    gogo(nxt, g);
  }
}
void solve(){
  for(int i=1; i<N; i++){
    if(wt[i].empty()) continue;
    for(int id: wt[i]){
      if(tg[id] == i) continue;
      got=0;
      gogo(id, i);
      cnt[i]+=C(got);

    }
  }
  for(int i=N-1; i; i--)
    for(int j=i+i; j<N; j+=i)
      cnt[i]-=cnt[j];
  for(int i=1; i<N; i++)
    if(cnt[i])
      printf("%d %lld\n", i, cnt[i]);
}
int main(){
  build();
  //__ = getint();
  while(__ --){
    init();
    solve();
  }
}