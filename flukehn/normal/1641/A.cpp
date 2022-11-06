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
int a[N],n,x;
int v[N];
int solve(){
  cin>>n>>x;
  for(int i=1;i<=n;++i)cin>>a[i];
  sort(a+1,a+n+1);
  for(int i=1;i<=n;++i) v[i]=0;
  int ans=0;
  int p=2;
  for(int i=1;i<=n;++i){
    if(v[i])continue;
    while(p<=n&&(v[p]||a[p]<1LL*x*a[i])) p+=1;
    if(p<=n&&!v[p]&&a[p]==1LL*x*a[i]){
      v[p]=1;
    }else{
      ans+=1;
    }
  }
  return ans;
}
int main(){
#ifdef flukehn
  freopen("A.in","r",stdin);
#endif
  ios::sync_with_stdio(0),cin.tie(0);
  int t;
  cin>>t;
  while(t--){
    cout<<solve()<<"\n";
  }
}