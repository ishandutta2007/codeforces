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
int a[N],n;
int solve() {
  cin>>n;
  For(i,0,n) cin>>a[i];
  sort(a,a+n);
  int mx=1;
  int now=1;
  For(i,1,n) {
    if(a[i]!=a[i-1]) now=1;
    else now+=1;
    mx=max(mx,now);
  }
  int ans=n-mx;
  int r=n-mx;
  while(r>0) {
    ans+=1;
    r-=mx;
    mx*=2;
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