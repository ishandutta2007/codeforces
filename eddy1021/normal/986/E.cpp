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
const int N=200020;
const int X=3163;
bool pp[X];
vector<int> pset;
int lb[N];
void build(){
  for(int i=2; i<X; i++) if(not pp[i]){
    pset.push_back(i);
    for(int j=i; j<X; j+=i)
      pp[j]=true;
  }
  for(int i=0; i<N; i++)
    lb[i]=i&(-i);
}
int BIT[2][N];
void reset_bit(int id){
  fill(BIT[id], BIT[id]+N, 0);
}
void modify(int id, int x, int v){
  for(int i=x; i<N; i+=lb[i])
    BIT[id][i] += v;
}
int query(int id, int x){
  int ret=0;
  for(int i=x; i; i-=lb[i])
    ret += BIT[id][i];
  return ret;
}
int n, a[N], in[N], out[N], stmp, dep[N];
vector<int> v[N], qq[N];
int q, qa[N], qb[N], lca[N], p[N];
int f(int x){
  return x==p[x]?x:p[x]=f(p[x]);
}
void uni(int x, int y){
  p[f(x)]=f(y);
}
void go(int now, int prt, int tdep){
  in[now]=++stmp;
  dep[now]=tdep;
  for(int id: qq[now]){
    if(qb[id] == now) swap(qa[id], qb[id]);
    if(in[qb[id]])
      lca[id]=f(qb[id]);
  }
  for(int son: v[now]){
    if(son == prt) continue;
    go(son, now, tdep+1);
  }
  uni(now, prt);
  out[now]=++stmp;
}
int ans[N], qx[N], oa[N], ox[N];
void init(){
  n=getint();
  for(int i=1; i<n; i++){
    int ui=getint();
    int vi=getint();
    v[ui].push_back(vi);
    v[vi].push_back(ui);
  }
  for(int i=1; i<=n; i++){
    oa[i]=a[i]=getint();
    p[i]=i;
  }
  q=getint();
  for(int i=0; i<q; i++){
    ans[i]=1;
    qa[i]=getint();
    qb[i]=getint();
    ox[i]=qx[i]=getint();
    qq[qa[i]].push_back(i);
    qq[qb[i]].push_back(i);
  }
  go(1, 1, 0);
}
const int K=24;
pair<int,int> teve[K][N+N];
int tsz[K];
pair<int,int> eve[N+N];
void gogo(int pri){
  int ec=0;
  bool need=false;
  for(int i=0; i<K; i++) tsz[i]=0;
  for(int i=1; i<=n; i++){
    int cnt=0;
    while(a[i] % pri == 0){
      cnt++;
      a[i] /= pri;
    }
    if(cnt) need=true;
    teve[cnt][tsz[cnt] ++]={cnt, -i};
    //eve[ec ++]={cnt, -i};
    //eve.push_back({cnt, -i});
  }
  if(not need) return;
  for(int i=0; i<q; i++){
    int cnt=0;
    while(qx[i] % pri == 0){
      cnt++;
      qx[i] /= pri;
    }
    if(cnt)
      teve[cnt][tsz[cnt] ++]={cnt, i};
      //eve[ec ++]={cnt, i};
      //eve.push_back({cnt, i});
  }
  for(int i=0; i<K; i++)
    for(int j=0; j<tsz[i]; j++)
      eve[ec ++]=teve[i][j];
  //sort(eve, eve+ec);
  //sort(eve.begin(), eve.end());
  reset_bit(0);
  reset_bit(1);
  for(int _=0; _<ec; _++){
  //for(auto ee: eve){
    pair<int,int>& ee=eve[_];
    if(ee.second < 0){
      int id=-ee.second;
      modify(0, in[id], +1);
      modify(0, out[id], -1);
      modify(1, in[id], +ee.first);
      modify(1, out[id], -ee.first);
    }else{
      int id=ee.second;
      int gt=query(0, in[qa[id]])-query(0, in[lca[id]])+
             query(0, in[qb[id]])-query(0, in[lca[id]]);
      int sm=query(1, in[qa[id]])-query(1, in[lca[id]])+
             query(1, in[qb[id]])-query(1, in[lca[id]]);
      int tot=dep[qa[id]]+dep[qb[id]]-2*dep[lca[id]];
      int pw=sm+(tot-gt)*ee.first;
      int bns=mypow(pri, pw, mod7);
      int tmp=__gcd(oa[lca[id]], ox[id]);
      while(tmp % pri == 0){
        tmp /= pri;
        bns=mul(bns, pri);
      }
      ans[id]=mul(ans[id], bns);
    }
  }
}
void solve(){
  for(int i: pset) gogo(i);
  //vector< pair<int, int> > eve;
  int ec=0;
  for(int i=1; i<=n; i++)
    if(a[i] > 1)
      eve[ec ++]={a[i], -i};
      //eve.push_back({a[i], -i});
  for(int i=0; i<q; i++)
    if(qx[i] > 1)
      eve[ec ++]={qx[i], i};
      //eve.push_back({qx[i], i});
  sort(eve, eve+ec);
  //sort(eve.begin(), eve.end());
  reset_bit(0);
  for(int l=0, r=0; l<ec; l=r){
  //for(size_t l=0, r=0; l<eve.size(); l=r){
    while(r<ec and eve[l].first == eve[r].first) r++;
    //while(r<eve.size() and eve[l].first == eve[r].first) r++;
    for(int i=l; i<r; i++)
      if(eve[i].second < 0){
        int id=-eve[i].second;
        modify(0, in[id], +1);
        modify(0, out[id], -1);
      }

    for(int i=l; i<r; i++)
      if(eve[i].second >= 0){
        int id=eve[i].second;
        int gt=query(0, in[qa[id]])-query(0, in[lca[id]])+
               query(0, in[qb[id]])-query(0, in[lca[id]]);
        if(__gcd(oa[lca[id]], ox[id]) % eve[l].first == 0) gt++;
        ans[id]=mul(ans[id], mypow(eve[l].first, gt, mod7));
      }

    for(int i=l; i<r; i++)
      if(eve[i].second < 0){
        int id=-eve[i].second;
        modify(0, in[id], -1);
        modify(0, out[id], +1);
      }
  }
  for(int i=0; i<q; i++)
    printf("%d\n", ans[i]);
}
int main(){
  build();
  //__ = getint();
  while(__ --){
    init();
    solve();
  }
}