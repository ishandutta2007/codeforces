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
const int N=100011;
int a[N],b[N];
int n,m;
void solve(){
  cin>>n;
  For(i,0,n) cin>>a[i];
  cin>>m;
  For(i,0,m) cin>>b[i];
  int x=*max_element(a,a+n);
  int y=*max_element(b,b+m);
  dbg(x,y);
  cout<<(x>=y?"Alice":"Bob")<<"\n";
  cout<<(x<=y?"Bob":"Alice")<<"\n";
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