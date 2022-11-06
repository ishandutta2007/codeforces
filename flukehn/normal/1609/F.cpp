#include<bits/stdc++.h>
using namespace std;
const int N=1e6+11;
using ll=long long;
const ll inf=~0uLL>>2;
ll a[N];
#define f __builtin_popcountll
int n;
ll ans;
void solve(int l,int r){
  if(l+1==r){
    ans+=1;
    return;
  }
  int m=(l+r)>>1;
  solve(l,m);
  solve(m,r);
  int p,q;
  ll mx,mn,ux,un;
  // mx,mn left
  mx=-inf,mn=inf;
  p=m,q=m;
  for(int i=m-1;i>=l;--i){
    mx=max(mx,a[i]);
    mn=min(mn,a[i]);
    if(f(mn)!=f(mx))continue;
    while(p<r&&a[p]<mx&&a[p]>=mn)++p;
    ans+=p-m;
  }
  mx=-inf,mn=inf;
  p=m-1;
  // mx,mn right
  for(int i=m;i<r;++i){
    mx=max(mx,a[i]);
    mn=min(mn,a[i]);
    if(f(mn)!=f(mx))continue;
    while(p>=l&&a[p]<=mx&&a[p]>mn)--p;
    ans+=m-1-p;
  }
  int g[64]={0};

  mx=-inf,mn=inf;
  p=m;
  q=m;
  //mx left, mn right
  
  un=inf;
  ux=a[m];
  for(int i=m-1;i>=l;--i){
    mx=max(mx,a[i]);
    mn=min(mn,a[i]);
    while(p<r&&a[p]<mx){
      un=min(un,a[p]);
      g[f(un)]++;
      ++p;
    }
    while(q<p&&ux>=mn){
      g[f(ux)]--;
      ++q;
      ux=min(ux,a[q]);
      
    }
    ans+=g[f(mx)];
  }

  memset(g,0,sizeof g);

  mx=-inf,mn=inf;
  
  
  p=m-1;
  q=m-1;
  //mn left , mx right
  //(a[i],i)
  un=inf;
  ux=a[m-1];
  for(int i=m;i<r;++i){
    mx=max(mx,a[i]);
    mn=min(mn,a[i]);
    while(p>=l&&a[p]<=mx){
      un=min(un,a[p]);
      g[f(un)]++;
      --p;
    }
    while(q>p&&ux>mn){
      g[f(ux)]--;
      --q;
      ux=min(ux,a[q]);
      
    }
    ans+=g[f(mx)];
  }
}
int main(){
#ifdef flukehn
  freopen("a.in","r",stdin);
#endif
  ios::sync_with_stdio(0),cin.tie(0);
  cin>>n;
  for(int i=1;i<=n;++i){
    cin>>a[i];
  }
  solve(1,n+1);
  /*for(int i=1;i<=n;++i){
    ll mn=a[i];
    ll mx=a[i];
    for(int j=i;j<=n;++j){
      mn=min(mn,a[j]);
      mx=max(mx,a[j]);
      if(f(mn)==f(mx))++ans;
    }
  }
  */
  cout<<ans<<"\n";
}