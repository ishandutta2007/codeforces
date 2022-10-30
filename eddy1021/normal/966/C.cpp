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
#define N 101010
#define K 62
void build(){

}
LL n;
vector<LL> cand[K];
clock_t s;
void init(){
  s=clock();
  n=getint();
  while(n --){
    LL ai=getint();
    LL hb=0;
    for(int i=0; i<K; i++)
      if((ai >> i) & 1LL)
        hb=i;
    cand[hb].push_back(ai);
  }
}
vector<LL> ans;
void no(){
  puts("No");
  exit(0);
}
LL a[N];
bool check(){
  ans.clear();
  for(LL i=K-1; i>=0; i--){
    if(cand[i].size()>ans.size()+1u) no();
    vector<LL> tmp;
    LL pre=0;
    size_t ptr=0;
    for(LL k: ans){
      if(ptr < cand[i].size()){
        if(pre < (pre ^ cand[i][ptr])){
          tmp.push_back(cand[i][ptr]);
          pre ^= cand[i][ptr++];
        }
      }
      pre ^= k;
      tmp.push_back(k);
    }
    if(ptr<cand[i].size())
      tmp.push_back(cand[i][ptr++]);
    if(ptr<cand[i].size())
      return false;
    //for(size_t jj=0;jj<max(cand[i].size(), ans.size()); jj++){
      //if(jj < cand[i].size()) tmp.push_back(cand[i][jj]);
      //if(jj < ans.size()) tmp.push_back(ans[jj]);
    //}
    ans.swap(tmp);
  }
  a[0]=ans[0];
  for(size_t i=1; i<ans.size(); i++){
    a[i]=a[i-1]^ans[i];
    if(a[i] <= a[i-1])
      return false;
  }
  return true;
}
void output(){
  puts("Yes");
  for(size_t i=0; i<ans.size(); i++)
    printf("%lld%c", ans[i], " \n"[i + 1 == ans.size()]);
  exit(0);
}
void solve(){
  if(check()) output();
  for(int i=0; i<K; i++)
    sort(cand[i].begin(), cand[i].end());
  if(check()) output();
  for(int i=0; i<K; i++)
    reverse(cand[i].begin(), cand[i].end());
  if(check()) output();
  while(((clock() - s) < 1.8 * CLOCKS_PER_SEC)){
    for(int i=0; i<K; i++)
      random_shuffle(cand[i].begin(), cand[i].end());
    if(check()) output();
  }
  no();
}
int main(){
  srand(514^1021);
  build();
  //__ = getint();
  while(__ --){
    init();
    solve();
  }
}