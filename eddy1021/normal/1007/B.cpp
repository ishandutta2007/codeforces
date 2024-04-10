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
LL ndiv[N], C[N][4];
LL _C(LL a, LL b){
  LL ret=1;
  for(int i=0; i<b; i++) ret*=(a-i);
  for(int i=0; i<b; i++) ret/=(b-i);
  return ret;
}
void build(){
  for(int i=1; i<N; i++)
    for(int j=i; j<N; j+=i)
      ndiv[j]++;
  for(int i=1; i<N; i++)
    for(int j=1; j<4; j++)
      C[i][j]=_C(i, j);
}
LL a[3];
LL GCD[8];
void init(){
  for(int i=0; i<3; i++)
    a[i]=getint();
}
LL H(LL A, LL B){
  if(A+B-1<0) return 0;
  return C[A+B-1][B];
}
LL ans, way[N], tk[N];
unordered_set<LL> hs;
void cal(){
  LL hsvl=0;
  for(int i=0; i<8; i++)
    hsvl=(hsvl<<2)|tk[i];
  if(hs.find(hsvl) != hs.end()) return;
  hs.insert(hsvl);
  LL ret=1;
  for(int i=1; i<8; i++)
    if(tk[i])
      ret*=H(way[i], tk[i]);
  ans+=ret;
}
void go(int now){
  if(now==3){
    cal();
    return;
  }
  for(int i=1; i<8; i++)
    if((i>>now)&1){
      tk[i]++;
      go(now+1);
      tk[i]--;
    }
}
LL bf(){
  set<vector<LL>> vv;
  for(int i=1; i<=a[0]; i++) if((a[0]%i)==0)
    for(int j=1; j<=a[1]; j++) if((a[1]%j)==0)
      for(int k=1; k<=a[2]; k++) if((a[2]%k)==0){
        vector<LL> tv={i, j, k};
        sort(tv.begin(), tv.end());
        vv.insert(tv);
      }
  return vv.size();
}
void solve(){
  hs.clear();
  for(int i=1; i<8; i++){
    LL gg=0;
    for(int j=0; j<3; j++)
      if((i>>j)&1){
        gg=__gcd(gg, a[j]);
      }
    GCD[i]=gg;
  }
  for(int i=7; i; i--){
    way[i]=ndiv[GCD[i]];
    for(int ii=7; ii>i; ii--)
      if((ii&i)==i)
        way[i]-=way[ii];
  }
  ans=0;
  go(0);
#ifndef ONLINE_JUDGE
  if(ans != bf()){
    cerr<<a[0]<<" ";
    cerr<<a[1]<<" ";
    cerr<<a[2]<<"\n";
    cerr<<ans<<endl;
    cerr<<bf()<<endl;
    assert(ans == bf());
  }
#else
  printf("%lld\n", ans);
#endif
}
int main(){
  build();


  //for(a[0]=1; a[0]<=10; a[0]++)
    //for(a[1]=1; a[1]<=10; a[1]++)
      //for(a[2]=1; a[2]<=10; a[2]++)
        //solve();


  __ = getint();
  while(__ --){
    init();
    solve();
  }
}