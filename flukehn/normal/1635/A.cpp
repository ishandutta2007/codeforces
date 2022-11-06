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

int main(){
#ifdef flukehn
	freopen("A.in","r",stdin);
#endif
  ios::sync_with_stdio(0),cin.tie(0);
  int t;
  cin>>t;
  while(t--){
    int n,x,y=0;
    cin>>n;
    For(i,0,n){
      cin>>x;
      y|=x;
    }
    cout<<y<<"\n";
  }
}