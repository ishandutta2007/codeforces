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
struct Trie{
  int mn;
  Trie *s[2];
  Trie(){
    mn=1e9;
    s[0]=s[1]=NULL;
  }
};
const int K=18;
const int N=131073;
const int BD=222;
Trie* st[BD];
void add(Trie* now, int bt, int val){
  now->mn=min(now->mn, val);
  if(bt < 0) return;
  int b=(val>>bt)&1;
  if(!now->s[b]) now->s[b]=new Trie();
  add(now->s[b], bt-1, val);
}
void go(Trie* now, int bt, int atmst, int val, int& ret, int cur){
  if(bt < 0){
    ret=max(ret, cur^val);
    return;
  }
  int b=(val>>bt)&1;
  for(int i=1; i>=0; i--){
    int g=b^i;
    if(now->s[g] and now->s[g]->mn <= atmst){
      go(now->s[g], bt-1, atmst, val, ret, cur | (g << bt));
      return;
    }
  }
}
int q(Trie* now, int qv, int atmst){
  if(atmst<1 or !now) return -1;
  int ret=-1;
  go(now, K-1, atmst, qv, ret, 0);
  return ret;
}
void build(){

}
bool has[N];
int qq;
const int inf=1e5;
void init(){
  qq=getint();
}
void solve(){
  while(qq--){
    int cmd=getint();
    if(cmd == 1){
      int ui=getint();
      has[ui]=true;
      for(int i=1; i<BD; i++){
        if(ui % i) continue;
        if(!st[i]) st[i]=new Trie();
        add(st[i], K-1, ui);
      }
      continue;
    }
    int xi=getint();
    int ki=getint();
    int si=getint();
    if(xi % ki){
      puts("-1");
      continue;
    }
    if(ki < BD){
      int atmst=si-xi;
      int ans=-1;
      if(atmst>=1)
        ans=q(st[ki], xi, atmst);
      if(ans != -1) ans^=xi;
      printf("%d\n", ans);
      continue;
    }
    int ans=-1;
    for(int i=ki; i<=min(inf, si-xi); i+=ki){
      if(not has[i]) continue;
      ans=max(ans, i^xi);
    }
    if(ans != -1) ans^=xi;
    printf("%d\n", ans);
  }
}
int main(){
  build();
  //__ = getint();
  while(__ --){
    init();
    solve();
  }
}