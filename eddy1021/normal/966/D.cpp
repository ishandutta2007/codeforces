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
#define N 303030
void build(){

}
int n, m;
vector<int> v[N];
unordered_set<int> s[N];
void init(){
  //n=514;
  //for(int i=1;i<n;i++)
    //for(int j=i+1;j<n;j++){
      //v[i].push_back(j);
      //v[j].push_back(i);
      //s[i].insert(j);
      //s[j].insert(i);
    //}
  //return;
  n=getint();
  m=getint();
  while(m --){
    int a=getint();
    int b=getint();
    v[a].push_back(b);
    v[b].push_back(a);

    s[a].insert(b);
    s[b].insert(a);
  }
}
vector<int> ans, ans2;
void output(){
  printf("%d\n", (int)ans.size() - 1);
  for(size_t i=0; i<ans.size(); i++)
    printf("%d%c", ans[i], " \n"[i + 1 == ans.size()]);
  exit(0);
}
int dst[N], fr[N];
bool has(int now, int goal){
  return s[now].find(goal) != s[now].end();
}
vector<int> cand;
bool vst[N];
void gogo(int now){
  vst[now]=true;
  cand.push_back(now);
  for(int nxt: v[now]){
    if(vst[nxt]) continue;
    gogo(nxt);
  }
}
int dst2[N], fr2[N], stk[N];
void gogogogo(int ss, int tt){
  for(int i:cand)
    dst2[i]=-1;
  dst2[ss]=0;
  queue<int> Q;
  Q.push(ss);
  while(Q.size()){
    int tn=Q.front(); Q.pop();
    for(int nxt: v[tn]){
      if(nxt == 1 or dst2[nxt]!=-1)
        continue;
      dst2[nxt]=dst2[tn]+1;
      fr2[nxt]=tn;
      Q.push(nxt);
    }
  }
  int now=tt, ptr=0;
  while(now != ss){
    stk[ptr++]=now;
    now=fr2[now];
  }
  for(int i=0;i+2<ptr;i++)
    if(not has(stk[i], stk[i+2])){
      ans2.clear();
      ans2.push_back(1);
      ans2.push_back(stk[i]);
      ans2.push_back(stk[i+1]);
      ans2.push_back(stk[i+2]);
      ans2.push_back(stk[i]);
      ans2.push_back(n);
      return;
    }
}
void gogogo(){
  vst[1]=true;
  for(int nxt: v[1]){
    if(vst[nxt]) continue;
    cand.clear();
    gogo(nxt);
    LL es=0;
    for(auto i: cand)
      es+=v[i].size()-1u;
    if(es == (LL)cand.size()*(LL)(cand.size() - 1u))
      continue;
    for(auto i: cand){
      for(size_t i1=0; i1<v[i].size(); i1++)
        for(size_t i2=i1+1; i2<v[i].size(); i2++){
          if(not has(v[i][i1], v[i][i2])){
            ans2.clear();
            ans2.push_back(1);
            ans2.push_back(v[i][i1]);
            ans2.push_back(i);
            ans2.push_back(v[i][i2]);
            ans2.push_back(v[i][i1]);
            ans2.push_back(n);
            return;
          }
        }
    }
    //for(size_t i=0; i<cand.size(); i++)
      //for(size_t i2=i+1; i2<cand.size(); i2++){
        //if(not has(cand[i], cand[i2])){
          //gogogogo(cand[i], cand[i2]);
          //if(ans2.size())
            //return;
        //}
      //}
  }
  return;
  for(int i: cand){
    for(size_t _=0; _<v[i].size(); _++){
      for(size_t _2=_+1; _2<v[i].size(); _2++){
        int v1=v[i][_], v2=v[i][_2];
    //for(int v1: v[i]){
      //for(int v2: v[i]){
        if(v1 == v2 or v1==1 or v2==1)
          continue;
        if(not has(v1, v2)){
          ans2.clear();
          ans2.push_back(1);
          ans2.push_back(v1);
          ans2.push_back(i);
          ans2.push_back(v2);
          ans2.push_back(v1);
          ans2.push_back(n);
          return;
        }
      }
    }
  }
}
void solve(){
  for(int i=1; i<=n; i++)
    dst[i]=-1;
  dst[1]=0;
  queue<int> Q;
  Q.push(1);
  while(Q.size()){
    int tn=Q.front(); Q.pop();
    for(int nxt: v[tn]){
      if(dst[nxt] != -1) continue;
      dst[nxt]=dst[tn]+1;
      fr[nxt]=tn;
      Q.push(nxt);
    }
  }
  if(dst[n] != -1){
    ans.clear();
    int now=n;
    while(now!=1){
      ans.push_back(now);
      now=fr[now];
    }
    ans.push_back(1);
    reverse(ans.begin(), ans.end());
    //output();
  }
  for(int i=1; i<=n; i++)
    if(dst[i] == 2){
      ans2.clear();
      ans2.push_back(1);
      ans2.push_back(fr[i]);
      ans2.push_back(i);
      ans2.push_back(1);
      ans2.push_back(n);
      break;
      //output();
    }
  if(ans2.empty())
    gogogo();
  if(not ans2.empty() and
     (ans.empty() or ans2.size() < ans.size()))
    ans=ans2;
  if(ans.size())
    output();
  puts("-1");
}
int main(){
  build();
  //__ = getint();
  while(__ --){
    init();
    solve();
  }
}