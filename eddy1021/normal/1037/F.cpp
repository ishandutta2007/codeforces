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
int p[N], l[N], r[N];
int f(int x){
  return x==p[x]?x:p[x]=f(p[x]);
}
void uni(int x, int y){
  x=f(x); y=f(y);
  if(x==y) return;
  p[x]=y;
  l[y]=min(l[y], l[x]);
  r[y]=max(r[y], r[x]);
}
const int inv2=(mod7+1)/2;
inline int AM(LL a0, LL d0, LL nn){
  return mul(mul(add(add(a0, a0), mul(nn-1, d0)), nn), inv2);
}
void build(){

}
int n, k, a[N];
int val(int lb, int md, int rb, int len){
  int llb=max(lb, md-len+1);
  int rrb=min(md, rb-len+1);
  return max(0, rrb-llb+1);
}
int cal(int lb, int md, int rb){
  int ret=0;
  int llen=md-lb+1;
  int rlen=rb-md+1;
  if(llen > rlen) swap(llen, rlen);
  int til=(llen-1)/(k-1);
  //printf("%d\n", til);
  if(1 <= til) ret=add(ret, AM(k, k-1, til));
  int rtil=(rlen-1)/(k-1);
  //printf("%d\n", rtil);
  if(til < rtil) ret=add(ret, mul(llen, rtil-til));
  int rrtil=(rb-lb)/(k-1);
  //printf("%d\n", rrtil);
  if(rtil < rrtil){
    int v1=val(lb, md, rb, (rtil+1)*(k-1)+1);
    int v2=val(lb, md, rb, rrtil*(k-1)+1);
    int tmp=mul(mul(add(v1, v2), rrtil-rtil), inv2);
    ret=add(ret, tmp);
  }
  //printf("%d %d %d ret=%d\n", lb, md, rb, ret);
  return ret;
}
void init(){
  n=getint();
  k=getint();
  for(int i=0; i<n; i++)
    a[i]=getint();
}
int ans, id[N];
bool in[N];
void solve(){
  for(int i=0; i<n; i++)
    id[i]=p[i]=l[i]=r[i]=i;
  sort(id, id+n, [&](int id1, int id2){return a[id1]<a[id2];});
  for(int _=0; _<n; _++){
    int i=id[_];
    in[i]=true;
    if(i     and in[i-1]) uni(i, i-1);
    if(i+1<n and in[i+1]) uni(i, i+1);
    int pp=f(i);
    ans=add(ans, mul(a[i], cal(l[pp], i, r[pp])));
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