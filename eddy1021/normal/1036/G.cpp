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
int n, m, od[N], id[N];
vector<int> v[N];
int oid[N], iid[N], tot;
void init(){
  n=getint();
  m=getint();
  while(m--){
    int ui=getint();
    int vi=getint();
    od[ui]++;
    id[vi]++;
    v[ui].push_back(vi);
  }
  int _oid=0, _iid=0;
  for(int i=1; i<=n; i++){
    if(od[i]==0) oid[i]=_oid++;
    else oid[i]=-1;
    if(id[i]==0) iid[i]=_iid++;
    else iid[i]=-1;
  }
  tot=_oid;
}
const int K=20;
int to[K], tg[N], stmp;
void go(int st, int now){
  tg[now]=stmp;
  if(oid[now] >= 0)
    to[st]|=(1<<oid[now]);
  for(int nxt: v[now]){
    if(tg[nxt] == stmp) continue;
    go(st, nxt);
  }
}
int msk[1<<K], cb[1<<K];
void solve(){
  for(int i=1; i<=n; i++)
    if(iid[i] >= 0){
      ++stmp;
      go(iid[i], i);
    }
  for(int i=1; i<(1<<tot); i++)
    cb[i]=cb[i>>1]+(i&1);
  bool win=false;
  for(int i=1; i<(1<<tot) and not win; i++){
    for(int j=0; j<tot; j++)
      if((i >> j) & 1)
        msk[i]=msk[i^(1<<j)]|to[j];
    if(i < (1<<tot)-1){
      if(cb[i] == cb[msk[i]])
        win=true;
    }
  }
  puts(win?"NO":"YES");
}
int main(){
  build();
  //__ = getint();
  while(__ --){
    init();
    solve();
  }
}