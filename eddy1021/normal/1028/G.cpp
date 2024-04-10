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
#define int LL
#ifdef TEST
LL x;
#endif
const LL inf=10004205361450474LL;
const LL N=1e4;
void build(){
  
}
int qed=0;
inline int ask(const vector<LL>& k){
  assert(++qed <= 5);
#ifdef TEST
  assert(k.size());
  assert((int)k.size() <= x);
  for(size_t i=0; i+1<k.size(); i++)
    if(k[i] >= k[i+1])
      assert(false);
  for(LL i: k) if(i == x) return -1;
  if(x < k[0]) return 0;
  int ret=0;
  for(size_t i=0; i<k.size(); i++)
    if(k[i] < x)
      ret=i+1;
  return ret;
#else
  printf("%d", (int)k.size());
  for(LL xx: k) printf(" %lld", xx);
  puts("");
  fflush(stdout);
  int ret=getint();
  if(ret == -2) assert(false);
  return ret;
#endif
}
void init(){
#ifdef TEST
  x=getint();
#endif
}
LL til(LL st, LL tms, vector<LL>& tmp){
  if(tms == 1) return st+min(st, N)-1;
  vector<LL> _;
  LL pre=til(st, tms-1, _);
  tmp.clear();
  for(LL i=0; i<min(st, N); i++){
    LL cur=pre+1;
    tmp.push_back(cur);
    pre=til(cur+1, tms-1, _);
  }
  return pre;
}
void go(LL lb, LL rb){
  if(lb < N){
    vector<LL> cand;
    til(lb, 5-qed, cand);
    while(cand.size() and cand.back() > rb) cand.pop_back();
    if(cand.size()){
      sort(cand.begin(), cand.end());
      cand.resize(unique(cand.begin(), cand.end())-cand.begin());
      int ret=ask(cand);
      if(ret == -1) return ;
      if(ret == 0) go(lb, cand[0]-1);
      else if(ret == (int)cand.size()) go(cand.back()+1, rb);
      else go(cand[ret-1]+1, cand[ret]-1);
      return;    
    }
  }
  LL sz=min(lb, N);
  vector<LL> cand;
  if(rb-lb+1<=sz){
    for(LL i=lb; i<=rb; i++)
      cand.push_back(i);
  }else{
    LL per=max(0LL, ((rb-lb+1)-sz)/(sz+1));
    LL mr=((rb-lb+1)-sz)%(sz+1);
    for(LL i=0, qq=lb; i<sz; i++){
      qq+=per;
      if(i < mr) qq++;
      cand.push_back(min(rb, qq));
      qq++;
    }
    sort(cand.begin(), cand.end());
    cand.resize(unique(cand.begin(), cand.end())-cand.begin());
  }
  //cerr<<lb<<" "<<rb<<" "<<cand.size()<<endl;
  int ret=ask(cand);
  if(ret == -1) return ;
  if(ret == 0) go(lb, cand[0]-1);
  else if(ret == (int)cand.size()) go(cand.back()+1, rb);
  else go(cand[ret-1]+1, cand[ret]-1);
}
//const LL A1=204761410473LL;
//const LL A1=204661380463LL;
//const LL A1=204661380463LL;
const LL A1=204761410474LL;
const LL A2=2046;
void solve(){
  {
    int ret=ask({A1});
    if(ret == -1) return;
    if(ret == 1){
      go(A1+1, inf);
      return;
    }
  }
  {
    int ret=ask({A2});
    if(ret == -1) return;
    if(ret == 1){
      go(A2+1, A1-1);
      return;
    }
  }
  {
    int ret=ask({6});
    if(ret == -1) return;
    if(ret == 1){
      vector<LL> magic={14,30,62,126,254,510,1022};
      ret=ask(magic);
      if(ret == -1) return;
      if(ret == 0){
        go(7, 13);
        return;
      }
      if(ret == (int)magic.size()){
        go(magic.back()+1, A2-1);
        return;
      }
      go(magic[ret-1]+1, magic[ret]-1);
      return;
    }
  }
  {
    int ret=ask({2});
    if(ret == -1) return;
    if(ret == 1) ask({3, 4, 5});
    else ask({1});
  }
}
const int B=13131;
int32_t main(){
  //vector<LL> dump;
  //cerr<<til(7, 2, dump)<<endl;
  //cerr<<til(2047, 3, dump)<<endl;
  //exit(0);
#ifdef TEST
  //init();
  //solve();
  //for(x=A2-100; x<=A2+100; x++){
    //printf("%lld \n", x);
    //qed=0;
    ////init();
    //solve();
  //}
  for(x=A1-0; x>=A1-10; x--){
    printf("%lld \n", x);
    qed=0;
    //init();
    solve();
  }
  for(x=A1+0; x<=A1+10; x++){
    printf("%lld \n", x);
    qed=0;
    //init();
    solve();
  }
  for(x=inf; x>=inf-B; x--){
    printf("%lld \n", x);
    qed=0;
    //init();
    solve();
  }
  //exit(0);
#else
  build();
  //__ = getint();
  while(__ --){
    init();
    solve();
  }
#endif
}