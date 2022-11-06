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
char s[N];
int n;
void solve(){
  cin>>n;
  cin>>s;
  int tot=0;
  For(i,0,n) tot+=s[i]-'0';
  if(tot==0||tot%2==1){
    cout<<"NO\n";
    return;
  }
  cout<<"YES\n";
  if(tot==n) {
    for(int i=2;i<=n;++i) cout<<"1 "<<i<<"\n";
    return;
  }
  vector<int> p;
  int i;
  for(i=0;i<n;++i) if(s[i]=='1') break;
  int x=-1;
  for(int j=0;j<n;++j) {
    int k=(i+j+1)%n;
    if(s[k]=='0') {
      cout<<k+1<<" "<<(k+1)%n+1<<"\n";
      if(x<0) x=k;
    } else {
      if(x>=0) {
        p.push_back(x);
        x=-1;
      } else {
        p.push_back(k);
      }
    }
  }
  for(int i=1;i<p.size();++i)cout<<p[0]+1<< " "<<p[i]+1<<"\n";
}
int main(){
#ifdef flukehn
  freopen("D.in","r",stdin);
#endif
  ios::sync_with_stdio(0),cin.tie(0);
  int t;
  cin>>t;
  while(t--){
    solve();
  }
}