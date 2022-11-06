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
const int N=1e5+11;
int a[N],n;
int solve(){
  cin>>n;
  for(int i=1;i<=n;++i)cin>>a[i];
  int b[2]={-1,-1};
  for(int i=1;i<=n;++i){
    int w=a[i]&1;
    if(b[w]>a[i])return 0;
    b[w]=a[i];
  }
  return 1;
}
int main(){
#ifdef flukehn
	freopen("A.in","r",stdin);
#endif
  ios::sync_with_stdio(0),cin.tie(0);
  int t;
  cin>>t;
  while(t--){
    cout<<(solve()?"YES":"NO")<<"\n";
  }
}