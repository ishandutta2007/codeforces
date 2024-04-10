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
const int N=101010;
void build(){

}
LL n, l[N];
char c[N];
void init(){
  n=getint();
  for(int i=0; i<n; i++)
    l[i]=getint();
  scanf("%s", c);
}
LL opt(vector<pair<int,LL>>& vw,
       vector<pair<int,LL>>& vg){
  vector<pair<int,LL>> vv;
  LL pw=0, dw=0;
  for(auto i: vw){
    vv.push_back({i.first, +i.second});
    pw+=i.second;
  }
  for(auto i: vg) vv.push_back({i.first, -i.second});
  sort(vv.begin(), vv.end());
  reverse(vv.begin(), vv.end());
  LL ret=0;
  for(auto p: vv){
    LL val=abs(p.second);
    if(p.second < 0){
      if(pw){
        LL tk=min(pw, val);
        val-=tk;
        pw-=tk;
        dw+=tk;
        ret+=tk;
      }
      if(val == 0) continue;
      ret+=val*3;
      continue;
    }
    if(dw){
      LL tk=min(dw, val);
      val-=tk;
      dw-=tk;
      ret+=tk*3;
    }
    if(val > 0){
      pw-=val;
      ret+=val*2;
    }
  }
  return ret;
}
LL cal(){
  vector< pair<int,LL> > vw, vg;
  LL ans=0;
  bool pass_W=false;
  for(int i=0; i<n; i++)
    if(c[i] == 'L'){
      while(l[i]>0 and vw.size()){
        LL tk=min(vw.back().second, l[i]);
        vw.back().second-=tk;
        if(vw.back().second == 0) vw.pop_back();
        l[i]-=tk;
        ans+=tk*4;
      }
      while(l[i]>0 and vg.size()){
        LL tk=min(vg.back().second, l[i]);
        vg.back().second-=tk;
        if(vg.back().second == 0) vg.pop_back();
        l[i]-=tk;
        ans+=tk*6;
      }
      if(l[i] == 0) continue;
      if(pass_W){
        ans+=l[i]*4;
        continue;
      }
      ans+=l[i]*6;
    }else if(c[i] == 'W'){
      pass_W=true;
      vw.push_back({i, l[i]});
    }else
      vg.push_back({i, l[i]});
  ans+=opt(vw, vg);
  return ans;
}
void solve(){
  printf("%lld\n", cal());
}
int main(){
  build();
  //__ = getint();
  while(__ --){
    init();
    solve();
  }
}