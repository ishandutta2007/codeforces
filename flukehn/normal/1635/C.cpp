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
int a[N],n;
void solve(){
#define GG {cout<<"-1\n";return;}
  cin>>n;
  for(int i=1;i<=n;++i)cin>>a[i];
  if(a[n-1]>a[n]) GG;
  if(a[n]<0) {
    for(int i=1;i<n;++i) if(a[i]>a[i+1])GG;
    cout<<"0\n";
  }else{
    cout<<n-2<<'\n';
    for(int i=1;i<=n-2;++i)
      cout<<i<<" "<<n-1<<" "<<n<<"\n";
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