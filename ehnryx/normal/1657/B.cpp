#include<bits/stdc++.h>
using namespace std;main(){
  int t;cin>>t;while(t--){
    int n,b,x,y;cin>>n>>b>>x>>y;
    long long s=0;
    int a=0;for(int i=0;i<n;i++){
      a+=x;if(a>b)a-=x+y;
      s+=a;
    }
    cout<<s<<'\n';
  }
}