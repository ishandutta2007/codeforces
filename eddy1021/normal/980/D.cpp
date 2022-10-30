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
const int N=5140;
const int P=1e5;
bool np[P];
vector<int> pset;
void build(){
  for(int i=2; i<P; i++) if(not np[i]){
    pset.push_back(i);
    for(int j=i; j<P; j+=i) np[j]=true;
  }
}
int mask(int val){
  if(val == 0) return val;
  int ret=val;
  val=abs(val);
  for(int i: pset){
    if((LL)i * i > val) break;
    while(val % (i * i) == 0){
      val /= (i * i);
      ret /= (i * i);
    }
  }
  return ret;
}
int n, a[N], aa[N];
void init(){
  n=getint();
  vector<int> li;
  for(int i=0; i<n; i++){
    a[i]=mask(getint());
    li.push_back(a[i]);
  }
  sort(li.begin(), li.end());
  li.resize(unique(li.begin(), li.end())-li.begin());
  for(int i=0; i<n; i++)
    aa[i]=lower_bound(li.begin(), li.end(), a[i])-li.begin();
}
int cnt[N], ans[N], ac;
void solve(){
  for(int i=0; i<n; i++){
    ac=0;
    for(int j=0; j<n; j++) cnt[j]=0;
    for(int j=i; j<n; j++){
      if(a[j]){
        cnt[aa[j]]++;
        if(cnt[aa[j]] == 1)
          ac++;
      }
      ans[max(1, ac)]++;
    }
  }
  for(int i=1; i<=n; i++)
    printf("%d%c", ans[i], " \n"[i == n]);
}
int main(){
  build();
  //__ = getint();
  while(__ --){
    init();
    solve();
  }
}