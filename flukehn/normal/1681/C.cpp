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
const int N=111;
int a[N],b[N];
using pa=pair<int,int>;
pa c[N],d[N];
int n;
void solve(){
  cin>>n;
  For(i,0,n) cin>>a[i];
  For(i,0,n) cin>>b[i];
  For(i,0,n) c[i]=pa(a[i],b[i]);
  For(i,0,n) d[i]=c[i];
  sort(d,d+n);
  For(i,1,n)
    if(d[i].second<d[i-1].second) {
      cout<<"-1\n";
      return;
    }
  vector<pa> ans;
  int flag;
  do{
    flag=0;
    for(int i=0;i<n-1;++i)
      if(c[i]>c[i+1]){
        swap(c[i],c[i+1]);
        ans.emplace_back(i,i+1);
        flag=1;
      }
  }while(flag);
  int k=ans.size();
  cout<<k<<"\n";
  for(auto [x,y]:ans)
    cout<<x+1<<" "<<y+1<<"\n";
}
int main(){
#ifdef flukehn
  freopen("C.in","r",stdin);
#endif
  ios::sync_with_stdio(0),cin.tie(0);
  int t;
  cin>>t;
  while(t--){
    solve();
  }
}