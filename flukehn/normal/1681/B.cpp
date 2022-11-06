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
const int N=200011;
int a[N],n;
void solve(){
  cin>>n;
  For(i,0,n)cin>>a[i];
  int x=0,m;
  cin>>m;
  For(i,0,m){
    int y;
    cin>>y;
    x=(x+y)%n;
  }
  cout<<a[x]<<"\n";
}
int main(){
#ifdef flukehn
  freopen("B.in","r",stdin);
#endif
  ios::sync_with_stdio(0),cin.tie(0);
  int t;
  cin>>t;
  while(t--){
    solve();
  }
}