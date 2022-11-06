#include<bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=(a),i##_end=(b);i<i##_end;++i)
using ll=long long;
#ifdef flukehn
#include "algo/debug.h"
#else
#define dbg(...) 0
#define debug(...) 0
#endif
const int N=100'011;
const int M=30;
struct T{
  T *c[2];
  int s;
} pool[N*M*2];
T *cnt;
T *rt[N];
T* nT(){
  cnt->c[0]=cnt->c[1]=rt[0];
  cnt->s=0;
  return cnt++;
}

int n;
int a[N];
void upd(T *&x,T *o,int d,int v) {
  x=nT();
  if(o){
    x->c[0]=o->c[0];
    x->c[1]=o->c[1];
    x->s=o->s+1;
  }
  if(d<0) return;
  int w=v>>d&1;
  if(!w) upd(x->c[0],o->c[0],d-1,v);
  else upd(x->c[1],o->c[1],d-1,v);
}
int S(T *x) {return x?x->s:0;}
vector<int> ad;
void append(T *u,T *v,int d,int now){
  if(S(u)<=S(v)) return;
  if(d<0) {
    For(i,0,S(u)-S(v))ad.push_back(now);
  }else{
    //if(S(u->c[0])>S(v->c[0])) 
      append(u->c[0],v->c[0],d-1,now);
    //if(S(u->c[1])>S(v->c[1])) 
      append(u->c[1],v->c[1],d-1,now|(1<<d));
  }
}
int ans;
void qry(T *u, T *v, int d){
  if(d<0) return ;
  int tot=0;
  for(int x:ad)if(~x>>d&1)tot+=1;
  if(tot+S(u->c[0])-S(v->c[0]) >=2) {
    vector<int> nad;
    for(int x:ad)if(~x>>d&1) nad.push_back(x);
    ad.swap(nad);
    qry(u->c[0],v->c[0],d-1);
  }else{
    append(u->c[0],v->c[0],d-1,0);
    //append(u->c[1],v->c[1],d-1,0);
    ans |= 1<<d;
    qry(u->c[1],v->c[1],d-1);
  }
}
void solve() {
  cin>>n;
  for(int i=1;i<=n;++i) cin>>a[i];
  cnt=pool;
  rt[0]=cnt++;
  rt[0]->c[0]=rt[0]->c[1]=rt[0];
  rt[0]->s=0;
  for(int i=1;i<=n;++i) upd(rt[i],rt[i-1],M-1,a[i]);
  int Q;
  cin>>Q;
  while(Q--) {
    int l,r;
    cin>>l>>r;
    ans=0;
    ad.clear();
    qry(rt[r],rt[l-1],M-1);
    cout<<ans<<"\n";
  }
}
int main(){
#ifdef flukehn
  freopen("A.in","r",stdin);
#endif
  ios::sync_with_stdio(0),cin.tie(0);
  int t;
  cin>>t;
  while(t--){
    solve();
  }
}