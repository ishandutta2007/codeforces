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
//inline LL sub(LL _x, LL _y, LL _mod=mod7){
  //_x-=_y;
  //return _x<0 ? _x+_mod : _x;
//}
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
const int N=505050;
void build(){

}
LL n, a[N];
LL sa[N];
void init(){
  n=getint();
  for(LL i=1; i<=n; i++)
    a[i]=getint();
  sort(a+1, a+n+1);
  reverse(a+1, a+n+1);
  for(LL i=1; i<=n; i++)
    sa[i]=sa[i-1]+a[i];
}
LL ok[N];
void on(LL la, LL ra){
  if(la > ra) return;
  ok[la]++;
  ok[ra+1]--;
}
vector<LL> ans;
LL sgar[N], sub[N];
void go(){
  LL sum=accumulate(a, a+n+1, 0LL);


  priority_queue<LL> heap;
  LL heap_sum=0, mr=0;
  
  priority_queue<LL> sheap;
  LL sheap_sum=0, smr=0;

  LL ub=n;
  sub[n+1]=n-1;
  for(LL i=n; i>=1; i--){
  // as (i+1)
  // sa[i]+ ? <= (i+1)*i + *gar*
    if(i+1<=n){
      heap.push(a[i+1]);
      heap_sum+=a[i+1];
      sheap.push(a[i+1]);
      sheap_sum+=a[i+1];
    }
    while(heap.size() and heap.top()>i+1){
      heap_sum-=heap.top();
      heap.pop();
      mr++;
    }
    while(sheap.size() and sheap.top()>i){
      sheap_sum-=sheap.top();
      sheap.pop();
      smr++;
    }
    LL gar=heap_sum+mr*(i+1);
    sgar[i]=sheap_sum+smr*i;

    LL tub=i*(i+1)+gar-sa[i];
    ub=min(ub, tub);
    sub[i]=ub;
  }
  // maximum
  LL til=a[1];
  {
    LL tmp=0;
    for(LL i=1; i<=n; i++)
      tmp+=min(a[i], 1LL);
    on(til, tmp);
    //for(int i=tmp; i>=til; i--)
      //ans.push_back(i);
  }
  LL lb=0;
  for(LL i=1; i<n; i++){
  // as i
  // sa[i] <= i*(i-1) + *gar* + min(?, i)
    LL tlb=sa[i]-i*(i-1)-sgar[i];
    lb=max(lb, tlb);
    // min(?, i) >= lb
    // ? <= sub[i+1]
    // ? <= a[i]
    // ? >= a[i+1]
    
    LL cmx=min(sub[i+1], a[i]);
    LL cmn=max(a[i+1], lb);
    if(lb <= i) on(cmn, cmx);
    //if(lb <= i) on(max(lb, a[i+1]), a[i]);
  }
  {
    // ? >= 0
    // ? <= a[n]
    // ? >= lb
    // ? <= n*(n+1)-sum
    LL cmx=min(a[n], n*(n+1)-sum);
    LL cmn=max(0LL, lb);
    if(cmn <= cmx and lb <= n+1) on(cmn, cmx);
  }
  //if(lb<=a[n]) on(lb, a[n]);


  for(LL i=1; i<=ub; i++) ok[i]+=ok[i-1];
  for(LL i=0; i<=ub; i++)
    if(ok[i] > 0 and (i+sum)%2==0)
      ans.push_back(i);
}
void solve(){
  go();
  if(ans.empty()) puts("-1");
  else{
    for(size_t i=0; i<ans.size(); i++)
      printf("%lld%c", ans[i], " \n"[i+1==ans.size()]);
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