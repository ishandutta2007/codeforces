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
const int N=2e5+11;
const int M=N<<2;
int n,Q;
int f[N],L[N];
int fa(int x){
  return f[x]==x?x:f[x]=fa(f[x]);
}
#define m ((l+r)>>1)
#define ls (x<<1)
#define rs (x<<1|1)
int ql,qr,qx,qL,qR;
set<int> t[M];
void upd(int x,int l,int r){
  t[x].insert(ql);
  if(l+1==r) {
    //return;
  }else{
    if(qr<m) upd(ls,l,m);
    if(qr>=m) upd(rs,m,r);
  }
}
int ans;
void qry(int x,int l,int r){
  if(x>0)dbg(x,l,r,m,ql,qr);
  if(ql<=l&&r<=qr){
    ans|= t[x].lower_bound(qL) != t[x].upper_bound(qR);
  }else{
    if(ql<m) qry(ls,l,m);
    if(qr>m) qry(rs,m,r);
  }
}
#undef m
#undef ls
#undef rs
int main(){
#ifdef flukehn
  freopen("A.in","r",stdin);
#endif
  ios::sync_with_stdio(0),cin.tie(0);
  cin>>n>>Q;
  n+=1;
  for(int i=0;i<=n+2;++i) {
    f[i]=i;
    L[i]=i;
  }
  while(Q--){
    int t,x;
    cin>>t;
    if(t==0){
      cin>>ql>>qr>>x;
      if(x==0) {
        for(int i=fa(ql),j;i<=qr;i=j){
          j=fa(i+1);
          f[i]=j;
          L[j]=L[i];
        }
      }else{
        upd(1,1,n);
      }
    }else{
      cin>>x;
      //dbg(fa(x));
      if(fa(x)!=x) cout<<"NO\n";
      else{
        qr=fa(x+1);
        ql=x;
        
        qR=x;
        qL=L[x];
        dbg(x,ql,qr,qL,qR);
        ans=0;
        qry(1,1,n);
        if(ans) cout<<"YES\n";
        else cout<<"N/A\n";
      }
    }
  }
}