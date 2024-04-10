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
int solve(){
  string s;
  cin>>s;
  int r=0,g=0,b=0;
  for(auto c:s){
    if(c=='r')r+=1;
    else if(c=='b')b+=1;
    else if(c=='g')g+=1;
    else if(c=='R')r-=1;
    else if(c=='G')g-=1;
    else if(c=='B')b-=1;
    if(r<0||b<0||g<0) return 0;
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